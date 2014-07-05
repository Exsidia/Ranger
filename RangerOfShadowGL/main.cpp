#include "GameGL.h"
GLint Height = 300;
GLint Width = 640;
void main(int argc, char** argv)
{
	GameGL *game = new GameGL(argc, argv);
	game->Initialize(Width, Height);
	glutMainLoop();
	delete game;
}