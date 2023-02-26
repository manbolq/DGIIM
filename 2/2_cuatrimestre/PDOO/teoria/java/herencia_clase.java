class Padre{
	public static final int DECLASE = 1;
	public static int getDECLASE() { return DECLASE;}
}

class Hija extends Padre {
	public static final int DECLASE = 2;
}

class Nieta extends Hija{
	@Override
	public static int getDECLASE(){
		// super.getDECLASE(); // error, NO se puede usar super en un ambito de clase
		return DECLASE;
	}
}


class Herencia_clase{
	public static void main(String[] args){
		Padre p = new Padre();
		System.out.println(p.getDECLASE());
		
		p = new Nieta();
		System.out.println(p.getDECLASE());
		
		Nieta n = new Nieta();
		System.out.println(n.getDECLASE());	
	}

}
