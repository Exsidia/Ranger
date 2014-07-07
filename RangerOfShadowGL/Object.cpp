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

void changeAll(int xx, int yy)
{
	
	for(int i = 0; i < Mobs.size(); ++i)
	{
		Mobs[i]->setLastX(Mobs[i]->getPosX());
		Mobs[i]->setLastY(Mobs[i]->getPosY());
		Mobs[i]->setPosX(Mobs[i]->getPosX() + xx);
		Mobs[i]->setPosY(Mobs[i]->getPosY() + yy);
	}
}
void CPlayer::controlPlayer(int key)
{
	int xt = getPosX();
	int yt = getPosY();
	setLastX(xt);
	setLastY(yt);
	switch(key)
	{
	case GLUT_KEY_UP: if(cMap.getNext(xt, yt, 0) != 1){ setPosY(yt-stepY); changeAll(0, stepY);}break;
	case GLUT_KEY_DOWN: if(cMap.getNext(xt, yt, 1) != 1){ setPosY(yt+stepY); changeAll(0, -stepY);}break;
	case GLUT_KEY_LEFT: if(cMap.getNext(xt, yt, 2) != 1){ setPosX(xt-stepX); changeAll(stepX, 0); }break;
	case GLUT_KEY_RIGHT: if(cMap.getNext(xt, yt, 3) != 1){ setPosX(xt+stepX); changeAll(-stepX, 0);}break;
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