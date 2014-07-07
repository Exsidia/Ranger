#pragma once
#include "headers.h"
#include "Object.h"
class Map
{
private:
	static const int size = 1200;
	static const int w = 71;
	static const int h = 20;
	char arrmap[w][h];
	int lx, ly;
public:
	Map(void);
	void Init();
	void paintMap(int xx, int yy);
	int getNext(int xx, int yy, int dir) const;
	~Map(void);
};
extern Map cMap;

