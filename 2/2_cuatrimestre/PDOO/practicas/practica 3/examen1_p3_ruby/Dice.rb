module Deepspace
    class Dice
        def initialize
            @NHANGARSPROB=0.25
            @NSHIELDSPROB=0.25
            @NWEAPONSPROB=0.33
            @FIRSTSHOTPROB=0.5
            @REDUCELOOTPROB=0.3
        end

        def initWithNHangars
            nrandom=rand
            if(nrandom<@NHANGARSPROB)
                return(0)
            else
                return(1)
            end
        end

        def initWithNWeapons
            nrandom=rand
            if(nrandom<(2*@NWEAPONSPROB))
                if(nrandom<@NWEAPONSPROB)
                    return 1
                else
                    return 2
                end
            else
                return 3
            end
        end

        def initWithNShields
            nrandom=rand
            if(nrandom<@NSHIELDSPROB)
                return 0
            else
                return 1
            end
        end

        def whoStarts(nPlayers)
            rand(nPlayers)
        end

        def firstShot
            nrandom=rand
            if(nrandom<@FIRSTSHOTPROB)
                return GameCharacter::SPACESTATION
            else
                return GameCharacter::ENEMYSTARSHIP
            end
        end
        
        
        # esta funcion devuelve true si hay que reducir el botin, y false si no hay que reducirlo
        def reduceLoot
        	rand < @REDUCELOOTPROB
        end
        
        
        #devuelve 1, 2, 3 o 4, con la misma probabilidad
        def reduceLootItem
        	rand(4) + 1
        end



        def spaceStationMoves(speed)
            nrandom=rand
            if(nrandom<speed)
                return true
            else
                return false
            end
        end

        def to_s
            mensaje = "Dice"
            return mensaje
        end
    end
end
