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
public class Hangar {
    private int maxElements;
    private ArrayList<ShieldBooster> shieldBoosters;
    private ArrayList<Weapon> weapons;
    
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    Hangar(int capacity){
        maxElements = capacity;
        shieldBoosters = new ArrayList<>(0);
        weapons = new ArrayList<>(0);
    }
    
    Hangar(Hangar h){
        maxElements = h.maxElements;
        shieldBoosters = h.shieldBoosters;
        weapons = h.weapons;
    }
    
    
    /**************************************************************************/
    /****************************    VERSION   ********************************/
    /**************************************************************************/
    
    HangarToUI getUIversion(){
        return new HangarToUI(this);
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    private boolean spaceAvailable(){
        return (shieldBoosters.size() + weapons.size() < maxElements);
    }
    
    
    public boolean addWeapon(Weapon w){
        if (spaceAvailable()){
            weapons.add(w);
            return true;
        }
        else return false;
    }
    
    
    public boolean addShieldBooster(ShieldBooster s){
        if (spaceAvailable()){
            shieldBoosters.add(s);
            return true;
        }
        else return false;
    }
    
    
    public int getMaxElements(){
        return maxElements;
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return shieldBoosters;
    }
    
    public ArrayList<Weapon> getWeapons(){
        return weapons;
    }
    
    public ShieldBooster removeShieldBooster(int s){
        if (s < shieldBoosters.size() && s >= 0){
            ShieldBooster aux = new ShieldBooster(shieldBoosters.get(s));
            shieldBoosters.remove(s);
            return aux;
        }
        else return null;
    }
    
    
    public Weapon removeWeapon(int w){
        if (w < weapons.size() && w >= 0){
            Weapon aux = new Weapon(weapons.get(w));
            weapons.remove(w);
            return aux;
        }
        else return null;            
    }
    
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
    
}
