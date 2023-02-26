module Deepspace

    class ShieldBooster

        def initialize (name, boost, uses)
            @name = name
            @boost = boost
            @uses = uses
        end

        def self.newCopy (s)
            new(s.name, s.boost, s.uses)
        end

        def boost
            @boost
        end

        def uses
            @uses
        end

        def useIt
            if (@uses > 0)
                @uses -= 1
                @boost
            else
                1.0
            end
        end

    end

end