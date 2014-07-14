#include "Control.h"

void glWrite(int x, int y, char *text, int size);
int xx = 0;
int yy = 0;
CControl::CControl(void)
{
}

void CControl::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '\033': for(int i = 0; i < Mobs.size(); ++i) delete Mobs[i]; exit(0);
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

void CControl::Display()
{
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
	player.showLook(startX, Height-startY);
	glColor3f(1,1,0);
	for(int i = 0; i < Mobs.size(); ++i)
		Mobs[i]->showLook(Mobs[i]->getPosX(), Height - Mobs[i]->getPosY());
	glColor3f(1,1,1);
	cMap.paintMap(startX - player.getPosX(), Height - startY + player.getPosY() - 15);
	glutSwapBuffers();
}

CControl::~CControl(void)
{
}


void CMenu::Display()
{
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex2f(startX + xx - 67, Height - startY + yy + 26);
	glVertex2f(startX + xx - 67, Height - startY + yy + 45);
	glVertex2f(startX + xx + 85, Height - startY + yy + 45);
	glVertex2f(startX + xx + 85, Height - startY + yy + 26);
	glEnd();
	glColor3f(0.7, 0, 0);
	glWrite(startX-63, Height - startY + 30, "Start a New Game", sizeof("Start a New Game"));
	glWrite(startX - 9, Height - startY + 10, "Exit", sizeof("Exit"));
	glutSwapBuffers();
}

void CMenu::SpecKeyboard(int key, int x, int y)
{
	//очень грубо и криво сделано :)
	if(key == GLUT_KEY_DOWN)
	{
		yy = - 20;
	}
	if(key == GLUT_KEY_UP)
	{
		yy = 0;
	}
	glutPostRedisplay();
}

void CMenu::Keyboard(unsigned char key, int x, int y)
{
	if(key == VK_RETURN)
	{
		if(yy == -20)
			exit(0);
		if(yy == 0)
		{
			CControl *ctrl = new CControl();
			player.setPosX(startX);
			player.setPosY(startY);
			player.setLook('@');
			CRat *cRat = new CRat('r', 306, 135);
			CSimpleAI *sAI = new CSimpleAI();
			//cRat->setLook('r');
			cRat->setAI(sAI);
			//cRat->setPosX(180);
			//cRat->setPosY(195);
			CRat *cRat2 = new CRat('r', 9, 30);
		//	cRat2->setLook('r');
			//cRat2->setPosX(9);
		//	cRat2->setPosY(105);
			cRat2->setAI(sAI);
			CWeaponBehavior *cClaw = new CClawWeapon();
			cRat2->setWeapon(cClaw);
			Mobs.push_back(cRat);
			Mobs.push_back(cRat2);
			cMap.Init();
			glutDisplayFunc(ctrl->Display);
			glutKeyboardFunc(ctrl->Keyboard);
			glutSpecialFunc(ctrl->SpecKeyboard);
		}
	}
	glutPostRedisplay();
}
void glWrite(int x, int y, char *text, int size)
{
	glRasterPos2f(x, y);
	for(int i = 0; i < size; ++i)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
}