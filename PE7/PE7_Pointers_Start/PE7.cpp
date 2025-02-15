// PE7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	//Printing the addresses of the boss, player, and fake monster
	cout << "\nBoss address: " << &boss << "\nPlayer address: " << &pOne << "\nFake Monster address: " << &fakeMonster << endl;

	//Setting some values of the positions of the boss, player, and fake monster
	boss->xPos = 10;
	boss->yPos = 15;
	pOne->xPos = 60;
	pOne->yPos = 35;
	fakeMonster->xPos = 100;
	fakeMonster->yPos = 100;

	//Printing the Positions of the boss, player, and fake monster
	cout << "\nPositions of the boss, player, and fake monster" << endl;
	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	delete boss;
	delete pOne;
	//An error was thrown due to 'fakeMonster' acting as a dangling pointer
	// delete fakeMonster;

	//When changing the original boss and player variables, the difference with the player object is
	// that it no longer prints "player dtor" when deleted

	return 0;
}

