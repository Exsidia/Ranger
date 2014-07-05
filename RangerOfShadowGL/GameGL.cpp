#include "GameGL.h"
CPlayer player;
Map cMap;
GameGL::GameGL(void)
{
}

GameGL::GameGL(int argc, char **argv)
{
	m_Ctrl = new CControl();
	glutInit(&argc, argv);
	player.setPosX(0);
	player.setPosY(15);
	player.setLook('l');
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
	player.showLook(player.getPosX(), Height-player.getPosY(), (int*)GLUT_BITMAP_9_BY_15);
	cMap.paintMap(0, Height - 15, (int*)GLUT_BITMAP_9_BY_15);
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
}
