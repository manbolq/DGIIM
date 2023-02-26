/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author carlos
 */
public class PowerEfficientSpaceStation extends SpaceStation{
    
    private final float EFFICIENCYFACTOR;
    
    public PowerEfficientSpaceStation(SpaceStation station){
        super(station);
        EFFICIENCYFACTOR = 1.10F;
    }
    
    public float fire(){
        return super.fire()*EFFICIENCYFACTOR;
    }
    
    public float protection(){
        return super.protection()*EFFICIENCYFACTOR;
    }
    
    public Transformation setLoot(Loot loot){
        super.setLoot(loot);
        return Transformation.NOTRANSFORM;
        
    }
    
    public PowerEfficientSpaceStationToUI getUIversion(){
            return new PowerEfficientSpaceStationToUI(this);
    }
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
}
