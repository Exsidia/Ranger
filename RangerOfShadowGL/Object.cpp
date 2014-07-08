#include "Object.h"
Map cMap;
Object::Object(void)
{
}

Object::~Object(void)
{
}

void CCharacter::showLook(int xx, int yy)
{
    glRasterPos2f(xx, yy);
    glutBitmapCharacter((int*)GLUT_BITMAP_9_BY_15, (int)look);
}

void CCharacter::setMiniMap(int tx, int ty)
{
	int xt = getPosX();
	int yt = getPosY();
	int xtt = startX - tx;
	int ytt = - startY + ty;
	miniMap[0] = cMap.getNext(xt-xtt, yt+ytt, 4);
	miniMap[1] = cMap.getNext(xt-xtt, yt+ytt, 0);
	miniMap[2] = cMap.getNext(xt-xtt, yt+ytt, 5);
	miniMap[3] = cMap.getNext(xt-xtt, yt+ytt, 3);
	miniMap[4] = cMap.getNext(xt-xtt, yt+ytt, 7);
	miniMap[5] = cMap.getNext(xt-xtt, yt+ytt, 1);
	miniMap[6] = cMap.getNext(xt-xtt, yt+ytt, 6);
	miniMap[7] = cMap.getNext(xt-xtt, yt+ytt, 2);
}
void changeAll(int xx, int yy, int tx, int ty)
{
	int xt, yt;
	for(int i = 0; i < Mobs.size(); ++i)
	{
		Mobs[i]->setPosX(Mobs[i]->getPosX() + xx);
		Mobs[i]->setPosY(Mobs[i]->getPosY() + yy);
		cMap.setMap(Mobs[i]->getPosX()-startX+tx, Mobs[i]->getPosY()-startY+ty, 0);
		Mobs[i]->setMiniMap(tx, ty);
		Mobs[i]->move();
		cMap.setMap(Mobs[i]->getPosX()-startX+tx, Mobs[i]->getPosY()-startY+ty, -2);
	}
}

//если встретился монстр на будущей клетке, то начнём переговоры :D
int getBattle(int dir)
{
	for(int i = 0; i < Mobs.size(); ++i)
	{
		switch(dir)
		{
		//верх
		case 0:
			if((Mobs[i]->getPosX() - startX) == 0 && (Mobs[i]->getPosY() - startY) == -15)
			{
				return 1;
			}
			break;
		case 1:
			if((Mobs[i]->getPosX() - startX) == 0 && (Mobs[i]->getPosY() - startY) == 15)
			{
				return 1;
			}
			break;
		case 2:
			if((Mobs[i]->getPosX() - startX) == -9 && (Mobs[i]->getPosY() - startY) == 0)
			{
				return 1;
			}
			break;
		case 3:
			if((Mobs[i]->getPosX() - startX) == 9 && (Mobs[i]->getPosY() - startY) == 0)
			{
				return 1;
			}
			break;
		}
	}
	return 0;
}
void CPlayer::controlPlayer(int key)
{
	int xt = getPosX();
	int yt = getPosY();
	setLastX(xt);
	setLastY(yt);
	int flag = 0;
	cMap.setMap(xt, yt, cMap.getTypeMap(xt, yt));
	switch(key)
	{
	case GLUT_KEY_UP: if(cMap.getNext(xt, yt, 0) != 1 && getBattle(0) != 1)
					  { 
						  setPosY(yt-stepY);
						  cMap.setMap(xt, yt-stepY, -1);
						  changeAll(0, stepY, getPosX(), getPosY()); flag = 1;
					  }break;
	case GLUT_KEY_DOWN: if(cMap.getNext(xt, yt, 1) != 1 && getBattle(1) != 1)
						{ 
							setPosY(yt+stepY); 
							cMap.setMap(xt, yt+stepY, -1);
							changeAll(0, -stepY, getPosX(), getPosY());flag = 1;
						}break;
	case GLUT_KEY_LEFT: if(cMap.getNext(xt, yt, 2) != 1 && getBattle(2) != 1)
						{ 
							setPosX(xt-stepX); 
							cMap.setMap(xt-stepX, yt, -1);
							changeAll(stepX, 0, getPosX(), getPosY()); flag = 1;
						}break;
	case GLUT_KEY_RIGHT: if(cMap.getNext(xt, yt, 3) != 1 && getBattle(3) != 1)
						 { 
							 setPosX(xt+stepX); 
							 cMap.setMap(xt+stepX, yt, -1);
							 changeAll(-stepX, 0, getPosX(), getPosY());flag = 1;
						 }break;
	}
	if(!flag)
	{
		cMap.setMap(xt, yt, -1);
		changeAll(0,0, xt, yt);
	}
}

CPlayer::CPlayer(const CPlayer & CP)
{
	setPosX(CP.getPosX());
	setPosY(CP.getPosY());
	setLastX(CP.getLastX());
	setLastY(CP.getLastY());
	setLook(CP.getLook());
}