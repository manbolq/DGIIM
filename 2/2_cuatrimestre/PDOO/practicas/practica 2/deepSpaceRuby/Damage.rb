require_relative 'WeaponType'
require_relative 'DamageToUI'


module Deepspace
    class Damage
        attr_reader :nShields, :nWeapons, :weapons

        def initialize(wl, w, s)
            @nShields = s
            @nWeapons = w
            if (wl != nil)
                @weapons = wl
            else
                @weapons = Array.new
            end
        end
        
        def self.newNumericWeapons(w, s)
            new(Array.new, w, s)
        end

        def self.newSpecificWeapons(wl,s)
            new(wl, -1, s)
        end

        def self.newCopy(w)
            new(w.weapons, w.nWeapons, w.nShields)
        end

        def getUIversion
            DamageToUI.new(self)
        end 

        def adjust(w, s)
            nw_aux = -1
            ns_aux = 0

            if @nShields > 0
                if @nShields > s.size
                    ns_aux = s.size
                else
                    ns_aux = @nShields
                end
            end
        
        
            if @nWeapons >= 0
                if @nWeapons > w.size
                    nw_aux = w.size
                else
                    nw_aux = @nWeapons
                end
                
                return Damage.newNumericWeapons(nw_aux, ns_aux)##
            else
                aux = Array.new(w)

                w_aux = Array.new

                for i in(0..(@weapons.size - 1)) do #recorre el array de armas del damage
                    if (arrayContainsType(aux, @weapons.at(i)) != nil) #si dentro de las armas que tengo en posesion esta un arma del tipo i, 
                        w_aux << aux.at(arrayContainsType(aux, @weapons.at(i))).type
                        aux.delete_at(arrayContainsType(aux, @weapons.at(i))) 
                    end
                end
                return Damage.newSpecificWeapons(w_aux, ns_aux)##
            end

        end

        def discardWeapon(w)

            if (@nWeapons > 0)
                @nWeapons -= 1
            else
                if (@weapons != nil)
                    for t in @weapons do
                        if t == w.type
                            @weapons.delete(t)
                        end
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
            return (@nShields == 0) && (@nWeapons == 0) && (@weapons.size == 0)
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