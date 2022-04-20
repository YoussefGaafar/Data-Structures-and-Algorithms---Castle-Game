#include "Healer.h"


Healer::Healer(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat,DOUBLE OH)
	:Enemy(id, arrTime, d, reload, HEALTH, S, pow, stat, OH)
	//,ID(id), ArrvTime(arrTime), Reloadtime(reload)
{
	SetStatus(stat);
	sethealth(HEALTH);
	setspeed(S);
	SetDistance(d);
	setoriginalhealth(OH);
	direction = -1;
}

void Healer::Move()
{
	
	DecrementDist();

}
Healer::Healer(int id, int arrt):Enemy(id,arrt)
	
	//, ArrvTime(0), Reloadtime(0)
{
	SetStatus(INAC);
	sethealth(100);
	setspeed(0);
	SetDistance(0);
	setoriginalhealth(100);
	direction = -1;
}
void Healer::DecrementDist()
{
	if (Health < 0.5 * original_health)
	   Distance = Distance + direction * (speed/2);
	else
	{
		Distance = Distance + direction * speed;
	}
	if (Distance == 60)
	   direction = -1;
	if (Distance == 2)
	   direction = 1;
}
void Healer::Act()
{

}
Healer::~Healer()
{
}