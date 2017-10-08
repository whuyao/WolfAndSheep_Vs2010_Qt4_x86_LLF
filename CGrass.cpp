#include "CWorld.h"
#include "CGrass.h"
 #include<stdlib.h>

CGrass::CGrass()
{
	world_llf=NULL;
	posrow=0;
	poscol=0;

	havegrass=true;
	year=0;
}

CGrass::CGrass(CWorld *world,int row,int col)
{
	this->world_llf=world;
	this->posrow=row;
	this->poscol=col;
	world->setgrassAt(row,col,this);

	havegrass=true;
	year=0;
}

void CGrass::grow()
{
	if (!havegrass)
	{
		year++;
		if (year==4)
		{
			havegrass=true;
			year=0;
			world_llf->grass[posrow][poscol]->havegrass=true;
		}
	}
}

bool CGrass::grassstate()
{
	return havegrass;
}