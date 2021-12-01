#ifndef STON_H
#define STON_H

#include <iostream>


class Stone
{
public:
	Stone(bool,int,int);
public:
	bool getColor();
	int getX();
	int getY();
	bool setX(int);
	bool setY(int);
	void Step(int,int);
	bool find(int,int)const;
	friend std::ostream& operator<<(std::ostream&,const Stone&);
private:
	mutable bool blackOrWhite;
	int x_;
	int y_;
};

#endif /*STON_H*/

