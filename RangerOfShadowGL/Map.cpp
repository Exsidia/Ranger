#include "Map.h"

Map::Map(void)
{
}

void Map::Init()
{
	lx = player.getPosX()/9;
	ly = Height - player.getPosY()/15;
	int i = 0;
	for(i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
			arrmap[i][j] = 0;
	for(i = 0; i < w; ++i)
	{
		arrmap[i][0] = 1;
		arrmap[i][h - 1] = 1;
	}
	for(i = 0; i < h; ++i)
	{
		arrmap[0][i] = 1;
		arrmap[w-1][i] = 1;
	}
	arrmap[10][5] = 1;
	arrmap[11][5] = 1;
	arrmap[12][5] = 1;
	arrmap[13][5] = 1;
	arrmap[14][5] = 1;
	arrmap[15][5] = 1;
	arrmap[16][5] = 1;
	arrmap[10][6] = 1;
	arrmap[16][6] = 1;
	arrmap[10][7] = 1;
	arrmap[16][7] = 1;
	arrmap[10][8] = 1;
	arrmap[16][8] = 1;
	arrmap[10][9] = 1;
	arrmap[16][9] = 1;
	arrmap[11][9] = 1;
	arrmap[12][9] = 1;
	arrmap[14][9] = 1;
	arrmap[15][9] = 1;
	arrmap[12][10] = 1;
	arrmap[14][10] = 1;
	FILE *fi;
	fi = fopen("map.data", "r");
	for(int i = 0; i < w; ++i)
	{
		for(int j = 0; j < h; ++j)
		{
			fscanf(fi, "%d ", &arrmap[i][j]);
		}
	}
	fclose(fi);
}
void Map::paintMap(int xx, int yy)
{
	int tx, ty;
	int rx, ry;
	int *font = (int*)GLUT_BITMAP_9_BY_15;
	for(int i = 0; i < Mobs.size(); i++)
	{
		rx = Mobs[i]->getPosX();
		ry = Mobs[i]->getPosY();
		Mobs[i]->setLastX(rx);
		Mobs[i]->setLastY(ry);
		rx = (-xx + rx)/9;
		ry = (yy+ry)/15;
		if(rx >= 0 && ry > 0)
		{
	//		arrmap[lx-1][ly] = 0;
	//		arrmap[rx-1][ry] = -1;
	//		lx = rx;
	//		ly = ry;
		}
	}
	for(int i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
		{
			glColor3f(0.6, 0.6, 0.6);
			tx = xx + i * stepX; ty = yy - j * stepY;
			if(tx != startX || ty != startY )
			{
				//arrmap[lx][ly] = 0;
				switch(arrmap[i][j])
				{
				case 0: glRasterPos2f(tx, ty);
						glutBitmapCharacter(font, (int)'.'); break;
				case 1: glRasterPos2f(tx, ty);
						glutBitmapCharacter(font, (int)'#'); break;
				case 2: glColor3f(0, 0.5, 1);
						glRasterPos2f(tx, ty);
						glutBitmapCharacter(font, (int)'='); break;
				case -1: glRasterPos2f(tx, ty);
						glutBitmapCharacter(font, (int)' '); break;
				case -2: glRasterPos2f(tx, ty);
						glutBitmapCharacter(font, (int)' '); break;
				default: break;
				}
			}
			else
			{
				cout << "You're here: " << i << " " << j << endl;
			}
		}
}
void Map::setMap(int xx, int yy, int l)
{
	int i, j;
	i = xx/9;
	j = yy/15;
	j = j - 1;
	lx = arrmap[i][j];
	arrmap[i][j] = l;
}
int Map::getTypeMap(int xx, int yy)
{
	int i, j;
	i = xx/9;
	j = yy/15;
	j = j - 1;
	return lx;
}
int Map::getNext(int xx, int yy, int dir) const
{
	int i, j;
	i = xx/9;
	j = yy/15;
	switch(dir)
	{
	//верх(север)
	case 0: return arrmap[i][j - 2];
	//низ(юг)
	case 1: return arrmap[i][j];
	//лево(запад)
	case 2: return arrmap[i - 1][j - 1];
	//право(восток)
	case 3: return arrmap[i + 1][j - 1];
	//северо-запад
	case 4: return arrmap[i - 1][j - 2];
	//северо-восток
	case 5: return arrmap[i + 1][j - 2];
	//юго-запад
	case 6: return arrmap[i - 1][j];
	//юго-восток
	case 7: return arrmap[i + 1][j];
	default: return arrmap[i][j - 1];
	}
	return arrmap[i][j - 1];
}
Map::~Map(void)
{
}
