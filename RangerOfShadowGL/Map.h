#pragma once
#include "headers.h"
class Map
{
private:
	static const int size = 1200;
	static const int w = 72;
	static const int h = 30;
	char arrmap[w][h];
public:
	Map(void);
	void Init();
	void paintMap(int xx, int yy, int *font);
	~Map(void);
};
extern Map cMap;

