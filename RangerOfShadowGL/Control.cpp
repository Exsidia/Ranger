#include "Control.h"


CControl::CControl(void)
{
}

void CControl::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '\033': exit(0);
	}
	glutPostRedisplay();
}

void CControl::SpecKeyboard(int key, int x, int y)
{
	if(key == GLUT_KEY_DOWN || key == GLUT_KEY_UP || key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT)
	{
		CPlayer *temp = new CPlayer(player);
		temp->controlPlayer(key);
		player.setPosX(temp->getPosX());
		player.setPosY(temp->getPosY());
		temp->~CPlayer();
		glutPostRedisplay();
	}
	cout << player.getPosX() << endl;
	cout << player.getPosY() << endl;
	cout << Mobs[0]->getPosX() - startX << endl;
	cout << Mobs[0]->getPosY() - startY<< endl;
}

CControl::~CControl(void)
{
}
