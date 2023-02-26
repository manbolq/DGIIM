package examen;
import otropaquete.Padre;
import java.util.ArrayList;


class Hija extends Padre{
    
    void publico(){ // error. no puedes subir la restriccion en una clase hija

    }
    
    public void privado(){
        super.privado(); //error. no puedes acceder a un metodo privado fuera de la clase
    }

    private void procesa(){
        System.out.println("Procesando en Hija");
    }

    void test1(){
        protegido(); 
        tarea();
    }

    void test2(Padre p){ 
        p.protegido(); //error. no se puede usar el protegido de una instancia de otra clase que no es la misma que Hija (p)
        p.tarea();
    }

    void test3(Nieta n){
        n.metodoNieta();
        n.protegido(); // bien
    }
    
    void test4(Hija h){
        h.protegido(); // bien
        h.procesa(); // "Procesando en Hija"
    }
}

class Nieta extends Hija implements Examen{
    
    public void procesa(){ //bien
        System.out.println("Procesando en Nieta");
    }

    protected void metodoNieta(){
        
    }
    
    void test5(){
        tarea(); 
        privado(); 
    }
}


interface Examen{
    void test5();
}


public class Pruebas {

    public static void main(String[] args) {
        
        Hija p = new Padre(); 
        Hija h = new Hija();
        Nieta n = new Nieta();

        ((Hija) n).tarea(); //error, dentro de tarea() se ejecuta el procesa() del padre que es de paquete y estamos en otro paquete

        ArrayList<Examen> examenes = new ArrayList<>();

        examenes.add(h); // error. hija no realiza Examen
        examenes.add(n);

        h = (Hija)(Padre)(Object) n; 
        ArrayList<Hija> hijas = (ArrayList<Hija>)(Object) n; // error. Object y ArrayList<Hija> no son tipos compatibles
        
        ArrayList<Hija> lista = new ArrayList<>();

        Hija hija = new Hija();
        Nieta nieta = new Nieta();
        
        lista.add(hija);
        lista.add(nieta); 

        ((Padre) lista.get(1)).tarea();
        ((Padre) lista.get(1)).metodo(); //error distinto paquete

    }   
}
