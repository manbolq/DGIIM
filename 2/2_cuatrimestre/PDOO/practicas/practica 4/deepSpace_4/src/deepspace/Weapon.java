/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author manbolq
 */
public class Weapon implements CombatElement{
    private String name;
    private WeaponType type;
    private int uses;
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    Weapon(String name, WeaponType type, int uses){
        this.name = name;
        this.type = type;
        this.uses = uses;
    }
    
    Weapon(Weapon w){
        name = w.name;
        type = w.type;
        uses = w.uses;
    }
    
    
    /**************************************************************************/
    /**************************    CONSULTORES   ******************************/
    /**************************************************************************/
    
    WeaponType getType(){
        return type;
    }
    
    @Override
    public int getUses(){
        return uses;
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    public float power(){
        return type.getPower();
    }
    
    @Override
    public float useIt(){
        if (uses > 0){
            uses--;
            return power();
        }
        else return 1.0f;
    }
    
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
    
    
    WeaponToUI getUIversion(){
        return new WeaponToUI(this);
    }
}