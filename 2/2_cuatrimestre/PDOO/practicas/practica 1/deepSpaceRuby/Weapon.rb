require_relative 'WeaponType'

module Deepspace

    class Weapon

        def initialize (name, type, uses)
            @name = name
            @type = type
            @uses = uses        
        end

        def self.newCopy(w)
            new(w.name, w.type, w.uses)
        end


        def type
            @type
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

    end

end