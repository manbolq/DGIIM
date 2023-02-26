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
        nMedals = 0;
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
            pendingDamage = null;
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
        hangar = null;
    }
    
    public void discardShieldBooster(int i){
        int size = shieldBoosters.size();
        
        if (i >= 0 && i < size){
            ShieldBooster s = shieldBoosters.remove(i);
            
            if (pendingDamage != null){
                pendingDamage.discardShieldBooster();
                cleanPendingDamage();
            }
        }
    }
    
    public void discardShieldBoosterInHangar(int i){
        if (hangar != null)
            hangar.removeShieldBooster(i);
    }
    
    public void discardWeapon(int i){
        int size = weapons.size();
        
        if (i >= 0 && i < size){
            Weapon w = weapons.remove(i);
            
            if (pendingDamage != null){
                pendingDamage.discardWeapon(w);
                cleanPendingDamage();
            }
        }
    }
    
    public void discardWeaponInHangar(int i){
        if (hangar != null)
            hangar.removeWeapon(i);
    }
    
    public float fire(){
        int size = weapons.size();
        float factor = 1.0f;
        
        for (Weapon w : weapons)
            factor *= w.useIt();
        
        return ammoPower*factor;
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
        int size = shieldBoosters.size();
        float factor = 1.0f;
        
        for (ShieldBooster s : shieldBoosters)
            factor *= s.useIt();
        
        return shieldPower*factor;
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
        float myProtection = protection();
        
        if (myProtection >= shot){
            shieldPower -= SHIELDLOSSPERUNITSHOT*shot;
            if (shieldPower < 0) shieldPower = 0;
            
            return ShotResult.RESIST;
        }
        else{
            shieldPower = 0;
            return ShotResult.DONOTRESIST;
        }
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
        CardDealer dealer = CardDealer.getInstance();
        int h = loot.getNHangars();
        
        if (h > 0){
            Hangar hangar = dealer.nextHangar();
            receiveHangar(hangar);
        }
        
        int elements = loot.getNSupplies();
        for (int i = 1; i <= elements; i++){
            SuppliesPackage sup = dealer.nextSuppliesPackage();
            receiveSupplies(sup);
        }
        
        elements = loot.getNWeapons();
        for (int i = 1; i <= elements; i++){
            Weapon weap = dealer.nextWeapon();
            receiveWeapon(weap);
        }
        
        elements = loot.getNShields();
        for (int i = 1; i <= elements; i++){
            ShieldBooster sh = dealer.nextShieldBooster();
            receiveShieldBooster(sh);
        }
        
        int medals = loot.getNMedals();
        nMedals += medals;
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
