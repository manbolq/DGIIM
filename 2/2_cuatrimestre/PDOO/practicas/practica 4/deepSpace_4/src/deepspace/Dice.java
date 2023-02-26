/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.Random;

/**
 *
 * @author manbolq
 */
public class Dice {
    private final float NHANGARSPROB;
    private final float NSHIELDSPROB;
    private final float NWEAPONSPROB;
    private final float FIRSTSHOTPROB;
    private final float EXTRAEFFICIENCYPROB;
    
    private Random generator;
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    Dice(){
        NHANGARSPROB=0.25f;
        NSHIELDSPROB=0.25f;
        NWEAPONSPROB=0.33f;
        FIRSTSHOTPROB=0.5f;
        EXTRAEFFICIENCYPROB=0.8f;
        generator = new Random();
    }
    
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    int initWithNHangars(){
        float random = generator.nextFloat();
        if (random <= NHANGARSPROB)
            return 0;
        else
            return 1;
    }
    
    int initWithNWeapons(){
        float random = generator.nextFloat();
        if (random <= NWEAPONSPROB)
            return 1;
        else if (random <= 2*NWEAPONSPROB)
            return 3;
        else
            return 2;
    }
    
    
    int initWithNShields(){
        float random = generator.nextFloat();
        
        if (random <= NSHIELDSPROB)
            return 0;
        else
            return 1;
    }
    
    
    int whoStarts(int nPlayers){
        return generator.nextInt(nPlayers);
    }
    
    
    GameCharacter firstShot(){
        float random = generator.nextFloat();
        if (random <= FIRSTSHOTPROB)
            return GameCharacter.SPACESTATION;
        else
            return GameCharacter.ENEMYSTARSHIP;            
    }
    
    
    boolean spaceStationMoves(float speed){
        float random = generator.nextFloat();
        return (random <= speed);
    }
    
    boolean extraEfficiency(){
        return (generator.nextFloat() <= EXTRAEFFICIENCYPROB);
    }
}
