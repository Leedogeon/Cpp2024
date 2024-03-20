#pragma once
#include "Enum.h";
using namespace Enum;
class Player
{
public:
	int level;
	int maxHp;
	int maxMp;
	int x;
	int y;
	int atk;
	const char* shape[3];
	COLOR color;
	int hp;
	int mp;
	//Text text;
	PlayerType playerType;
	bool act;
	bool critical;

};

class Weapon : public Player
{
public:
	int x;
	int y;
	const char* shape[4];
	COLOR color;
	const char* Text;
};

class Skill : public Player
{
public:
	int x;
	int y;
	const char* shape;
	COLOR textColor;
	COLOR color;
	const char* Text;
	bool act;
};


