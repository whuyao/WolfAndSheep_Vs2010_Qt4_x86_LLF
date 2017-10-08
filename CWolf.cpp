#include "CWorld.h"
#include "CGrass.h"
#include "Organism.h"
#include "CSheep.h"
#include "CWolf.h"
#include <time.h>
#include <stdlib.h>

CWolf::CWolf():Organism()
{
	prePredation=0.75;
}

CWolf::CWolf(CWorld *world,int row,int col,int np):Organism(world,row,col,np)
{
	prePredation=0.75;
}

void CWolf::move()
{
	double dirmax[3][3];

	for (int i=-1;i<=1;i++)
	{
		for (int j=-1;j<=1;j++)
		{
			if ((posrow+i)<GRIDROW && (posrow-i>=0) && (poscol+j)<GRIDCOL && (poscol-j>=0))
			{
				if (world_llf->getAt(posrow+i,poscol+j)==ISEMPTY)
				{
					dirmax[i+1][j+1]=satisfaction(posrow+i,poscol+j)+double(rand())/RAND_MAX;
				}
				else if(world_llf->getAt(posrow+i,poscol+j)->getType()==ISFSHEEP || world_llf->getAt(posrow+i,poscol+j)->getType()==ISMSHEEP)
				{
					dirmax[i+1][j+1]=499+satisfaction(posrow+i,poscol+j)+double(rand())/RAND_MAX;
				}
				else if (world_llf->getAt(posrow+i,poscol+j)->getType()==ISFWOLF || world_llf->getAt(posrow+i,poscol+j)->getType()==ISMWOLF)
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
		feeddegree=feeddegree-2;
	}
	else 
	{
		if(world_llf->getAt(posrow+stepr,poscol+stepc)->getType()==ISFSHEEP || world_llf->getAt(posrow+stepr,poscol+stepc)->getType()==ISMSHEEP)
		{
			if (double(rand())/RAND_MAX<prePredation)
			{
				/*delete (world_llf->grid[posrow+stepr][posrow+stepc]);*/
				world_llf->grid[posrow+stepr][poscol+stepc]=this;
				world_llf->setAt(posrow,poscol,ISEMPTY);
				addPos(stepr,stepc);
				if (feeddegree+15<=30)
				{
					feeddegree=feeddegree+15;
				}
				else
				{
					feeddegree=30;
				}
			}
			else
			{
				feeddegree=feeddegree-3;
			}
		}
		else
		{
			feeddegree=feeddegree-1;
		}
	}
	
}

int CWolf::getType()
{
	if (sex==FEMALE)
	{
		return ISFWOLF;
	}
	return ISMWOLF;
}

void CWolf::pregnancy()
{
	if (!ispregnancy && year>=ADULTYEAR && sex==FEMALE)
	{
		for (int i=-2;i<=2;i++)
		{
			for (int j=-2;j<=2;j++)
			{
				if ((posrow+i)<GRIDROW && (posrow+i)>=0 && (poscol+j)<GRIDCOL && (poscol+j)>=0)
				{
					if (world_llf->getAt(posrow+i,poscol+j)!=ISEMPTY)
					{
						if (world_llf->getAt(posrow+i,poscol+j)->getType()==ISMWOLF)
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
				CWolf *newWolf=new CWolf(world_llf,posrow,poscol-1);
				ispregnancy=false;
				preyear=0;
			}
			else if ((poscol<GRIDCOL-1)&&(world_llf->getAt(posrow,poscol+1)==ISEMPTY))
			{
				CWolf *newWolf=new CWolf(world_llf,posrow,poscol+1);
				ispregnancy=false;
				preyear=0;
			}
			else if ((posrow>0)&&(world_llf->getAt(posrow-1,poscol)==ISEMPTY))
			{
				CWolf *newWolf=new CWolf(world_llf,posrow-1,poscol);
				ispregnancy=false;
				preyear=0;
			}
			else if ((posrow<GRIDROW-1)&&(world_llf->getAt(posrow+1,poscol)==ISEMPTY))
			{
				CWolf *newWolf=new CWolf(world_llf,posrow+1,poscol);
				ispregnancy=false;
				preyear=0;
			}

		}
	}
}

bool CWolf::isdead()
{
	bool fdead=false;
	if (year>=DEADYEAR)
	{
		fdead=true;
	}

	if (feeddegree<=-20)
	{
		fdead=true;
	}
	return fdead;
}

int CWolf::satisfaction(int nrow,int ncol)
{
	int satisfy=0;
	for (int i=-2;i<=2;i++)
	{
		for (int j=-2;j<=2;j++)
		{
			if ((nrow+i)<GRIDROW && (nrow+i>=0) && (ncol+j)<GRIDCOL && (ncol+j>=0))
			{
				if (world_llf->getAt(nrow+i,ncol+j)!=ISEMPTY)
				{
					if (world_llf->getAt(nrow+i,ncol+j)->getType()+world_llf->getAt(posrow,poscol)->getType()==(ISMWOLF+ISFWOLF))
					{
						satisfy=satisfy+15;
					}
					if (world_llf->getAt(nrow+i,ncol+j)->getType()+world_llf->getAt(posrow,poscol)->getType()==(ISMWOLF+ISMWOLF) || world_llf->getAt(nrow+i,ncol+j)->getType()+world_llf->getAt(posrow,poscol)->getType()==(ISFWOLF+ISFWOLF))
					{
						satisfy=satisfy-5;
					}
					if (world_llf->getAt(nrow+i,ncol+j)->getType()==ISFSHEEP || world_llf->getAt(nrow+i,ncol+j)->getType()==ISMSHEEP)
					{
						satisfy=satisfy+20;
					}
				}
				else
				{
					satisfy=satisfy+3;
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