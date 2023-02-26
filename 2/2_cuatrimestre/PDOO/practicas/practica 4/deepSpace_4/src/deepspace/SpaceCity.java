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
public class SpaceCity extends SpaceStation{
    SpaceStation base;
    ArrayList<SpaceStation> collaborators;
    
    
    
    SpaceCity(SpaceStation base, ArrayList<SpaceStation> rest){
        super(base);
        this.base = base;
        this.collaborators = rest;
    }
    
    
    
    
    public ArrayList<SpaceStation> getCollaborators(){
        return collaborators;
    }
    
    
    @Override
    public float fire(){
        float factor = base.fire();
        
        for (SpaceStation station : collaborators){
            factor *= station.fire();
        }
        
        return factor;
    }
    
    
    @Override
    public float protection(){
        float factor = base.protection();
        
        for (SpaceStation station : collaborators){
            factor *= station.protection();
        }
        
        return factor;
    }
    
    
    @Override
    public Transformation setLoot(Loot loot){
        super.setLoot(loot);
        return Transformation.NOTRANSFORM;
    }
    
    @Override
    public SpaceCityToUI getUIversion(){
        return new SpaceCityToUI(this);
    }    
    
}
