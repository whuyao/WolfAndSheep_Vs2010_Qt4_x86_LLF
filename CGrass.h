#include "global_define.h"

class CGrass
{
	friend class CWorld;
	friend class CSheep;
public:
	CGrass();
	CGrass(CWorld *world,int row,int col);

	bool grassstate();
	void grow();

protected:
	int year;
	bool havegrass;
	int posrow;
	int poscol;

	CWorld *world_llf;
};