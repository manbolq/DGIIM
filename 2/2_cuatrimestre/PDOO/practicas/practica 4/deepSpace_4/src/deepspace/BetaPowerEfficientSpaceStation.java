/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author carlos
 */
public class BetaPowerEfficientSpaceStation extends PowerEfficientSpaceStation {
    private final float EXTRAEFFICIENCY;
    private Dice dice;
    public BetaPowerEfficientSpaceStation(SpaceStation station){
        super(station);
        EXTRAEFFICIENCY = 1.10F;
        dice = new Dice();
        
    }
    
    public float fire(){
        if(dice.extraEfficiency())
            return super.fire()*EXTRAEFFICIENCY;
        else
            return super.fire();
    }
    
    public BetaPowerEfficientSpaceStationToUI getUIversion(){
            return new BetaPowerEfficientSpaceStationToUI(this);
    }
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
}
