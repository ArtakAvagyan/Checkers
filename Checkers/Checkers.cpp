#include "Checkers.h"

Checkers::Checkers()
{
	stones.reserve(24);
	for(int i = 0 ; i < 3 ; ++i)
	{
		for(int j = i%2 ; j < 8 ; j+=2)
		{
			stones.push_back(Stone(true,i,j));
		}
	}
	for(int i = 5 ; i < 8 ; ++i)
	{
		for(int j = i%2 ; j < 8 ; j+=2)
		{
			stones.push_back(Stone(false,i,j));
		}
	}
	Queue = true;
}
void Checkers::Displey()const
{
	std::system("clear");
	for(int i = 0 ; i < 8 ;++i)
		std::cout<<"  "<<i ;
	std::cout<<std::endl;
	for(int i = 0 ; i < 8;++i)
	{
		std::cout<< i ;
		for(int j = 0 ; j < 8 ; ++j)
		{
			std::cout<< '|' ;
			int k =this->find(i,j);
			if(k  == -1){std::cout<< ' ';}
			else{std::cout<< stones[k];}
			
		}
		std::cout<< '|'<< std::endl;
	}
}

int Checkers::find(int x , int y)const 
{
	for(int i = 0 ; i < stones.size();++i)
	{
		if(stones[i].find(x,y))
		{
			return i;
		}	
	}
	return -1;
}
void Checkers::Step()
{
	int tmp;
	int x,y,z,k;
	do{
		std::cout<< (Queue?"White":"Black") ;
		std::cout<< "Plise enter x & y and new x & y" <<std::endl;
		std::cin>> x >> y >> z >> k ;
		tmp = find(x,y);
	}while(tmp == -1 || stones[tmp].getColor() == Queue || !validStep(tmp,z,k));
	if((x-1 == z && y+1 == k )||(x+1 == z && y-1 == k )||(x+1 == z && y+1 == k )||(x-1 == z && y-1 == k ))
	{
		stones[tmp].setX(z);
		stones[tmp].setY(k);
	//	Queue = !Queue;
	}
	else
	{
		int c = z - x;
		int g = k - y;
		int d = find((x + c/2),(y + g/2));
		if(-1 == d){Step();return;}
		if(stones[d].getColor() ==  stones[tmp].getColor()){return;}
		stones.erase(stones.begin()+d);
		tmp = find(x,y);
		stones[tmp].setX(z);
		stones[tmp].setY(k);
		Displey();
		check(z,k);
	//	Queue = !Queue;

	}
}
void Checkers::check(size_t x,size_t y)
{
	int tmp[4];
	tmp[0] = find(x+1,y+1);
	tmp[1] = find(x-1,y-1);
	tmp[2] = find(x+1,y-1);
	tmp[2] = find(x-1,y+1);
	if(tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3]&& tmp[3] == -1){return;}
	if(tmp[0]!= -1)
	{
		int k[2];
		k[0] = find(x+2,y+2);
		k[1] = find(x-2,y+2);
		if(k[0]== -1 && stones[k[0]].getColor() != Queue){Step();}
		else if(k[1]== -1 && stones[k[1]].getColor() != Queue){Step();}
		Queue = !Queue;
		return;
	}
	else if(tmp[1]!= -1)
	{
		int k[2];
		k[0] = find(x-2,y-2);
		k[1] = find(x+2,y-2);
		if(k[0]== -1 && stones[k[0]].getColor() != Queue){Step();}
		else if(k[1]== -1 && stones[k[1]].getColor() != Queue){Step();}
		Queue = !Queue;
		return;
	}
	else if(tmp[2]!= -1)
	{
		int k[2];
		k[0] = find(x-2,y+2);
		k[1] = find(x+2,y-2);
		if(k[0]== -1 && stones[k[0]].getColor() != Queue){Step();}
		else if(k[1]== -1 && stones[k[1]].getColor() != Queue){Step();}
		Queue = !Queue;
		return;
	}
	else if(tmp[3]!= -1)
	{
		int k[2];
		k[0] = find(x+2,y-2);
		k[1] = find(x-2,y+2);
		if(k[0]== -1 && stones[k[0]].getColor() != Queue){Step();}
		else if(k[1]== -1 && stones[k[1]].getColor() != Queue){Step();}
		Queue = !Queue;
		return;
	}
}
bool Checkers::ifWin()
{
	bool Black = false;
	bool White = false;
	for(int i = 0 ; i < stones.size();++i)
	{
		if(stones[i].getColor()){White = true;}
		else{Black = true;}
	}
	if(Black && White){return true;}
	return false;
}

bool Checkers::validStep(int pos,size_t x,size_t y)
{
	int x_ = stones[pos].getX();
	int y_ = stones[pos].getY();
	int count = 0;
	while(x_ < 8 && y_ < 8 && count < 4)
	{
		x_++;y_++;count++;
		if(x_ == x && y_ == y){return true;}
	}
	x_ = stones[pos].getX();
	y_ = stones[pos].getY();
	count = 0;
	while(x_ < 8 && y_ < 8 && count < 4)
	{
		x_--;y_--;count++;
		if(x_ == x && y_ == y){return true;}
	}
	x_ = stones[pos].getX();
	y_ = stones[pos].getY();
	count = 0;
	while(x_ < 8 && y_ < 8 && count < 4)
	{
		x_++;y_--;count++;
		if(x_ == x && y_ == y){return true;}
	}
	x_ = stones[pos].getX();
	y_ = stones[pos].getY();
	count = 0;
	while(x_ < 8 && y_ < 8 && count < 4)
	{
		x_--;y_++;count++;
		if(x_ == x && y_ == y){return true;}
	}
	return false;
}
int main()
{
	Checkers chek;
	while(chek.ifWin())
	{
	chek.Displey();
	chek.Step();
	chek.setQueue(!chek.getQueue());
	}
}
