require_relative 'ShieldBooster'
require_relative 'Weapon'
require_relative 'HangarToUI'


module Deepspace
    class Hangar

        attr_reader :maxElements, :weapons, :shieldBoosters
        
        def initialize(capacity)
            @maxElements = capacity
            @weapons = Array.new
            @shieldBoosters = Array.new
        end

        def self.newCopy(h)
            new(h.maxElements)
            if (h.weapons != nil)
                @weapons = h.weapons
            else
                @weapons = Array.new
            end

            if (h.shieldBoosters != nil)
                @shieldBoosters = h.shieldBoosters
            else
                @shieldBoosters = Array.new
            end
        end

        def getUIversion
            return HangarToUI.new(self)
        end

        def addWeapon(w)
            if spaceAvailable
                @weapons << w
                return true
            else 
                false
            end
        end

        def addShieldBooster(s)
            if spaceAvailable
                @shieldBoosters << s
                return true
            else 
                false
            end
        end

        def removeShieldBooster(s)
            if (s < @shieldBoosters.size && s >= 0)
                aux = ShieldBooster.newCopy(@shieldBoosters[s])
                @shieldBoosters.delete_at(s)
                aux
            else
                nil
            end

        end

        def removeWeapon(w)
            if (w < @weapons.size && w >= 0)
                aux = Weapon.newCopy(@weapons[w])
                @weapons.delete_at(w)
                aux
            else
                nil
            end
        end

        def to_s
            return getUIversion.to_s
        end
        
        def spaceAvailable
            @weapons.length + @shieldBoosters.length < @maxElements
        end

    end
end 