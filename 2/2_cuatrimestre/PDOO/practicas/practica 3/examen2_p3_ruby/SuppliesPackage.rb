module Deepspace

    class SuppliesPackage
        
        def initialize (ammoPower, fuelUnits, shieldPower)
            @ammoPower = ammoPower
            @fuelUnits = fuelUnits
            @shieldPower = shieldPower
        end

        def self.newCopy (s)
            new(s.ammoPower, s.fuelUnits, s.shieldPower)
        end


        def ammoPower
            @ammoPower
        end

        def fuelUnits
            @fuelUnits
        end
        
        def shieldPower
            @shieldPower
        end
        
        def to_s
            "AmmoPower: #{@ammoPower}, FuelUnits: #{@fuelUnits}, ShieldPower: #{@shieldPower}"
        end
    end

end