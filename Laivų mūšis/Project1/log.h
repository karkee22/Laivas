#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;


int y, x2, y2;
char x;
bool gameover;
enum eDirection { LEFT, RIGHT, UP, DOWN };
eDirection dir;
void input()
{
	switch (_getch())
	{
	case 'a':
		dir = LEFT;
		break;
	case 'd':
		dir = RIGHT;
		break;
	case 'w':
		dir = UP;
		break;
	case 's':
		dir = DOWN;
		break;
	}
}

void put()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
}