#include "Freezer.h"


freezer::freezer(int id, int arrTime, int d, int reload, int HEALTH, int S, int pow, ENMY_STATUS stat)
	:ID(id), ArrvTime(arrTime), Reloadtime(reload)
{
	SetStatus(stat);
	sethealth(HEALTH);
	setspeed(S);
	SetDistance(d);


}
