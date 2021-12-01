#include "Stone.h"

Stone::Stone(bool b,int x, int y):blackOrWhite(b)
{
	x_ = x;
	y_ = y;
}


bool Stone::getColor(){return blackOrWhite;}
int Stone::getX(){return x_;}
int Stone::getY(){return y_;}
bool Stone::setX(int x)
{
	x_ = x;
	return true;
}
bool Stone::setY(int y)
{
	y_ = y;
	return true;
}

void Stone::Step(int x , int y)
{
	x_ = x;
	y_ = y;
}
std::ostream& operator<<(std::ostream& os,const Stone& other)
{
	if(other.blackOrWhite)
	{
		os << '#';
	}
	else
	{
		os << '*';
	}
	return os;
}
bool Stone::find(int x,int y)const
{
	if(x == x_ && y == y_){return true;}
	return false;
}
