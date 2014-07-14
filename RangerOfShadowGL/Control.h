#pragma once
#include "Object.h"

class CControl
{
public:
	CControl(void);
	static void Keyboard(unsigned char key, int x, int y);
	static void SpecKeyboard(int key, int x, int y);
	static void Display();
	~CControl(void);
};

class CMenu
{
public:
	CMenu(){}
	static void Keyboard(unsigned char key, int x, int y);
	static void SpecKeyboard(int key, int x, int y);
	static void Display();
	~CMenu(){}
};