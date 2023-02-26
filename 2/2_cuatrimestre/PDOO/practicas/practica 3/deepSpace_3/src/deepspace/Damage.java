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
public class Damage {
    private int nShields;
    private int nWeapons;
    private ArrayList<WeaponType> weapons;
   
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    Damage(int w, int s){
        nShields = s;
        nWeapons = w;
        weapons = null;
    }
    
    Damage(ArrayList<WeaponType> wl, int s){
        nShields = s;
        nWeapons = -1;
        weapons = wl;
    }
    
    Damage(Damage d){
        nShields = d.nShields;
        nWeapons = d.nWeapons;
        weapons = d.weapons;
    }
    
    /**************************************************************************/
    /****************************    VERSION   ********************************/
    /**************************************************************************/
    
    DamageToUI getUIversion(){
        return new DamageToUI(this);
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    private int arrayContainsType(ArrayList<Weapon> w, WeaponType t){
        for (int i = 0; i < w.size(); i++)
            if (w.get(i).getType() == t)
                return i;
        
        return -1;
    }
    
    
    public Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s){
        int nw_aux = -1;
        int ns_aux = 0;
        
        if (nShields > 0){
            if (nShields > s.size())
                ns_aux = s.size();
            else
                ns_aux = nShields;
        }
        
        if (nWeapons >= 0){
            if (nWeapons > w.size())
                nw_aux = w.size();
            else
                nw_aux = nWeapons;
            
            return new Damage(nw_aux, ns_aux);
        }
        else{
            ArrayList<Weapon> aux = new ArrayList<>();
            for (int i = 0; i < w.size(); i++)
                aux.add(w.get(i));
            
            ArrayList<WeaponType> w_aux = new ArrayList<>();
            
            for (int i = 0; i < weapons.size(); i++){
                if (arrayContainsType(aux, weapons.get(i)) >= 0){
                    w_aux.add(aux.get(arrayContainsType(aux, weapons.get(i))).getType());
                    aux.remove(arrayContainsType(aux, weapons.get(i)));
                }
            }
            
            return new Damage(w_aux, ns_aux);
        }
        
    }
    
    
    public void discardWeapon(Weapon w){
        if (nWeapons > 0)
            nWeapons--;
        else if (nWeapons != 0){
            if (weapons != null){
                for (int i = 0; i < weapons.size(); i++){
                    if (weapons.get(i) == w.getType())
                        weapons.remove(i);
                }
            }
        }
    }
    
    
    public void discardShieldBooster(){
        if (nShields > 0)
            nShields--;
    }
    
    
    public boolean hasNoEffect(){
        return ( (nShields == 0) && ((nWeapons == 0 && weapons == null) || (nWeapons == -1 && weapons.isEmpty())));
    }
    
    
    public int getNShields(){
        return nShields;
    }
    
    public int getNWeapons(){
        return nWeapons;
    }
    
    public ArrayList<WeaponType> getWeapons(){
        return weapons;
    }   
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
}
