require_relative 'Transformation'
require_relative 'SpaceStation'
require_relative 'PowerEfficientSpaceStationToUI'

module Deepspace
    class PowerEfficientSpaceStation < SpaceStation
        def initialize (station)
            @EFFICIENCYFACTOR = 1.10
            newCopy(station)
        end


        def fire
            super * @EFFICIENCYFACTOR
        end

        def protection
            super * @EFFICIENCYFACTOR
        end
        
        def setLoot(loot)
            super
            Transformation::NOTRANSFORM
        end

        
        def getUIversion
            PowerEfficientSpaceStationToUI.new(self)
        end

        def to_s
            return getUIversion.to_s
        end
    end
end