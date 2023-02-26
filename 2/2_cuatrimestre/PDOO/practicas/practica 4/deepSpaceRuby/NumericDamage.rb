require_relative 'NumericDamageToUI'
require_relative 'Damage'
require_relative 'WeaponType'

module Deepspace
    class NumericDamage < Damage

        attr_reader :nWeapons

        public_class_method def initialize(w,s)
            super(s)
            @nWeapons = w
        end
        
        def copy()
            return new(@nWeapons,@nShields)
        end

        def getUIversion
            return NumericDamageToUI.new(self)
        end 

        def adjust(w, s)
            
            ns_aux = 0

            if @nShields > 0
                if @nShields > s.size
                    ns_aux = s.size
                else
                    ns_aux = @nShields
                end
            end
        
            nw_aux = 0
            if @nWeapons >= 0
                if @nWeapons > w.size
                    nw_aux = w.size
                else
                    nw_aux = @nWeapons
                end
            end
                
            return NumericDamage.new(nw_aux,ns_aux)
            
        end

        def discardWeapon(w)

            if (@nWeapons > 0)
                @nWeapons -= 1
            end
        end

        def hasNoEffect
            return ((@nShields == 0) && (@nWeapons == 0))
        end

        def to_s
            return getUIversion.to_s
        end

    end
end