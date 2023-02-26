require_relative 'Damage'
require_relative 'Weapon'
require_relative 'ShieldBooster'
require_relative 'Hangar'
require_relative 'SpaceStationToUI'
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
            for i in 0..(@weapons.length-1)
                if (@weapons[i].uses == 0)
                    @weapons.delete_at(i)
                end
            end

            for i in 0..(@shieldBoosters.length-1)
                if (@shieldBoosters[i].uses == 0)
                    @shieldBoosters.delete_at(i)
                end
            end
        end

        def discardHangar
            @hangar = nil
        end

        def discardShieldBooster(i)

        end

        def discardShieldBoosterInHangar(i)
            if (@hangar != nil)
                @hangar.removeShieldBooster(i)
            end
        end

        def discardWeapon(i)

        end


        def discardWeaponInHangar(i)
            if (@hangar != nil)
                @hangar.removeWeapon(i)
            end
        end


        def fire
        
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

