#include "Enemy.h"
#include <fstream>
#include "..\Defs.h"

using namespace std;


Enemy::Enemy(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat, double OH) : ID(id), ArrvTime(arrTime), Reloadtime(reload)
{
	SetStatus( stat);
	sethealth(HEALTH);
	setspeed(S);
	SetDistance(d);
	setoriginalhealth(OH);

}
Enemy::Enemy(int id, int arrt) :ID(id), ArrvTime(arrt), Reloadtime(0)
{
	SetStatus(INAC);
	sethealth(0);
	setspeed(0);
	SetDistance(MaxDistance);
}
Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}

void Enemy::setoriginalhealth(double OH)
{

	if (OH > 0)
	{
		original_health = OH;
	}
	else original_health = 100;

}

double  Enemy::getoriginalhealth()
{
	return original_health;
}
void Enemy:: setspeed(int S)

{
	if (S > 0)
		speed = S;
	else speed = 2;
  

}


int Enemy::getspeed()const
{
	return speed;

}

ENMY_STATUS Enemy::GetStatus() const
{

  return status;

}
void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}

void Enemy::Move()
{
	// -- -- -- -- -- -- -- -- -- -- -- --
	{
		DecrementDist();
	}
}



void Enemy::sethealth(double HEALTH)
{
	if (HEALTH > 0)
	{
		

		Health = HEALTH;

	}
	else Health = 100;


}
void Enemy::load(ifstream& f)
{

	if (f.is_open())
	{
		int id;         //Each enemy has a unique ID (sequence number)
		int AT;	//arrival time (time it starts to join battle)
		int RT;// this is reloaD period(3 SEC)

		int P;               //Always positive (ranges from 2 to 60)
		double H;	//Enemy health
		int Ss;
		int type;

		f >> H >> P >> RT >> Ss;
		sethealth(H);
		setpower( P);
		setspeed(Ss);
		Reloadtime = RT;

	}
}
double Enemy::gethealth() const
{
	return Health;
}

void Enemy::setpower(int pow)
{
	if (pow > 0)
		power = pow;
	else power = 1;
}

int Enemy::getpower()
{
	return power;
}
void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
	{
		if (Health < 0.5 * original_health)
		{
			Distance = Distance - (speed/2);
		}


		if (Health > 0.5 * original_health)
		{
			Distance = Distance - speed;
		}
	}
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}
