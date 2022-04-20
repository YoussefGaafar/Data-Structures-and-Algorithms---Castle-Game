#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)
    int Reloadtime;// this is reloaD period(3 SEC)
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	int Distance;	//Horizontal distance between enemy & the tower of its region
	int power;               //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
    int speed;
	double original_health;
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Enemy(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat,double OH);
	Enemy(int id,int arrt);
	virtual ~Enemy();
	void setoriginalhealth(double  OH);
	double getoriginalhealth();
	int GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS s);
	void setspeed(int S);//
	int getspeed()const;//
	void  sethealth(double HEALTH);//
	double gethealth()const;//
	void setpower(int pow);//
	int getpower();//
	virtual void DecrementDist();
	virtual void load(ifstream& f);
	void SetDistance(int d );
	int GetDistance() const;

	int GetArrvTime() const;
	

	// Virtual Functions: ----------------

	virtual void Move() ;	//All enemies can move
	virtual void Act() = 0;	//Acting means fighting or healing
	
	//
	// TODO: Add More Member Functions As Needed
	//

};

