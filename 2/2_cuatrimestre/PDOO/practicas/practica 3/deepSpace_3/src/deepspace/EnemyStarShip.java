/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author manbolq
 */
public class EnemyStarShip {
    private float ammoPower;
    private String name;
    private float shieldPower;
    private Damage damage;
    private Loot loot;
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    EnemyStarShip(String n, float a, float s, Loot l, Damage d){
        ammoPower = a;
        name = n;
        shieldPower = s;
        damage = d;
        loot = l;
    }
    
    EnemyStarShip(EnemyStarShip e){
        ammoPower = e.ammoPower;
        name = e.name;
        shieldPower = e.shieldPower;
        damage = e.damage;
        loot = e.loot;
    }
    
    
    /**************************************************************************/
    /****************************    VERSION   ********************************/
    /**************************************************************************/
    
    EnemyToUI getUIversion(){
        return new EnemyToUI(this);
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    public float fire(){
        return ammoPower;
    }
    
    public float getAmmoPower(){
        return ammoPower;
    }
    
    public Damage getDamage(){
        return damage;
    }
    
    public Loot getLoot(){
        return loot;
    }
    
    public String getName(){
        return name;
    }
    
    public float getShieldPower(){
        return shieldPower;
    }
    
    public float protection(){
        return shieldPower;
    }
    
    public ShotResult receiveShot(float shot){
        if (shot > shieldPower)
            return ShotResult.DONOTRESIST;
        else
            return ShotResult.RESIST;
    }
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
}
