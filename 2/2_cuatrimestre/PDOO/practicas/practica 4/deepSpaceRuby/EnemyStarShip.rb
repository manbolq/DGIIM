require_relative 'ShotResult'
require_relative 'EnemyToUI'



module Deepspace
    class EnemyStarShip

        attr_reader :ammoPower, :name, :shieldPower, :damage, :loot

        def initialize(n, a, s, l ,d)
            @ammoPower = a
            @name = n
            @shieldPower = s
            @damage = d
            @loot = l
        end
        
        def self.newCopy(w)
            new(w.name, w.ammoPower, w.shieldPower, w.loot, w.damage)
        end
        
        def getUIversion
            return EnemyToUI.new(self)
        end

        def fire
            @ammoPower
        end

        def protection
            @shieldPower
        end

        def receiveShot(shot)
            if (shot > shieldPower)
                ShotResult::DONOTRESIST
            else
                ShotResult::RESIST
            end
        end

        def to_s
            return getUIversion.to_s
        end
    end
end