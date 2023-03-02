/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author manbolq
 */
public class ShieldBooster {
    private String name;
    private float boost;
    private int uses;
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    ShieldBooster(String name, float boost, int uses){
        this.name = name;
        this.boost = boost;
        this.uses = uses;
    }
    
    ShieldBooster(ShieldBooster s){
        name = s.name;
        boost = s.boost;
        uses = s.uses;
    }
    
    
    /**************************************************************************/
    /**************************    CONSULTORES   ******************************/
    /**************************************************************************/
    
    float getBoost(){
        return boost;
    }
    
    int getUses(){
        return uses;
    }
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    public float useIt(){
        if (uses > 0){
            boost--;
            return boost;
        }
        else
            return 1.0f;
    }
}

