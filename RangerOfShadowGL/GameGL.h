#pragma once
#include "Control.h"
class GameGL
{
private:
	CControl *m_Ctrl;
public:
	GameGL(void);
	GameGL(int argc, char **argv);
	void Initialize(GLint w, GLint h);
	static void Display();
	static void Reshape(GLint w, GLint h);
	~GameGL(void);
};
