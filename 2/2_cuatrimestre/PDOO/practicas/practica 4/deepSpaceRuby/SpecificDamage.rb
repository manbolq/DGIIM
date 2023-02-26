require_relative 'Damage'
require_relative 'SpecificDamageToUI'


module Deepspace
    class SpecificDamage < Damage
        
        attr_reader :weapons

        public_class_method def initialize(w,s)
            super(s)
            @weapons = w
        end
        
        def copy()
            return new(@weapons,@nShields)
        end

        def getUIversion
            return SpecificDamageToUI.new(self)
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
        

            aux = Array.new(w)

            w_aux = Array.new

            for i in(0..(@weapons.size - 1)) do #recorre el array de armas del damage
                if (arrayContainsType(aux, @weapons.at(i)) != nil) #si dentro de las armas que tengo en posesion esta un arma del tipo i, 
                    w_aux << aux.at(arrayContainsType(aux, @weapons.at(i))).type
                    aux.delete_at(arrayContainsType(aux, @weapons.at(i))) 
                end
            end
            return SpecificDamage.new(w_aux, ns_aux)
            

        end

        def discardWeapon(w)
            if (@weapons != nil)
                for t in @weapons do
                    if t == w.type
                        @weapons.delete(t)
                    end
                end
            end
        end


        def discardShieldBooster
            if @nShields > 0
                @nShields -= 1
            end 
        end

        def hasNoEffect
            return ( (@nShields == 0) && ((@weapons.length == 0 || @weapons == nil)))
        end

        def to_s
            return getUIversion.to_s
        end


        private

        def arrayContainsType(w,t)
            return w.index{ |wea| wea.type == t}
        end

    end
end