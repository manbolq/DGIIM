class Persona{
	private String nombre;

	public Persona(String nombre){
		this.nombre = nombre;
	}

	public String andar(){
		return ("Ando como una persona");
	}
	
	public String hablar(){
		return ("Hablo como una persona");
	}
}

class Profesor extends Persona{

	public Profesor(String nombre){
		super(nombre);
	}

	@Override
	public String hablar(){
		return ("Hablo como un profesor");
	}
	
	public String impartirClase(){
		return ("Impartiendo clase");
	}
}

class Alumno extends Persona{

	public Alumno(String nombre){
		super(nombre);
	}
	// Clase hermana de Profesor
	// Aliumno y Profesor son descendientes directos de Persona
}

class Prueba{
	static public void main(String[] args){
	
	/*
		Persona p = new Persona();
		Persona p2 = new Profesor();
		
		System.out.println(p.hablar());
		System.out.println(p2.hablar());
		System.out.println(((Profesor)p2).impartirClase()); // downCast para que acceder
															// al metodo impartirClase()
															
		//System.out.println(p2.impartirClase()); // error, el cast no dura para siempre
		Profesor prof = (Profesor) p2;
		prof.impartirClase();
		
	*/
	
	
	
	//ERRORES EN TIEMPO DE EJECUCION
	/*
		Persona p = new Persona();
		Profesor prof = (Profesor) p; // error ejecucion
		
		prof = ((Profesor) new Persona()); // error en ejecucion
		
		((Profesor) p).impartirClase(); //error ejecucion
		
		((Profesor) ((Object) new Profesor())).impartirClase(); // funciona
		}
	*/
	
	
	
	// EJEMPLOS DE CAST ENTRE CLASES HERMANAS
	/*
		//Alumno a1 = new Profesor(); // Error de compilacion, tipos incompatibles
		
		//Alumno a2 = (Alumno) new Profesor(); //ni upCast, ni downCast->error compilacion
		
		Alumno a3 = ((Alumno) ((Object) new Profesor())); //upCast a Object, y downCast 
														  // a Alumno --> no hay error
														  // en compilacion, pero error 
														  // en ejecucion, porque son
														  // tipos incompatibles
	*/
	
	Profesor profe = new Profesor();
	ArrayList<Persona> personas = (ArrayList<Profesor>)(Object) profe;
	
	
	}
}


