#include "CWorld.h"
#include "CGrass.h"
#include "Organism.h"
#include "CSheep.h"
#include "CWolf.h"

Organism* CWorld::getAt(int nrow,int ncol)
{
	if ((nrow>=0 && nrow<GRIDROW) && (ncol>=0 && ncol<GRIDCOL))
	{
		return grid[nrow][ncol];
	}
	return ISEMPTY;
}

bool CWorld::havegrassAt(int nrow,int ncol)
{
	return grass[nrow][ncol]->grassstate();
}

void CWorld::setAt(int nrow,int ncol,Organism* org)
{
	if ((nrow>=0 && nrow<GRIDROW) && (ncol>=0 && ncol<GRIDCOL))
	{
		grid[nrow][ncol]=org;
	}
}

void CWorld::setgrassAt(int nrow,int ncol,CGrass* cgr)
{
	if ((nrow>=0 && nrow<GRIDROW) && (ncol>=0 && ncol<GRIDCOL))
	{
		grass[nrow][ncol]=cgr;
	}
}

void CWorld::SimulateOneStep()
{
	movepace=2;

	for (int i=0;i<GRIDROW;i++)
	{
		for (int j=0;j<GRIDCOL;j++)
		{
			if (grid[i][j]!=ISEMPTY)
			{
				if (grid[i][j]->getType()==ISFSHEEP || grid[i][j]->getType()==ISMSHEEP)
				{
					grid[i][j]->pacenum=1;
				}
				else if (grid[i][j]->getType()==ISFWOLF || grid[i][j]->getType()==ISMWOLF)
				{
					grid[i][j]->pacenum=2;
				}
			}
		}
	}

	for (int i=0;i<GRIDROW;i++)
	{
		for (int j=0;j<GRIDCOL;j++)
		{
			grass[i][j]->grow();
		}
	}

	while(movepace>=0)
	{
		for (int i=0;i<GRIDROW;i++)
		{
			for (int j=0;j<GRIDCOL;j++)
			{
				if ((grid[i][j]!=ISEMPTY) && (grid[i][j]->getType()==ISFWOLF || grid[i][j]->getType()==ISMWOLF))
				{
					if (grid[i][j]->pacenum==2)
					{
						grid[i][j]->pacenum--;
						grid[i][j]->move();
					}
				}
			}
		}

		for (int i=0;i<GRIDROW;i++)
		{
			for (int j=0;j<GRIDCOL;j++)
			{
				if ((grid[i][j]!=ISEMPTY) && (grid[i][j]->getType()==ISFSHEEP || grid[i][j]->getType()==ISMSHEEP))
				{
					if (grid[i][j]->pacenum==1)
					{
						grid[i][j]->pacenum--;
						grid[i][j]->move();
					}
				}
			}
		}

		for (int i=0;i<GRIDROW;i++)
		{
			for (int j=0;j<GRIDCOL;j++)
			{
				if ((grid[i][j]!=ISEMPTY) && (grid[i][j]->getType()==ISFWOLF || grid[i][j]->getType()==ISMWOLF))
				{
					if (grid[i][j]->pacenum==1)
					{
						grid[i][j]->pacenum--;
						grid[i][j]->move();
					}
				}
			}
		}
		movepace--;
	}

	for (int i=0;i<GRIDROW;i++)
	{
		for (int j=0;j<GRIDCOL;j++)
		{
			if (grid[i][j]!=ISEMPTY)
			{
				grid[i][j]->pregnancy();
				grid[i][j]->addYear(1);
			}
		}
	}

	for (int i=0;i<GRIDROW;i++)
	{
		for (int j=0;j<GRIDCOL;j++)
		{
			if (grid[i][j]!=ISEMPTY)
			{
				if (grid[i][j]->isdead())
				{
					grid[i][j]=ISEMPTY;
				}
			}
		}
	}

}

void CWorld::clearWorld()
{
	for (int nr=0;nr<GRIDROW;nr++)
	{
		for (int nc=0;nc<GRIDCOL;nc++)
		{
			grid[nr][nc]=ISEMPTY;
			grass[nr][nc]=ISEMPTY;
		}
	}
}