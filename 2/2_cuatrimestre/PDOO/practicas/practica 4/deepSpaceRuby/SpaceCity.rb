require_relative 'SpaceStation'
require_relative 'SpaceCityToUI'

module Deepspace
    class SpaceCity < SpaceStation

        attr_reader :ammoPower, :fuelUnits, :weapons, :hangar, :shieldPower, :name, :nMedals, :pendingDamage, :shieldBoosters

        def initialize(base, rest)
            @collaborators = Array.new(rest)
            @base = base
            newCopy(base)
        end

        def fire
            size = @collaborators.length
            factor = @base.fire

            for i in 0..(size-1)
                factor *= @collaborators[i].fire
            end
            
            return factor
        end

        def protection 
            factor = super

            @collaborators.each do |x|
                factor *= x.protection
            end

            return factor
        end

        def setLoot(loot)
            super(loot)
            return Transformation::NOTRANSFORM
        end

        def getUIversion
            return SpaceCityToUI.new(self)
        end

        def collaborators
           @collaborators 
        end

    end
end

