require_relative 'WeaponType'
require_relative 'WeaponToUI'

module Deepspace

    class Weapon

        def initialize (n, t, u)
            @name = n
            @type = t
            @uses = u        
        end

        def self.newCopy(w)
            new(w.name, w.type, w.uses)
        end

        def getUIversion
            return WeaponToUI.new(self)
        end

        def type
            @type
        end

        def name
            @name
        end
        
        def uses
            @uses
        end
        
        def power
            @type.power
        end

        def useIt
            if (@uses > 0)
                @uses -= 1
                power
            else
                1.0
            end
        end

        def to_s
            return getUIversion.to_s
        end

    end

end