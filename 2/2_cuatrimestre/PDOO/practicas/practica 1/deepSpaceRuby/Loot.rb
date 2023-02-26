module Deepspace

    class Loot
        def initialize (nSupplies, nWeapons, nShields, nHangars, nMedals)
            @nSupplies = nSupplies
            @nWeapons = nWeapons
            @nShields = nShields
            @nHangars = nHangars
            @nMedals = nMedals
        end

        def nSupplies
            @nSupplies
        end

        def nWeapons
            @nWeapons
        end

        def nShields
            @nShields
        end

        def nHangars
            @nHangars
        end

        def nMedals
            @nMedals
        end

    end

end