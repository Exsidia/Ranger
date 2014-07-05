#include "Object.h"

Object::Object(void)
{
}

Object::~Object(void)
{
}

void CCharacter::showLook(int xx, int yy, int *font)
{
    glRasterPos2f(xx, yy);
    glutBitmapCharacter(font, (int)look);
}

void CPlayer::controlPlayer(int key)
{
	switch(key)
	{
		case GLUT_KEY_UP: setPosY(getPosY()-stepY); break;
		case GLUT_KEY_DOWN: setPosY(getPosY()+stepY); break;
		case GLUT_KEY_LEFT: setPosX(getPosX()-stepX); break;
		case GLUT_KEY_RIGHT: setPosX(getPosX()+stepX); break;
	}
}

CPlayer::CPlayer(const CPlayer & CP)
{
	setPosX(CP.getPosX());
	setPosY(CP.getPosY());
	setLook(CP.getLook());
}