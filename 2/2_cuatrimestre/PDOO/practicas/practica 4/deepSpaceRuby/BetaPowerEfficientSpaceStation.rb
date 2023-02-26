require_relative 'Dice'
require_relative 'BetaPowerEfficientSpaceStationToUI'
require_relative 'PowerEfficientSpaceStation'

module Deepspace
    class BetaPowerEfficientSpaceStation < PowerEfficientSpaceStation
        def initialize (station)
            @EXTRAEFFICIENCY = 1.2
            @dice = Dice.new
            super
        end


        def fire
            if (@dice.extraEfficiency)
                super * @EXTRAEFFICIENCY
            else
                super
            end
        end

        
        def getUIversion
            BetaPowerEfficientSpaceStationToUI.new(self)
        end

        def to_s
            return getUIversion.to_s
        end
    end
end