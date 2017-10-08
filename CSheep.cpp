#include "CWorld.h"
#include "CGrass.h"
#include "Organism.h"
#include "CSheep.h"
#include "CWolf.h"
#include <time.h>
#include <stdlib.h>

CSheep::CSheep(CWorld *world,int row,int col,int np):Organism(world,row,col,np)
{

}

int CSheep::getType()
{
	if (sex==FEMALE)
	{
		return ISFSHEEP;
	}
	return ISMSHEEP;
}

void CSheep::move()
{
	double dirmax[3][3];

	for (int i=-1;i<2;i++)
	{
		for (int j=-1;j<2;j++)
		{
			if ((posrow+i)<GRIDROW && (posrow+i>=0) && (poscol+j)<GRIDCOL && (poscol+j>=0))
			{
				if (world_llf->getAt(posrow+i,poscol+j)==ISEMPTY)
				{
					dirmax[i+1][j+1]=satisfaction(posrow+i,poscol+j)+double(rand())/RAND_MAX;
				}
				else
				{
					dirmax[i+1][j+1]=-9999;
				}
			}
			else
			{
				dirmax[i+1][j+1]=-9999;
			}
		}
	}

	double maxdir=-99;
	int stepr=-1,stepc=-1;
	for (int i=-1;i<2;i++)
	{
		for (int j=-1;j<2;j++)
		{
			if ((posrow+i)<GRIDROW && (posrow+i)>=0 && (poscol+j)<GRIDCOL && (poscol+j)>=0)
			{
				if (dirmax[i+1][j+1]>maxdir)
				{
					maxdir=dirmax[i+1][j+1];
					stepr=i;
					stepc=j;
				}
			}
		}
	}


	if (world_llf->getAt(posrow+stepr,poscol+stepc)==ISEMPTY)
	{
		world_llf->setAt(posrow+stepr,poscol+stepc,world_llf->getAt(posrow,poscol));
		world_llf->setAt(posrow,poscol,ISEMPTY);
		addPos(stepr,stepc);
		if (world_llf->grass[posrow][poscol]->havegrass)
		{
			world_llf->grass[posrow][poscol]->havegrass=false;
			if (feeddegree+3<=5)
			{
				feeddegree=feeddegree+3;
			}
			else
			{
				feeddegree=5;
			}
		}
		else
		{
			feeddegree=feeddegree-2;
		}
	}
	else
	{
		feeddegree--;
	}
}

void CSheep::pregnancy()
{
	if ((!ispregnancy) && (year>=ADULTYEAR) && (sex==FEMALE))
	{
		for (int i=-2;i<=2;i++)
		{
			for (int j=-2;j<=2;j++)
			{
				if ((posrow+i)<GRIDROW && (posrow+i)>=0 && (poscol+j)<GRIDCOL && (poscol+j)>=0)
				{
					if (world_llf->getAt(posrow+i,poscol+j)!=ISEMPTY)
					{
						if (world_llf->getAt(posrow+i,poscol+j)->getType()==ISMSHEEP)
						{
							if (double(rand())/RAND_MAX<0.5)
							{
								ispregnancy=true;
								preyear=1;
							}
						}
					}
				}
			}
		}

	}
	else if(ispregnancy)
	{
		if (preyear<=GROWYEAR)
		{
			preyear++;
		}
		else
		{
			if ((poscol>0)&&(world_llf->getAt(posrow,poscol-1)==ISEMPTY))
			{
				CSheep *newSheep=new CSheep(world_llf,posrow,poscol-1);
				ispregnancy=false;
				preyear=0;
			}
			else if ((poscol<GRIDCOL-1)&&(world_llf->getAt(posrow,poscol+1)==ISEMPTY))
			{
				CSheep *newSheep=new CSheep(world_llf,posrow,poscol+1);
				ispregnancy=false;
				preyear=0;
			}
			else if ((posrow>0)&&(world_llf->getAt(posrow-1,poscol)==ISEMPTY))
			{
				CSheep *newSheep=new CSheep(world_llf,posrow-1,poscol);
				ispregnancy=false;
				preyear=0;
			}
			else if ((posrow<GRIDROW-1)&&(world_llf->getAt(posrow+1,poscol)==ISEMPTY))
			{
				CSheep *newSheep=new CSheep(world_llf,posrow+1,poscol);
				ispregnancy=false;
				preyear=0;
			}

		}
	}
}

bool CSheep::isdead()
{
	bool fdead=false;
	if (year>=DEADYEAR)
	{
		fdead=true;
	}

	if (feeddegree<=-5)
	{
		fdead=true;
	}
	return fdead;
}

int CSheep::satisfaction(int nrow,int ncol)
{
	int satisfy=0;
	for (int i=-1;i<=1;i++)
	{
		for (int j=-1;j<=1;j++)
		{
			if ((nrow+i)<GRIDROW && (nrow+i>=0) && (ncol+j)<GRIDCOL && (ncol+j>=0))
			{
				if (world_llf->getAt(nrow+i,ncol+j)!=ISEMPTY)
				{
					if (world_llf->getAt(nrow+i,ncol+j)->getType()==ISFWOLF || world_llf->getAt(nrow+i,ncol+j)->getType()==ISMWOLF)
					{
						satisfy=satisfy-10;
					}

					if (world_llf->getAt(nrow+i,ncol+j)->getType()==ISFSHEEP || world_llf->getAt(nrow+i,ncol+j)->getType()==ISMSHEEP)
					{
						satisfy=satisfy+3;
					}
				}
				else
				{
					if (world_llf->grass[nrow+i][ncol+j]->havegrass)
					{
						satisfy=satisfy+5;
					}
					else
					{
						satisfy=satisfy+1;
					}
				}
			}
			else
			{
				return -9999;
			}
		}
	}

	return satisfy;
}