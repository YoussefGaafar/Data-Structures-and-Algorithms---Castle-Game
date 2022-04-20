#include "fighter.h"

fighter::fighter(int id, int arrTime, int d, int reload, double HEALTH, int S, int pow, ENMY_STATUS stat,double OH)
	:Enemy(id, arrTime, d, reload, HEALTH, S, pow, stat,OH)
	//,ID(id), ArrvTime(arrTime), Reloadtime(reload)
{
	SetStatus(stat);
	sethealth(HEALTH);
	setspeed(S);
	SetDistance(d);
	setoriginalhealth(OH);

}

fighter::fighter(int id, int arrt) :Enemy(id,arrt)
	//:ID(0), ArrvTime(0), Reloadtime(0)
{
	SetStatus(INAC);
	sethealth(100);
	setspeed(0);
	SetDistance(0);
	setoriginalhealth(100);
}

void fighter::Act()
{
	/*int x;
	if (ENMY_STATUS status = ACTV )

	{
		if( ArrvTime <= x < Reloadtime)
	{
		double k;
		if (Health == 100)
		{
			k = 1;
			double DFC = (k / Distance) * power;
		}
		else if (Health == 0.5 * Health)
		{
			k = 0.5;
		double DFC = (k / Distance) * power;
		}*/


}




fighter::~fighter()
{

}