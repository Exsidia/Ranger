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
	int x, y, xpr, ypr, sz;
	char look;
	int *miniMap;
public:
	CWeaponBehavior *w;
	CAIBehavior *ai;
	int getPosX() const { return x; }
	int getPosY() const { return y; }
	int getLastX() const { return xpr; }
	int getLastY() const {return ypr; }
	int getSMap() const { return sz; }
	int* getMiniMap() const { return miniMap; }
	void setMiniMap(int,int);
	void setPosX(int xx){ x = xx; }
	void setPosY(int yy){ y = yy; }
	void setLastX(int xx){ xpr = xx; }
	void setLastY(int yy){ ypr = yy; }
	void setWeapon(CWeaponBehavior *weap){ this->w = weap; }
	void setAI(CAIBehavior *ai) { this->ai = ai; }
	CCharacter(){sz = 8; miniMap = new int[sz];};
	CCharacter(char l, int xx, int yy){look = l; xpr = xx; ypr = yy; setPosX(xx); setPosY(yy); }
	void setLook(char l){look = l;}
	char getLook() const { return look; }
	void showLook(int x, int y);
	virtual void attack() = 0;
	virtual void move() = 0;
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
	void move(){}
	~CPlayer(){};
};
extern CPlayer player;


//монстры

class CRat: public CCharacter
{
public:
	CRat(){ setName("Rat");}
	CRat(char l, int xx, int yy){setLook(l); setLastX(xx); setLastY(yy); setPosX(xx); setPosY(yy); }
	void attack(){w->useWeapon();}
	void move(){
		int aim = ai->useMind(getMiniMap(), getSMap(), getPosX(), getPosY());
		switch (aim)
		{
		case 0: setPosX(getPosX() - stepX); setPosY(getPosY() - stepY); break;
		case 1: setPosY(getPosY() - stepY); break;
		case 2: setPosX(getPosX() + stepX); setPosY(getPosY() - stepY); break;
		case 3: setPosX(getPosX() + stepX); break;
		case 4: setPosX(getPosX() + stepX); setPosY(getPosY() + stepY); break;
		case 5: setPosY(getPosY() + stepY); break;
		case 6: setPosX(getPosX() - stepX); setPosY(getPosY() + stepY); break;
		case 7: setPosX(getPosX() - stepX); break;
		default:
			break;
		}
	}
};
extern vector<CCharacter*> Mobs;