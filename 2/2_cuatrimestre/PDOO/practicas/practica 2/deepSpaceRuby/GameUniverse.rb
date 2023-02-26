require_relative './Dice.rb'
require_relative './GameStateController.rb'
require_relative './GameState'
require_relative 'GameUniverseToUI'
require_relative 'SpaceStation'
require_relative 'EnemyStarShip'

module Deepspace
    class GameUniverse

        def initialize()
            @WIN = 10 
            @gameState = GameStateController.new
            @dice = Dice.new
            @turns = 0      
            

            # no se si hay que inicializarlo asi
            @currentStationIndex = 0
            @currentStation = nil
            @spaceStations = nil
            @currentEnemy = nil
        end

        
        def combatGo (station,enemy) 

        end

        def combat

        end

        def discardHangar
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].discardHangar()
            end
        end

        def discardShieldBooster(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].discardShieldBooster(i)
            end
        end
        
        def discardShieldBoosterInHangar(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].discardShieldBoosterInHangar(i)
            end
        end


        def discardWeapon(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].discardWeapon(i)
            end
        end


        def discardWeaponInHangar(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].discardWeaponInHangar(i)
            end
        end


        def getState
            return @gameState.state
        end



        def init(names)

        end


        def haveAWinner
            @currentStation.getNMedals >= @WIN
        end

        def mountShieldBooster(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].mountShieldBooster(i)
            end

        end

        def mountWeapon(i)
            if (@gameState.state == GameState::INIT || @gameState.state == GameState::AFTERCOMBAT)
                @spaceStations[@currentStationIndex].mountWeapon(i)
            end
        end

        def nextTurn

        end

        def getUIversion
            return GameUniverseToUI.new(@currentStation, @currentEnemy)
        end

        def to_s
            return getUIversion.to_s
        end
    end 
end 