#pragma once
#include "AIBehavior.h"
#include "Object.h"
class Map
{
private:
	static const int size = 1200;
	static const int w = 71;
	static const int h = 20;
	char arrmap[w][h];
	int lx, ly;
	int clr;
public:
	Map(void);
	void Init();
	void paintMap(int xx, int yy);
	int getNext(int xx, int yy, int dir) const;
	void setMap(int xx, int yy, int l);
	int getTypeMap(int xx, int yy);
	~Map(void);
};
extern Map cMap;

