#include "Map.h"


Map::Map(void)
{
}

void Map::Init()
{
	for(int i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
			arrmap[i][j] = 0;
	arrmap[10][5] = 1;
}
void Map::paintMap(int xx, int yy, int *font)
{
	for(int i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
		{
			glRasterPos2f(xx + i*stepX, yy - j * stepY);
			if(arrmap[i][j] == 0)
				glutBitmapCharacter(font, (int)'.');
			if(arrmap[i][j] == 1)
				glutBitmapCharacter(font, (int)'#');
		}
}
Map::~Map(void)
{
}
