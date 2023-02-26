require_relative 'Damage'
require_relative 'WeaponType'
require_relative 'Weapon'
require_relative 'ShieldBooster'


module Deepspace

	class Examen
		def self.principal
			# creacion elementos para el damage
			wt1 = WeaponType::PLASMA
			wt2 = WeaponType::LASER
			wt3 = WeaponType::MISSILE
			
			weapons = Array.new			
			weapons << wt1
			weapons << wt2
			weapons << wt1
			weapons << wt3
			
			nShields = 4
			#creacion de damage
			damage = Damage.newSpecificWeapons(weapons, nShields)
			
			puts "Damage:"
			puts (damage)
			
			
			#creacion de elementos de la estacion
			w = Array.new
			w1 = Weapon.new("Weapon 1", WeaponType::MISSILE, 3)
			w2 = Weapon.new("Weapon 2", WeaponType::LASER, 2)
			w << w1
			w << w2
			
			s = Array.new
			s1 = ShieldBooster.new("Shield 1", 3, 2)
			s << s1
			
			puts 
			puts "Damage ajustado:"
			puts (damage.adjust(w, s))
			
			
		end

	end
	
	Examen.principal
end



