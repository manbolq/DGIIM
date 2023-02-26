class Padre
	@atributo_clase1 = 1
	@atributo_clase2 = 2
	@@atributo_clase3 = 5
	
	def self.salida
		puts @atributo_clase1 + 1
		puts @atributo_clase2 + 1 unless @atributo_clase2.nil?
		puts @@atributo_clase3 +1
		puts "FIN"
	end
	
	def self.salida2
		salida
	end
end

Padre.salida # 2, 3, 6

class Hija < Padre
	@atributo_clase1 = 3
	@@atributo_clase3 = 7
	
	def self.salida2
		super
		puts @atributo_clase1 + 1
	end
end

Padre.salida #2, 3, 8
Hija.salida #4, 8
Padre.salida2 #2, 3, 8
Hija.salida2 #4, 8, 4


