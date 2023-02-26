import java.util.ArrayList;

class A{
	private int x;
	private int y;
	
	public A(int a, int b){
		x = a;
		y = b;
	}
	
	public A(A a){
		x = a.x;
		y = a.y;
	}
	
	@Override
	public String toString(){
		return "(" + Integer.toString(x) + ", " + Integer.toString(y) + ")";
	}
}

class B extends A{
	private int z;
	
	public B(int a, int b, int c){
		super(a, b);
		z = c;
	}
	
	public B (B b){
		super(b);
		z = b.z;
	}
	
	@Override
	public String toString(){
		return super.toString() + "(" + Integer.toString(z) + ")";
	}
}

class Constructor_copia{
	public static void main(String[] args){
		ArrayList<B> array1 = new ArrayList<A>();
	}	
}
