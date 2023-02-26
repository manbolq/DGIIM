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
    private boolean haveSpaceCity;
    
    
    /**************************************************************************/
    /*************************    CONSTRUCTORES   *****************************/
    /**************************************************************************/
    
    public GameUniverse(){
        gameState = new GameStateController();
        dice = new Dice();
        turns = 0;
        
        // no se si hay que inicializarlo asi
        currentStationIndex = 0;
        spaceStations = new ArrayList<>();
        haveSpaceCity = false;
    }
    
    /**************************************************************************/
    /****************************    METODOS   ********************************/
    /**************************************************************************/
    
    CombatResult combat(SpaceStation station, EnemyStarShip enemy){
        GameState state = gameState.getState();
        boolean enemyWins;
        CombatResult combatResult;
        
        if(state == GameState.BEFORECOMBAT || state == GameState.INIT){
            GameCharacter ch = dice.firstShot();
        
            if(ch == GameCharacter.ENEMYSTARSHIP){
                
                float fire = enemy.fire();
                ShotResult result = station.receiveShot(fire);
                
                if(result == ShotResult.RESIST){
                    fire = station.fire();
                    result = enemy.receiveShot(fire);
                    enemyWins = (result == ShotResult.RESIST);
                }else{
                    enemyWins = true;
                }
            }else{
                float fire = station.fire();
                ShotResult result = enemy.receiveShot(fire);
                enemyWins = (result == ShotResult.RESIST);
            }
            
            if(enemyWins){
                float s = station.getSpeed();
                boolean moves = dice.spaceStationMoves(s);
                
                if(!moves){
                    Damage damage = enemy.getDamage();
                    station.setPendingDamage(damage);
                    combatResult = CombatResult.ENEMYWINS;
                }else{
                    station.move();
                    combatResult = CombatResult.STATIONESCAPES;
                }
                    
            }else{
                Loot aLoot = enemy.getLoot();
                Transformation t = station.setLoot(aLoot);
                
                if (t == Transformation.SPACECITY){
                    createSpaceCity();
                    combatResult = CombatResult.STATIONWINSANDCONVERTS;
                }
                else if (t == Transformation.GETEFFICIENT){
                    makeStationEfficient();
                    combatResult = CombatResult.STATIONWINSANDCONVERTS;
                }
                else
                    combatResult = CombatResult.STATIONWINS;
            }
            
            gameState.next(turns, spaceStations.size());
            return combatResult;
        
        }else{
           return CombatResult.NOCOMBAT;
        }
    }
    
    public void createSpaceCity(){
        if(!haveSpaceCity){
            ArrayList<SpaceStation> rest = new ArrayList<>();
            for(SpaceStation s:spaceStations){
                if(s != currentStation){
                    rest.add(s);
                }
            }
            currentStation = new SpaceCity(currentStation,rest);
            spaceStations.set(currentStationIndex,currentStation);
            haveSpaceCity = true;
        }
        
    }
    
    public CombatResult combat(){
        GameState state = getState();
        
        if(state == GameState.BEFORECOMBAT || state == GameState.INIT){
            return combat(currentStation,currentEnemy);
        }else{
            return CombatResult.NOCOMBAT;
        }
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
    
    public void init (ArrayList<String> names){
        GameState state = gameState.getState();
        
        if (state == GameState.CANNOTPLAY){
            spaceStations = new ArrayList<>();
            CardDealer dealer = CardDealer.getInstance();
            
            for (int i = 0; i < names.size(); i++){
                
                SuppliesPackage supplies = dealer.nextSuppliesPackage();
                SpaceStation station = new SpaceStation(names.get(i), supplies);
                
                spaceStations.add(station);
                
                int nh = dice.initWithNHangars();
                int nw = dice.initWithNWeapons();
                int ns = dice.initWithNShields();
                
                Loot lo = new Loot(0, nw, ns, nh, 0);
                station.setLoot(lo);
            }
            currentStationIndex = dice.whoStarts(names.size());
            currentStation = spaceStations.get(currentStationIndex);
            currentEnemy = dealer.nextEnemy();
            gameState.next(turns, spaceStations.size());
        }
        
    }
    
    public GameUniverseToUI getUIversion(){
        return new GameUniverseToUI(currentStation, currentEnemy);
    }
    
    public boolean haveAWinner(){
        return currentStation.getNMedals() >= WIN;
    }
    
    public void makeStationEfficient(){
        if(dice.extraEfficiency()){
            currentStation = new BetaPowerEfficientSpaceStation(currentStation);
        }else{
            currentStation = new PowerEfficientSpaceStation(currentStation);
        }
        
        spaceStations.set(currentStationIndex, currentStation);
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
        GameState state = getState();
        
        if(state == GameState.AFTERCOMBAT){
            
            boolean stationState = currentStation.validState();
            
            if (stationState){
                currentStationIndex = ((currentStationIndex+1)%spaceStations.size());
                turns ++;
                
                currentStation = spaceStations.get(currentStationIndex);
                currentStation.cleanUpMountedItems();
                
                CardDealer dealer = CardDealer.getInstance();
                
                currentEnemy = dealer.nextEnemy();
                
                gameState.next(turns, spaceStations.size());
                
                return true;
            }else{
                return false;
            }
            
        }else{
            return false;
        }
    }
    
    
    @Override
    public String toString(){
        return getUIversion().toString();
    }
    
}
