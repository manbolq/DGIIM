require_relative 'LootToUI'

module Deepspace

    class Loot
        def initialize (nSupplies, nWeapons, nShields, nHangars, nMedals, efficient=false, spaceCity=false)
            @nSupplies = nSupplies
            @nWeapons = nWeapons
            @nShields = nShields
            @nHangars = nHangars
            @nMedals = nMedals
            @efficient = efficient
            @spaceCity = spaceCity
        end

        def getUIversion
           return LootToUI.new(self) 
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

        def efficient
            @efficient
        end

        def spaceCity
            @spaceCity
        end

        def to_s
            return getUIversion.to_s
        end 
    end

end