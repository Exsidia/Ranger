#include "GameGL.h"
CPlayer player;
vector<CCharacter*> Mobs;
//CRat *cRat = new CRat();
GameGL::GameGL(void)
{
}

GameGL::GameGL(int argc, char **argv)
{
	//m_Ctrl = new CControl();
	menu = new CMenu();
	glutInit(&argc, argv);
}

void GameGL::Initialize(GLint w, GLint h)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("Ranger of Shadows");
	glutDisplayFunc(menu->Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(menu->Keyboard);
	glutSpecialFunc(menu->SpecKeyboard);
	glutMainLoop();
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
	for(int i = 0; i < Mobs.size(); ++i)
		delete Mobs[i];
	cMap.~Map();
}
