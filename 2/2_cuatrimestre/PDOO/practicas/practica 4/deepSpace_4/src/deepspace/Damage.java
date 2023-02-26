/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.ArrayList;


/**
 *
 * @author manbolq
 */


public abstract class Damage{
    protected int nShields;
    
    /**************************************************************************/
    /**************************    CONSTRUCTOR   ******************************/
    /**************************************************************************/
    
    Damage(int s){
        nShields = s;
    }
    
    
    /**************************************************************************/
    /***********************    METODOS ABSTRACTOS  ***************************/
    /**************************************************************************/
    
    public abstract Damage copy();
    
    abstract DamageToUI getUIversion();
    
    public abstract Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s);
    
    public abstract void discardWeapon(Weapon w);
    
    public abstract boolean hasNoEffect();
    
    @Override
    public abstract String toString();
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/   
    
    public void discardShieldBooster(){
        if (nShields > 0)
            nShields--;
    }
    
    
    public int getNShields(){
        return nShields;
    }
}