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
public class GameUniverse {
    private final int WIN = 10;
    
    private int currentStationIndex;
    private int turns;
    private Dice dice;
    private GameStateController gameState;
    private SpaceStation currentStation;
    private ArrayList<SpaceStation> spaceStations;
    private EnemyStarShip currentEnemy;
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    GameUniverse(){
        gameState = new GameStateController();
        dice = new Dice();
        turns = 0;
        
        // no se si hay que inicializarlo asi
        currentStationIndex = 0;
        currentStation = new SpaceStation("", new SuppliesPackage(0, 0, 0));
        spaceStations = new ArrayList<>();
        currentEnemy = new EnemyStarShip("", 0, 0, new Loot(0, 0, 0, 0, 0), new Damage(0, 0));
    }
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    CombatResult combat(SpaceStation station, EnemyStarShip enemy){
        throw new UnsupportedOperationException();
    }
    
    public CombatResult combat(){
        throw new UnsupportedOperationException();
    }
    
    public void discardHangar(){
        if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).discardHangar();
    }
    
    public void discardShieldBooster(int i){
        if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).discardShieldBooster(i);
    }
    
    public void discardShieldBoosterInHangar(int i){
         if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).discardShieldBoosterInHangar(i);
    }
    
    public void discardWeapon(int i){
         if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).discardWeapon(i);
    }
    
    public void discardWeaponInHangar(int i){
         if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).discardWeaponInHangar(i);
    }
    
    public GameState getState(){
        return gameState.getState();
    }
    
    public GameUniverseToUI getUIversion(){
        return new GameUniverseToUI(currentStation, currentEnemy);
    }
    
    public boolean haveAWinner(){
        return currentStation.getNMedals() >= WIN;
    }
    
    public void init(ArrayList<String> names){
        throw new UnsupportedOperationException();
    }
    
    public void mountShieldBooster(int i){
        if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).mountShieldBooster(i);
    }
    
    public void mountWeapon(int i){
        if ((gameState.getState() == GameState.INIT) || (gameState.getState() == GameState.AFTERCOMBAT))
            spaceStations.get(currentStationIndex).mountWeapon(i);
    }
    
    public boolean nextTurn(){
        throw new UnsupportedOperationException();
    }
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
    
}
