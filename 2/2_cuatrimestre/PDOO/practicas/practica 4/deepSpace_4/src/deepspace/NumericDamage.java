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
public class NumericDamage extends Damage{
    private int nWeapons;
    
    
    /**************************************************************************/
    /**************************    CONSTRUCTOR   ******************************/
    /**************************************************************************/
    
    NumericDamage(int w, int s){
        super(s);
        nWeapons = w;
    }    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    public int getNWeapons(){
        return nWeapons;
    }
    
    @Override
    NumericDamageToUI getUIversion(){
        return new NumericDamageToUI(this);
    }

    @Override
    public Damage copy() {
        return new NumericDamage(nWeapons, nShields);
    }

    @Override
    public Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s) {
        int ns_aux = 0;
        if (nShields > 0){
            if (nShields > s.size())
                ns_aux = s.size();
            else
                ns_aux = nShields;
        }
            
        
        int nw_aux = 0;
        if (nWeapons > 0){
            if (nWeapons > w.size())
                nw_aux = w.size();
            else
                nw_aux = nWeapons;
        }
        
        return new NumericDamage(nw_aux, ns_aux);
        
    }

    @Override
    public void discardWeapon(Weapon w) {
        if (nWeapons > 0)
            nWeapons--;
    }

    @Override
    public boolean hasNoEffect() {
        return ( (nShields == 0) && (nWeapons == 0));
    }

    @Override
    public String toString() {
        return getUIversion().toString();
    }
    
    
}
