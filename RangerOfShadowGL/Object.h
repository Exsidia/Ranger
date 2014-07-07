#pragma once
#include "Map.h"
class CWeaponBehavior;
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
	int x, y, xpr, ypr;
	char look;
public:
	CWeaponBehavior *w;
	int getPosX() const { return x; }
	int getPosY() const { return y; }
	int getLastX() const { return x; }
	int getLastY() const {return y; }
	void setPosX(int xx){ x = xx; }
	void setPosY(int yy){ y = yy; }
	void setLastX(int xx){ xpr = xx; }
	void setLastY(int yy){ ypr = yy; }
	void setWeapon(CWeaponBehavior *weap){ this->w = weap; }
	CCharacter(){};
	CCharacter(char l){look = l;}
	void setLook(char l){look = l;}
	char getLook() const { return look; }
	void showLook(int x, int y);
	void attack();
	CCharacter(int xx, int yy){ x = xx; y = yy; }
	~CCharacter(){};
};

class CWeaponBehavior
{
public:
	virtual void useWeapon() = 0;
};

class CSwordBehavior: public CWeaponBehavior
{
public:
	void useWeapon(){};
};

class CNothingWeapon: public CWeaponBehavior
{
public:
	void useWeapon(){};
};

class CClawWeapon: public CWeaponBehavior
{
public:
	void useWeapon(){}
};

class CPlayer: public CCharacter
{
public:
	void controlPlayer(int key);
	CPlayer(){ setName("Player"); };
	CPlayer(const CPlayer & CP);
	void attack(){w->useWeapon();}
	~CPlayer(){};
};
extern CPlayer player;


//монстры

class CRat: public CCharacter
{
public:
	CRat(){ setName("Rat");}
	void attack(){w->useWeapon();}
};
extern vector<CCharacter*> Mobs;