#pragma once
#include "../DSProject_Code_F2019/Enemies/Enemy.h"
#include "../DSProject_Code_F2019/Defs.h"
#include "../DSProject_Code_F2019/CMUgraphicsLib/CMUgraphics.h"
class Healer : public Enemy
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
	int direction;
	//double original_health;
public:
	Healer(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat, double OH);
	virtual void Move();
	virtual void Act();
	virtual void DecrementDist();
	~Healer();
	Healer(int id,int arrt);


};

