#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Generic_DS\Node.h"
#include "GUI\GUI.h"
#include"Enemies/fighter.h"
#include "Healer.h"
#include "Freezer.h"
#include"Stack.h"
#include"ArrayBag.h"
#include"BagInterface.h"
// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	int ActiveCount = 0;
	int FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)
	int CurrentTimeStep;
	int HealerFRSTCount ;
	int FighterFRSTCount ;
	int FighterKILDCount ;
	int FreezerFRSTCount;
	int FreezerACTVCount;
	int FreezerKildCount;
	int HealerACTVCount;
	int FighterACTVCount;
	int HealerKILDCount;
	//Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	Queue<Enemy*>ActiveFighet;
	Queue<Enemy*>ActiveFreezer;
	LinkedListStack<Enemy*>ActiveHealer;
	ArrayBag<Enemy*>KilledEnemies;
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue for all enemies in the battle
	/*int DemoListCount;*/
	int FighterEnemyCount=0;
	int HealerEnemyCount=0;
	int FreezerEnemyCount=0;


	
	/// ==>


	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	void Load();
	void AddAllListsToDrawingList();		//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle * GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived

	void AddtoFigherList(Enemy* ptr);
	void AddtoFreezerList(Enemy* ptr);
	void AddtoHealerList(Enemy* ptr);
	void AddtoKilledList(Enemy* Ptr);		//Add Enemy to the demo queue of enemies (for demo purposes only)
	void Simulation();	//just to show a demo and should be removed in phase1 1 & 2
	void SimulationPhase1();
	void moveAll();
	
};

