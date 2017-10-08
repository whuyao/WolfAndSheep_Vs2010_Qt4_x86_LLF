#include "global_define.h"

class CWorld
{
	friend class Organism;
	friend class CGrass;
	friend class CSheep;
	friend class CWolf;
public:
	CWorld()
	{
		for (int i=0;i<GRIDROW;i++)
		{
			for (int j=0;j<GRIDCOL;j++)
			{
				grid[i][j]=ISEMPTY;
				grass[i][j]=ISEMPTY;
			}
		}
		movepace=10;
	}
	~CWorld()
	{
		for (int i=0;i<GRIDROW;i++)
		{
			for (int j=0;j<GRIDCOL;j++)
			{
				if (grid[i][j]!=ISEMPTY) delete (grid[i][j]);
			}
		}
	}

	Organism* getAt(int nrow,int ncol);
	bool havegrassAt(int nrow,int ncol);

	void setAt(int nrow,int ncol,Organism* org);
	void setgrassAt(int nrow,int ncol,CGrass* cgr);

	void clearWorld();


	void SimulateOneStep();
private:
	//bool havegrass[GRIDROW][GRIDCOL];
	CGrass* grass[GRIDROW][GRIDCOL];
	Organism* grid[GRIDROW][GRIDCOL];
	int movepace;


};