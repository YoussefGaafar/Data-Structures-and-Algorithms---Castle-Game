#pragma once
#include "Enemy.h"
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
class fighter :
	public Enemy
{
protected: //is this important here?
	//const int ID;         //Each enemy has a unique ID (sequence number)
	//const int ArrvTime;	//arrival time (time it starts to join battle)
	//const int Reloadtime;// this is reloaD period(3 SEC)
	//ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	//int power;               //Always positive (ranges from 2 to 60)
	//double Health;	//Enemy health
	//int speed;
	//double original_health;
public:
	//fighter(int id, int arrTime);
	fighter(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat, double OH);
	//virtual void Move();
	virtual void Act();
	~fighter();
	fighter(int id, int arrt);
	


};



