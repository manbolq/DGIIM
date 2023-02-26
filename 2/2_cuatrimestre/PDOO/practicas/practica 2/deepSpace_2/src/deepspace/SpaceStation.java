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
public class SpaceStation {
    private final int MAXFUEL = 100;
    private final float SHIELDLOSSPERUNITSHOT = 0.1f;
    
    private float ammoPower;
    private float fuelUnits;
    private String name;
    private int nMedals;
    private float shieldPower;
    private Hangar hangar;
    private ArrayList<ShieldBooster> shieldBoosters;
    private ArrayList<Weapon> weapons;
    private Damage pendingDamage;
    
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    SpaceStation(String n, SuppliesPackage supplies){
        name = n;
        ammoPower = supplies.getAmmoPower();
        fuelUnits = supplies.getFuelUnits();
        shieldPower = supplies.getShieldPower();
        weapons = new ArrayList<Weapon>();
        hangar = new Hangar(0);
        nMedals = 0;
        pendingDamage = new Damage(0, 0);
        shieldBoosters = new ArrayList<ShieldBooster>();
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    private void assignFuelValue(float f){
        if (f <= MAXFUEL)
            fuelUnits = f;
    }
    
    private void cleanPendingDamage(){
        if (pendingDamage.hasNoEffect())
            pendingDamage = new Damage(0, 0);
    }
    
    public void cleanUpMountedItems(){
        for (int i = 0; i < weapons.size(); i++){
            if (weapons.get(i).getUses() == 0)
                weapons.remove(i);
        }
        
        for (int i = 0; i < shieldBoosters.size(); i++){
            if (shieldBoosters.get(i).getUses() == 0)
                shieldBoosters.remove(i);
        }
    }
    
    public void discardHangar(){
        hangar = new Hangar(0);
    }
    
    public void discardShieldBooster(int i){
        throw new UnsupportedOperationException();
    }
    
    public void discardShieldBoosterInHangar(int i){
        if (hangar != null)
            hangar.removeShieldBooster(i);
    }
    
    public void discardWeapon(int i){
        throw new UnsupportedOperationException();
    }
    
    public void discardWeaponInHangar(int i){
        if (hangar != null)
            hangar.removeWeapon(i);
    }
    
    public float fire(){
        throw new UnsupportedOperationException();
    }
    
    public float getAmmoPower(){
        return ammoPower;
    }
    
    public float getFuelUnits(){
        return fuelUnits;
    }
    
    public Hangar getHangar(){
        return hangar;
    }
    
    public String getName(){
        return name;
    }
    
    public int getNMedals(){
        return nMedals;
    }
    
    public Damage getPendingDamage(){
        return pendingDamage;
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return shieldBoosters;
    }
    
    public float getShieldPower(){
        return shieldPower;
    }
    
    public float getSpeed(){
        return fuelUnits/MAXFUEL;
    }
    
    public SpaceStationToUI getUIversion(){
        return new SpaceStationToUI(this);
    }
    
    public ArrayList<Weapon> getWeapons(){
        return weapons;
    }
    
    public void mountShieldBooster(int i){
        if (hangar != null){
            ShieldBooster aux = hangar.removeShieldBooster(i);
            if (aux != null)
                shieldBoosters.add(aux);
        }
    }
    
    public void mountWeapon(int i){
        if (hangar != null){
            Weapon aux = hangar.removeWeapon(i);
            if (aux != null)
                weapons.add(aux);
        }
    }
    
    public void move(){
        fuelUnits -= getSpeed();
        if (fuelUnits < 0)
            fuelUnits = 0;
    }
    
    
    public float protection(){
        throw new UnsupportedOperationException();
    }
    
    public void receiveHangar(Hangar h){
        if (hangar == null || hangar.getMaxElements() == 0)
            hangar = h;
    }
    
    public boolean receiveShieldBooster(ShieldBooster s){
        if (hangar != null)
            return hangar.addShieldBooster(s);
        else
            return false;
    }
    
    public ShotResult receiveShot(float shot){
        throw new UnsupportedOperationException();
    }
    
    public void receiveSupplies(SuppliesPackage s){
        ammoPower += s.getAmmoPower();
        shieldPower += s.getShieldPower();
        fuelUnits += s.getFuelUnits();
    }
    
    public boolean receiveWeapon(Weapon w){
        if (hangar != null)
            return hangar.addWeapon(w);
        else
            return false;
    }
    
    public void setLoot(Loot loot){
        throw new UnsupportedOperationException();
    }
    
    public void setPendingDamage(Damage d){
        pendingDamage = d.adjust(weapons, shieldBoosters);
    }
    
    public boolean validState(){
        return ((pendingDamage == null) || (pendingDamage.hasNoEffect()));
    }
    
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
    
    
    
}
