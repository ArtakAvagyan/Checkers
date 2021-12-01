#ifndef CHECKERS_H 
#define CHECKERS_H

#include <iostream>
#include <vector>
#include "Stone.h"

class Checkers
{
public:
	Checkers();
public:
	void Displey()const;
	void Step();
	bool ifWin();
	void setQueue(bool b){Queue = b;}
	bool getQueue(){return Queue;}
private:
	void check(size_t,size_t);
	int find(int,int)const;
	bool validStep(int,size_t,size_t);
private:
	bool Queue;
	std::vector<Stone>stones;
};/*end of Checkers*/

#endif /*CHECKERS_H*/
