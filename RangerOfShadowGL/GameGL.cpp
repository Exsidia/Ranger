#include "GameGL.h"
CPlayer player;
vector<CCharacter*> Mobs;
CRat *cRat = new CRat();
GameGL::GameGL(void)
{
}

GameGL::GameGL(int argc, char **argv)
{
	m_Ctrl = new CControl();
	glutInit(&argc, argv);
	player.setPosX(startX);
	player.setPosY(startY);
	player.setLook('@');
	CRat *cRat = new CRat();
	cRat->setLook('r');
	cRat->setPosX(180);
	cRat->setPosY(195);
	CRat *cRat2 = new CRat();
	cRat2->setLook('r');
	cRat2->setPosX(36);
	cRat2->setPosY(105);
	Mobs.push_back(cRat);
	Mobs.push_back(cRat2);
	cMap.Init();
}

void GameGL::Initialize(GLint w, GLint h)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("Ranger of Shadows");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(m_Ctrl->Keyboard);
	glutSpecialFunc(m_Ctrl->SpecKeyboard);
	glutMainLoop();
}

void GameGL::Display()
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

void GameGL::Reshape(GLint w, GLint h)
{
	Width = w; Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
GameGL::~GameGL(void)
{
	player.~CPlayer();
	cMap.~Map();
}
