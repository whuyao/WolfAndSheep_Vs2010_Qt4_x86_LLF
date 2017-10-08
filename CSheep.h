#include "global_define.h"

class CSheep:public Organism
{
	friend class CWorld;
	friend class CGrass;
public:
	CSheep(){}

	CSheep(CWorld *world,int row,int col,int np=1);

	void addPos(int tx,int ty)
	{
		posrow=posrow+tx;
		poscol=poscol+ty;
	}

	void addYear(int ty)
	{
		year=year+ty;
	}

	int satisfaction(int nrow,int ncol);

	void move();
	void pregnancy();
	int getType();
	bool isdead();    //≈–∂œ—Ú «∑ÒÀ¿Õˆ
private:
};