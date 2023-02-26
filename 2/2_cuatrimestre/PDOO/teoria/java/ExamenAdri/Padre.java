package otropaquete;

/**
 *
 * @author adria
 */

public class Padre {
    
    private void privado(){
        
    }

    protected void protegido(){
        
    }

    public void publico(){

    }
    
    void metodo(){
        
    }
    
    void procesa(){
        System.out.println("Procesando en Padre");
    }
    
    public void tarea(){
        procesa();
        System.out.println("Terminando tarea en Padre");
    }
    
}
