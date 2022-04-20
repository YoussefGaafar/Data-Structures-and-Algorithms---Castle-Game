#include "Battle.h"
#include <time.h>
#include "Generic_DS\Node.h"
Battle::Battle()
{	
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	CurrentTimeStep = 0;
	HealerFRSTCount = 0;
	HealerACTVCount = 0;
	 FighterFRSTCount = 0;
	 FighterKILDCount = 0;
	 FreezerFRSTCount = 0;
	 FreezerACTVCount = 0;
	 FreezerKildCount = 0;
	 HealerKILDCount=0;

	pGUI = NULL;
}


void Battle::AddtoFigherList(Enemy* ptr)
{
	ActiveFighet.enqueue(ptr);
	FighterEnemyCount++;
}
void Battle::AddtoFreezerList(Enemy* ptr2)
{
	ActiveFreezer.enqueue(ptr2);
	FreezerEnemyCount++;
}
void Battle::AddtoHealerList(Enemy* ptr3)
{
	ActiveHealer.push(ptr3);
	HealerEnemyCount++;

}
void Battle::AddtoKilledList(Enemy* ptr)
{
	KilledEnemies.add(ptr);
}
Castle * Battle::GetCastle()
{
	return &BCastle;
}

void Battle::Load()
{
	pGUI->PrintMessage("Enter the name of the file you want to load");
	string filename = pGUI->GetString();
	ifstream f(filename + ".txt");

		if (f.is_open())
	{
		BCastle.load(f);
		f >> EnemyCount;
		for (int i = 0;i < EnemyCount;i++)
		{
			int id;
			int type;
			int arrt;
			f >> id >> type>> arrt ;
			if (type == 0)
			{

				fighter* F = new fighter(id, arrt);

				F->load(f);
				Q_Inactive.enqueue(F);
				//F.set
			}
			else if (type == 1)
			{
				Healer* H = new Healer(id, arrt);
				H->load(f);
				Q_Inactive.enqueue(H);
			}
			else if (type == 2)
			{
				Freezer* FR = new Freezer(id, arrt);
				FR->load(f);
				Q_Inactive.enqueue(FR);

			}
			
			 //initiall all enemies are inactive 
			//pE->SetStatus(INAC);
            		//Add created enemy to inactive Queue

		}
		
		
	}
		
}
void Battle::moveAll()

{
	Enemy* f;
	Queue<Enemy*> tempfighter;
	while (ActiveFighet.peekFront(f))
	{
		
		ActiveFighet.dequeue(f);
		f->Move();
		tempfighter.enqueue(f);


	}
	while (tempfighter.peekFront(f))
	{
		tempfighter.dequeue(f);
		ActiveFighet.enqueue(f);
	}
	Queue<Enemy*> tempfreezer;
	while (ActiveFreezer.peekFront(f))
	{

		ActiveFreezer.dequeue(f);
		f->Move();
		tempfreezer.enqueue(f);


	}
	while (tempfreezer.peekFront(f))
	{
		tempfreezer.dequeue(f);
		ActiveFreezer.enqueue(f);
	}
	LinkedListStack<Enemy*>tempHealer;
	while (ActiveHealer.peek(f))
	{
		ActiveHealer.pop(f);
		f->Move();
		tempHealer.push(f);
	}
	while (tempHealer.peek(f))
	{
		tempHealer.pop(f);
		
		ActiveHealer.push(f);
	}
					  	



}


void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		Simulation();
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	

	}

	delete pGUI;
	
}



void Battle::Simulation()
{	
	Load();
	

	pGUI->waitForClick();

	CurrentTimeStep = 0;
	
	

	AddAllListsToDrawingList();

	
	pGUI->UpdateInterface(CurrentTimeStep, BCastle.GetHealth(),BCastle.GetStatus(), FighterEnemyCount, FreezerACTVCount,  HealerACTVCount, ActiveCount,FighterFRSTCount,FreezerFRSTCount, HealerFRSTCount, FrostedCount, FighterKILDCount,FreezerKildCount, HealerKILDCount, KilledCount);	//upadte interface to show the initial case where all enemies are still inactive

	pGUI->waitForClick();
	
	while( KilledCount < EnemyCount )	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();
		moveAll();
		SimulationPhase1();
		

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep,BCastle.GetHealth(), BCastle.GetStatus(), FighterEnemyCount, FreezerEnemyCount, HealerEnemyCount, ActiveCount, FighterFRSTCount, FreezerFRSTCount, HealerFRSTCount, FrostedCount, FighterKILDCount, FreezerKildCount, HealerKILDCount, KilledCount);	//upadte interface to show the initial case where all enemies are still inactive
		

		pGUI->waitForClick();
		//Sleep(250);
	}		
}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{	
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const* EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(EnemyList[i]);
	Enemy* const* FighterList = ActiveFighet.toArray(FighterEnemyCount);
	for (int i = 0; i < FighterEnemyCount; i++)
		pGUI->AddToDrawingList(FighterList[i]);
	Enemy* const* FreezerList = ActiveFreezer.toArray(FreezerEnemyCount);
	for (int i = 0; i < FreezerEnemyCount; i++)
		pGUI->AddToDrawingList(FreezerList[i]);
	Enemy* const* HealerList = ActiveHealer.toArray(HealerEnemyCount);
	for (int i = 0; i < HealerEnemyCount; i++)
		pGUI->AddToDrawingList(HealerList[i]);


}


