require_relative 'Damage'
require_relative 'Weapon'
require_relative 'ShieldBooster'
require_relative 'Hangar'
require_relative 'SpaceStationToUI'
require_relative 'ShotResult'
require_relative 'CardDealer'

module Deepspace
    class SpaceStation

        attr_reader :ammoPower, :fuelUnits, :weapons, :hangar, :shieldPower, :name, :nMedals, :pendingDamage, :shieldBoosters

        def initialize(n, supplies)
            @MAXFUEL = 100
            @SHIELDLOSSPERUNITSHOT = 0.1
            @name = n
            @ammoPower = supplies.ammoPower
            @fuelUnits = supplies.fuelUnits
            @shieldPower = supplies.shieldPower
            @weapons = Array.new
            @hangar = nil
            @nMedals = 0
            @pendingDamage = nil
            @shieldBoosters = Array.new
            
        end


        def cleanUpMountedItems
            for i in 0..(@weapons.length - 1)
                if (@weapons.at(i).uses == 0)
                    @weapons.delete_at(i)
                end
            end

            for i in 0..(@shieldBoosters.length-1)
                if (@shieldBoosters.at(i).uses == 0)
                    @shieldBoosters.delete_at(i)
                end
            end
        end

        def discardHangar
            @hangar = nil
        end

        def discardShieldBooster(i)
            size = @shieldBoosters.length

            if (i >= 0 && i < size)
                w = @shieldBoosters.remove(i)
                if(@pendingDamage != nil)
                    @pendingDamage.discardWeapon(w)
                    cleanPendingDamage
                end
            end
        end

        def discardShieldBoosterInHangar(i)
            if (@hangar != nil)
                @hangar.removeShieldBooster(i)
            end
        end

        def discardWeapon(i)
            size = @weapons.length

            if (i >= 0 && i < size)
                w = @weapons.delete_at(i)
                if(@pendingDamage != nil)
                    @pendingDamage.discardWeapon(w)
                    cleanPendingDamage
                end
            end
        end


        def discardWeaponInHangar(i)
            if (@hangar != nil)
                @hangar.removeWeapon(i)
            end
        end


        def fire
            size = @weapons.length
            factor = 1

            for i in 0..(size-1)
                factor *= @weapons[i].useIt
            end
            
            return @ammoPower*factor
        end

        def mountShieldBooster(i)
            if (@hangar != nil)
                aux = @hangar.removeShieldBooster(i)
                if (aux != nil)
                    shieldBoosters << aux
                end
            end
        end


        def mountWeapon(i)
            if (@hangar != nil)
                aux = @hangar.removeWeapon(i)
                if (aux != nil)
                    weapons << aux
                end
            end
        end


        def move
            @fuelUnits -= getSpeed
            if (@fuelUnits < 0)
                @fuelUnits = 0
            end
            
        end

        def protection
            size = @shieldBoosters.length
            factor = 1

            for i in 0..(size - 1)
                factor *= @shieldBoosters[i].useIt
            end

            return @shieldPower*factor
        end

        def receiveHangar(h)
            if (@hangar == nil)
                @hangar = h
            end

        end

        def receiveShieldBooster(s)

            if (@hangar != nil)
                @hangar.addShieldBooster(s)
            else
                false
            end
        end

        def receiveShot(shot)
            myProtection = protection

            if (myProtection >= shot)
                @shieldPower -= @SHIELDLOSSPERUNITSHOT*shot
                if (@shieldPower < 0)
                    @shieldPower = 0
                end
                return ShotResult::RESIST
            else
                @shieldPower = 0
                return ShotResult::DONOTRESIST
            end
        end


        def receiveSupplies(s)
            @ammoPower += s.ammoPower
            @shieldPower += s.shieldPower
            @fuelUnits += s.fuelUnits
        end


        def receiveWeapon(w)
            if (@hangar != nil)
                @hangar.addWeapon(w)
            else
                false
            end

        end

        def setLoot(loot)
            dealer = CardDealer.instance
            h = loot.nHangars
      
            if h > 0
              hangar = dealer.nextHangar
              receiveHangar(hangar)
            end
      
            elements = loot.nSupplies

            elements.times do
              sup = dealer.nextSuppliesPackage
              receiveSupplies(sup)
            end
      
            elements = loot.nWeapons

            elements.times do
              weap = dealer.nextWeapon
              receiveWeapon(weap)
            end
      
            elements = loot.nShields

            elements.times do
              sh = dealer.nextShieldBooster
              receiveShieldBooster(sh)
            end
      
            @nMedals += loot.nMedals
        end

        def getSpeed
            @fuelUnits/@MAXFUEL
        end

        def setPendingDamage(d)
            @pendingDamage = d.adjust(weapons, shieldBoosters)

        end


        def validState
            (@pendingDamage == nil) || (@pendingDamage.hasNoEffect)
        end


        def getUIversion
            return SpaceStationToUI.new(self)
        end

        def to_s 
            return getUIversion().to_s
        end

        
        private

        def cleanPendingDamage
            if (@pendingDamage.hasNoEffect)
                @pendingDamage = nil
            end


        end


        def assignFuelValue(f)
            if (f <= @MAXFUEL)
                @fuelUnits = f
            end

        end


    end
end

