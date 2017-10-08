#include "global_define.h"

class Organism
{
	friend class CWorld;
	public:
		Organism();
		Organism(CWorld *world,int row,int col,int np);
		~Organism(){}

		virtual void move(){}
		virtual void pregnancy(){}
		virtual int getType(){return 0;}
		virtual bool isdead(){return 0;}
		virtual void addPos(int,int){}
		virtual void addYear(int){}

	protected:
		int year;
		int feeddegree;
		int sex;
		bool ispregnancy;
		int preyear;
		int pacenum;
		int posrow;
		int poscol;

		CWorld *world_llf;
};