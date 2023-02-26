require_relative 'SuppliesPackage'
require_relative 'SpaceStation'
require_relative 'Hangar'
require_relative 'Weapon'
require_relative 'WeaponType'
require_relative 'ShieldBooster'

module Test
	class Examen3
		def principal
		
			#2.a
			name = "manbolq"
			supplies = Deepspace::SuppliesPackage.new(2, 5, 3)
			
			station = Deepspace::SpaceStation.new(name, supplies)
			
			puts "(2.a)"
			puts station
			puts
			
			
			#2.b
			hangar = Deepspace::Hangar.new(3)
			station.receiveHangar(hangar)
			
			puts "(2.b)"
			puts station
			puts
			
			
			#2.c
			weapon = Deepspace::Weapon.new("Espada", Deepspace::WeaponType::LASER, 1)
			station.receiveWeapon(weapon)
			
			puts "(2.c)"
			puts station
			puts
			
			
			#2.d
			for i in (0..2) do
				station.receiveWeapon(weapon)
			end
			
			puts "(2.d)"
			puts station
			puts
			
			
			#2.e
			for i in (0..1) do
				station.mountWeapon(0)
			end
			
			puts "(2.e)"
			puts station
			puts
			
			
			#2.f
			s = Deepspace::ShieldBooster.new("Escudo", 1.5, 2)
			station.receiveShieldBooster(s)
			
			puts "(2.f)"
			puts station
			puts
			
			
			#2.g
			station.receiveShieldBooster(s)
			station.receiveShieldBooster(s)
			
			puts "(2.g)"
			puts station
			puts
			
			
			#2.h
			station.mountShieldBooster(1)
			
			puts "(2.h)"
			puts station
			puts
			
			
			
		end
	end
	
	examen = Examen3.new
	examen.principal
end
