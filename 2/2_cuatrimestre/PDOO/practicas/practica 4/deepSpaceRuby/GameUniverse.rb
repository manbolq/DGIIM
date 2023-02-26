require_relative './Dice.rb'
require_relative './GameStateController.rb'
require_relative './GameState'
require_relative 'GameUniverseToUI'
require_relative 'SpaceStation'
require_relative 'EnemyStarShip'
require_relative 'CardDealer'
require_relative 'Loot'
require_relative 'CombatResult'
require_relative 'SpaceCity'
require_relative 'BetaPowerEfficientSpaceStation'
require_relative 'PowerEfficientSpaceStation'
require_relative 'Transformation'

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

            @haveSpaceCity = false
        end

        
        def combatGo (station, enemy) 
            state = @gameState.state

            if (state == GameState::BEFORECOMBAT || state == GameState::INIT)
                ch = @dice.firstShot

                if (ch == GameCharacter::ENEMYSTARSHIP)
                    fire = enemy.fire
                    result = station.receiveShot(fire)

                    if (result == ShotResult::RESIST)
                        fire = station.fire
                        result = enemy.receiveShot(fire)
                        enemyWins = (result == ShotResult::RESIST)
                    else
                        enemyWins = true
                    end

                else
                    fire = station.fire
                    result = enemy.receiveShot(fire)
                    enemyWins = (result == ShotResult::RESIST)
                end

                if (enemyWins)
                    s = station.getSpeed
                    moves = @dice.spaceStationMoves(s)

                    if (!moves)
                        damage = enemy.damage
                        station.setPendingDamage(damage)
                        combatResult = CombatResult::ENEMYWINS
                    else
                        station.move
                        combatResult = CombatResult::STATIONESCAPES
                    end 

                else
                    aLoot = enemy.loot
                    t = station.setLoot(aLoot)

                    if (t == Transformation::GETEFFICIENT)
                        makeStationEfficient
                        combatResult = CombatResult::STATIONWINSANDCONVERTS
                    elsif (t == Transformation::SPACECITY)
                        createSpaceCity
                        combatResult = CombatResult::STATIONWINSANDCONVERTS
                    else
                        combatResult = CombatResult::STATIONWINS
                    end

                end

                @gameState.next(@turns, @spaceStations.length)

                return combatResult

            else
                return CombatResult::NOCOMBAT
            end
        end


        def combat
            state = @gameState.state

            if (state == GameState::BEFORECOMBAT || state == GameState::INIT)
                combatGo(@currentStation, @currentEnemy)
            else
                return CombatResult::NOCOMBAT
            end
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
            state = @gameState.state
            if (state == GameState::CANNOTPLAY)
                @spaceStations = Array.new
                dealer = CardDealer.instance

                for i in (0..(names.length - 1)) do 
                    supplies = dealer.nextSuppliesPackage
                    station = SpaceStation.new(names[i], supplies)
                    @spaceStations << station

                    nh = @dice.initWithNHangars
                    nw = @dice.initWithNWeapons
                    ns = @dice.initWithNShields
                    
                    lo = Loot.new(0, nw, ns, nh, 0)

                    station.setLoot(lo)
                end

                @currentStationIndex = @dice.whoStarts(names.length)
                @currentStation = @spaceStations[@currentStationIndex]
                @currentEnemy = dealer.nextEnemy

                @gameState.next(@turns, @spaceStations.length)
            end
        end


        def haveAWinner
            @currentStation.nMedals >= @WIN
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
            state = @gameState.state

            if (state == GameState::AFTERCOMBAT)
                stationState = @currentStation.validState
                if (stationState)
                    @currentStationIndex = (@currentStationIndex+1) % (@spaceStations.length)
                    @turns += 1

                    @currentStation = @spaceStations[@currentStationIndex]
                    @currentStation.cleanUpMountedItems

                    dealer = CardDealer.instance

                    @currentEnemy = dealer.nextEnemy

                    @gameState.next(@turns, @spaceStations.length)

                    return true
                else
                    return false
                end
            else
                return false
            end
        end


        def makeStationEfficient
            if (@dice.extraEfficiency)
                @currentStation = BetaPowerEfficientSpaceStation.new(@currentStation)
            else
                @currentStation = PowerEfficientSpaceStation.new(@currentStation)
            end

            @spaceStations[@currentStationIndex]  = @currentStation
        end

        def createSpaceCity
            if (!@haveSpaceCity)
                rest = Array.new

                for s in @spaceStations
                    if (s != @currentStation)
                        rest << s
                    end
                end

                @currentStation = SpaceCity.new(@currentStation, rest)
                @spaceStations[@currentStationIndex]  = @currentStation
                @haveSpaceCity = true
            end
        end



        def getUIversion
            return GameUniverseToUI.new(@currentStation, @currentEnemy)
        end

        def to_s
            return getUIversion.to_s
        end
    end

end 