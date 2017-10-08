#include "global_define.h"

class CWolf:public Organism
{
	friend class CWorld;
public:
	CWolf();

	CWolf(CWorld *world,int row,int col,int np=2);

	void move();
	void pregnancy();
	int getType();
	bool isdead();    //≈–∂œ¿« «∑ÒÀ¿Õˆ

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
private:
	double prePredation;
};