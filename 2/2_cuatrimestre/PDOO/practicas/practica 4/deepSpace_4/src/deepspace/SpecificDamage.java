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
public class SpecificDamage extends Damage{
    private ArrayList<WeaponType> weapons;
    
    /**************************************************************************/
    /**************************    CONSTRUCTOR   ******************************/
    /**************************************************************************/
    
    SpecificDamage(ArrayList<WeaponType> wl, int s){
        super(s);
        weapons = wl;
    }
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    
    public ArrayList<WeaponType> getWeapons(){
        return weapons;
    }
    
    
    private int arrayContainsType(ArrayList<Weapon> w, WeaponType t){
        for (int i = 0; i < w.size(); i++)
            if (w.get(i).getType() == t)
                return i;
        
        return -1;
    }

    @Override
    public Damage copy() {
        return new SpecificDamage(weapons, nShields);
    }

    @Override
    DamageToUI getUIversion() {
        return new SpecificDamageToUI(this);
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
        
        return new SpecificDamage(w_aux, ns_aux);
    }

    @Override
    public void discardWeapon(Weapon w) {
        if (weapons != null){
            for (int i = 0; i < weapons.size(); i++){
                if (weapons.get(i) == w.getType())
                    weapons.remove(i);
            }
        }
    }

    @Override
    public boolean hasNoEffect() {
        return ( (nShields == 0) && (weapons == null || weapons.isEmpty()));
    }

    @Override
    public String toString() {
        return getUIversion().toString();
    }
    
}
