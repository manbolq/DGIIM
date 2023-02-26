/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author manbolq
 */
public class Weapon {
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
    
    
    int getUses(){
        return uses;
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    public float power(){
        return type.getPower();
    }
    
    
    public float useIt(){
        if (uses > 0){
            uses--;
            return power();
        }
        else return 1.0f;
    }
}
