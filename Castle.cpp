#include "Castle.h"
#include <fstream>



void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Castle::GetHealth() const
{
	return Health;
}

void Castle::SetStatus(CASTLE_STATUS c)
{
	status = c;


}
CASTLE_STATUS Castle::GetStatus() const
{
	return status;


}


void Castle::SetStatuS(castlebullets_type B)
{
	type = B;


}

castlebullets_type Castle::GetStatuS() const
{
	return type;
}


void Castle::setnumberofenemies(int MAX)
{

	maxnumberofenemies = MAX;

}

int Castle::getnumberofenemies()
{


	return maxnumberofenemies;
}

void  Castle::setpower(int pow)
{
	if (pow > 0)
	{
		power = pow;
	}
	else power = 1;


}
int Castle::getpower()
{

	return power;
}

void Castle::load(ifstream & f)

{
	if (f.is_open())
	{
		double H;
		int MaX;
		int POW;
		f >> H >> MaX >> POW;
		SetHealth(H);
		setnumberofenemies( MaX);
		setpower( POW);
		SetStatus(ACTIV);
	}


}