//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy* pE;
	while (Q_Inactive.peekFront(pE))	//as long as there are more inactive enemies
	{
		if (pE->GetArrvTime() != CurrentTimeStep)	//no more arrivals at current time
			return;
		else
		{
			Q_Inactive.dequeue(pE);	//remove enemy from the queue
			pE->SetStatus(ACTV);	//make status active
			fighter* P = dynamic_cast<fighter*>(pE);
			if (P)
			{
				AddtoFigherList(pE);
				ActiveCount++;
			}
			else
			{
				Freezer* F = dynamic_cast<Freezer*>(pE);
				if (F)
				{
					AddtoFreezerList(pE); 				ActiveCount++;
				}

				else
				{
					AddtoHealerList(pE);
					ActiveCount++;
				}

			}
		}

	}

}


//Randomly update enemies distance/status (for demo purposes)
void Battle::SimulationPhase1()
{
	Enemy* Dr;
	
	Queue<Enemy*> tempfighter;
	Queue<Enemy*>tempFreezer;
	LinkedListStack<Enemy*>tempHealer;
	while (ActiveFighet.peekFront(Dr))
	{
		ActiveFighet.dequeue(Dr);
		
		{
			if (Dr->GetStatus() == ACTV&& FighterFRSTCount < 2)
			{
				Dr->SetStatus(FRST);
				FighterFRSTCount++;
				FighterACTVCount--;
				FrostedCount++;
				ActiveCount--;
			}
			else if (Dr->GetStatus() == FRST&& FighterKILDCount < 1)
			{
				Dr->SetStatus(KILD);
				FighterKILDCount++;
				FighterFRSTCount--;

				FrostedCount--;
				KilledCount++;
			}

		}
		tempfighter.enqueue(Dr);
	}
	while (tempfighter.peekFront(Dr))
	{
		tempfighter.dequeue(Dr);
		ActiveFighet.enqueue(Dr);
	}
	/////////////////////////////////////////////////
	while (ActiveFreezer.peekFront(Dr))
	{
		ActiveFreezer.dequeue(Dr);
		
		{
			if (Dr->GetStatus() == ACTV&& FreezerFRSTCount < 2)
			{
				Dr->SetStatus(FRST);
				FreezerFRSTCount++;
				FreezerACTVCount--;
				FrostedCount++;
				ActiveCount--;
			}
			else if (Dr->GetStatus() == FRST&&FreezerACTVCount<1 )
			{
				Dr->SetStatus(ACTV);
				FreezerFRSTCount--;
				FreezerACTVCount++;

				FrostedCount--;
				ActiveCount++;
				if (Dr->GetStatus() == ACTV && FreezerKildCount < 1)
				{
					Dr->SetStatus(KILD);
					FreezerKildCount++;
					FreezerACTVCount--;

					ActiveCount--;
					KilledCount++;

				}
			}
			 

		}
		tempFreezer.enqueue(Dr);
	}
	while (tempFreezer.peekFront(Dr))
	{
		tempFreezer.dequeue(Dr);
		ActiveFreezer.enqueue(Dr);
	}
	///////////////////////////////////////////////////
	while (ActiveHealer.peek(Dr))
	{
		ActiveHealer.pop(Dr);
		 
		{
			if (Dr->GetStatus() == ACTV && HealerFRSTCount < 2)
			{
				Dr->SetStatus(FRST);
				HealerFRSTCount++;
				HealerACTVCount--;
				FrostedCount++;
				ActiveCount--;
			}
			else if (Dr->GetStatus() == FRST )
			{
				Dr->SetStatus(ACTV);
				
				HealerFRSTCount--;
				HealerACTVCount++;

				FrostedCount--;
				ActiveCount++;
			}
		}
		tempHealer.push(Dr);
	}
	while (tempHealer.peek(Dr))
	{
		tempHealer.pop(Dr);
		ActiveHealer.push(Dr);
	}
}
	/////////////////////////////////////////////////



