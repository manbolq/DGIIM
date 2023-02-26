require_relative 'Loot'
require_relative 'SuppliesPackage'
require_relative 'ShieldBooster'
require_relative 'Weapon'
require_relative 'Dice'

module Deepspace

    class TestP1

        # Solo compruebo la clase Dice porque el resto ya las he comprobado en sus respectivos archivos

        def initialize
            @dice = Dice.new
        end

        DICE = Dice.new

        def test

            trys = 100.to_f
            nHangars = 0
            nWeapons = 0
            nShields = 0
            playerStarts = 0
            nPlayers = 6            #Número de jugadores
            firstShot = 0
            moves = 0
            speed = 0.5
            for i in(1..trys)
                nHangars += DICE.initWithNHangars
                nWeapons += DICE.initWithNWeapons
                nShields += DICE.initWithNShields
                playerStarts += DICE.whoStarts(nPlayers)
                if DICE.firstShot==GameCharacter::SPACESTATION
                    firstShot += 1
                end
                if DICE.spaceStationMoves(speed)
                    moves += 1
                end

            end
            puts "Real: \n Hangars: #{1-(nHangars/trys)}, Weapons: #{1-(nWeapons/trys/3)}, Shields: #{1-(nShields/trys)}, Starts player: #{playerStarts/trys}, First shot: #{firstShot/trys}, Moves: #{moves/trys}"
        end

    end

end

#Main
@test=Deepspace::TestP1.new
@test.test