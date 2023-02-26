/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Enum.java to edit this template
 */
package deepspace;

/**
 *
 * @author manbolq
 */
public enum WeaponType {
    LASER(2.0f), MISSILE(3.0f), PLASMA(4.0f);
    
    private float power;
    
    WeaponType(float power){
        this.power = power;
    }
    
    float getPower(){
        return power;
    }   
    
//    String toString(){
//        if (power == 2.0f) return "LASER";
//        else if (power == 3.0f) return "MISSILE";
//        else return "PLASMA";
//    }
    
}
