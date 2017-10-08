#include "Organism.h"
#include "CWorld.h"
#include <time.h>
#include <stdlib.h>


Organism::Organism()
{
	world_llf=NULL;
	posrow=0;
	poscol=0;

	year=0;
	feeddegree=0;
	if (rand()%2==1)
	{
		sex=MALE;
	}
	else
	{
		sex=FEMALE;
	}
	ispregnancy=false;
	preyear=0;
	pacenum=1;
}

Organism::Organism(CWorld *world,int row,int col,int np)
{
	this->world_llf=world;
	this->posrow=row;
	this->poscol=col;
	world->setAt(row,col,this);

	year=(double(rand())/RAND_MAX)*DEADYEAR;
	feeddegree=0;
	if (rand()%2==1)
	{
		sex=MALE;
	}
	else
	{
		sex=FEMALE;
	}
	ispregnancy=false;
	preyear=0;
	pacenum=np;
}