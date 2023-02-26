/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package main;

import java.util.ArrayList;
import modelo.Animal;
import modelo.Gallina;
import modelo.Vaca;
import modelo.ProductoAnimal;
import modelo.Huevo;
import modelo.Leche;
import vista.VistaPrincipal;
import controlador.Controlador;


/**
 *
 * @author Profe
 */
public class HayDay {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // a) Cree 1 lista de animales con 2 gallinas y 1 vaca 
        ArrayList<Animal> lista_animales = new ArrayList<>();
        lista_animales.add(new Gallina());
        lista_animales.add(new Gallina());
        lista_animales.add(new Vaca());
        
        // b) y 3 productos de animales disponibles (2 huevos; 1 leche)
        
        ArrayList<ProductoAnimal> productos = new ArrayList<>();
        productos.add(new Huevo());
        productos.add(new Huevo());
        productos.add(new Leche());
       
        // c) Inicia la vista y controlador
        
        VistaPrincipal vista = new VistaPrincipal();
        Controlador.instancia.start(vista, lista_animales, productos);
    }
    
}
