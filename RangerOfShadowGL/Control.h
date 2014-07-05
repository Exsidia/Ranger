#pragma once
#include "Object.h"
class CControl
{
public:
	CControl(void);
	static void Keyboard(unsigned char key, int x, int y);
	static void SpecKeyboard(int key, int x, int y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	~CControl(void);
};

