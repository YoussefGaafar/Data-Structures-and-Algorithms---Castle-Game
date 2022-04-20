#pragma once
#include "..\Defs.h"
#include <fstream>
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
class Castle
{
	double Health;
	int maxnumberofenemies;
	CASTLE_STATUS status;
	castlebullets_type type;
	int power;
	//
	// TODO: Add More Data Members As Needed
	//

public:
	void load(ifstream& f);
	void SetHealth(double h);
	double GetHealth() const;
	CASTLE_STATUS GetStatus() const;
	void SetStatus(CASTLE_STATUS c);
	castlebullets_type  GetStatuS() const;
	void SetStatuS(castlebullets_type B);
	void setnumberofenemies(int MAX);
	int getnumberofenemies();
    void setpower(int pow);
	int getpower();
	//
	// TODO: Add More Member Functions As Needed
	//

};

