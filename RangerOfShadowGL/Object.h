#pragma once
#include "Map.h"

class Object
{
private:
	string name;
public:
	Object(void);
	string getName() const { return name; }
	void setName(string yname){name = yname;}
	~Object(void);
};

class CCharacter: public Object
{
private:
	int x, y;
	char look;
public:
	int getPosX() const { return x; }
	int getPosY() const { return y; }
	void setPosX(int xx){ x = xx; }
	void setPosY(int yy){ y = yy; }
	CCharacter(){};
	CCharacter(char l){look = l;}
	void setLook(char l){look = l;}
	char getLook() const { return look; }
	void showLook(int x, int y, int *font);
	CCharacter(int xx, int yy){ x = xx; y = yy; }
	~CCharacter(){};
};

class CPlayer: public CCharacter
{
public:
	void controlPlayer(int key);
	CPlayer(){ setName("Player"); };
	CPlayer(const CPlayer & CP);
	~CPlayer(){};
};
extern CPlayer player;