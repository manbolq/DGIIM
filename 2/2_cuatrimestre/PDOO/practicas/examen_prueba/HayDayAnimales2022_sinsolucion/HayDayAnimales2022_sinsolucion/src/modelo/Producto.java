/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

/**
 *
 * @author Profe
 */
public abstract class Producto {
    //-------------------------------------------------
    //Atributos
    //-------------------------------------------------
    private String icono = "";
    private int duracionProduccion = 1;
    private int experienciaProduccion = 1;
    private int precioVenta = 1;
   
    
    //-------------------------------------------------
    // Constructores
    //-------------------------------------------------
    Producto(String icono, int duracionProduccion, int experienciaProduccion, int precioVenta){
        this.icono = icono;
        this.duracionProduccion = duracionProduccion;
        this.experienciaProduccion = experienciaProduccion;
        this.precioVenta = precioVenta;
    }
    
    Producto(){
        icono = "";
        duracionProduccion = 1;
        experienciaProduccion = 1;
        precioVenta = 1;
    }
    
    
    //-------------------------------------------------
    // Getters & Setters
    //-------------------------------------------------
    
    public String getIcono() {
        return icono;
    }

    public void setIcono(String icono) {
        this.icono = icono;
    }

    public int getDuracionProduccion() {
        return duracionProduccion;
    }

    public void setDuracionProduccion(int duracionProduccion) {
        this.duracionProduccion = duracionProduccion;
    }

    public int getExperienciaProduccion() {
        return experienciaProduccion;
    }

    public void setExperienciaProduccion(int experienciaProduccion) {
        this.experienciaProduccion = experienciaProduccion;
    }

    public int getPrecioVenta() {
        return precioVenta;
    }

    public void setPrecioVenta(int precioVenta) {
        this.precioVenta = precioVenta;
    }

    //-------------------------------------------------
    // Funcionalidades
    //-------------------------------------------------
    
    public abstract void enProduccion();
   
    
    
}
