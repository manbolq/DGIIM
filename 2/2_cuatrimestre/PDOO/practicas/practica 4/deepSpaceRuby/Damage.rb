require_relative 'WeaponType'
require_relative 'DamageToUI'


module Deepspace
    class Damage
        attr_reader :nShields

        private_class_method def initialize(s)
            @nShields = s
        end
        
        def getUIversion
            raise "Método abstracto"
        end 

        def adjust(w, s)
            raise "Método abstracto"
        end

        def discardWeapon(w)
            raise "Método abstracto"
        end


        def discardShieldBooster
            if @nShields > 0
                @nShields -= 1
            end 
        end

        def hasNoEffect
            raise "Método abstracto"
        end

        def to_s
            raise "Método abstracto"
        end
    end
end