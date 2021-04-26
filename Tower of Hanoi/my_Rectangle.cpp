#include "my_Rectangle.h"
#include "freeLibrary.h"
#include <iomanip>


void my_Rectangle::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void my_Rectangle::setColor(int color)
{
	this->color = color;
}

void my_Rectangle::setSize(int size)
{
	this->size = size;
}

int my_Rectangle::getX()
{
	return x;
}

int my_Rectangle::getY()
{
	return y;
}

void my_Rectangle::clean()
{
	gotoxy(x, y);
	
	cout << string(size, ' ');
	
}

void my_Rectangle::draw()
{
	gotoxy(x, y);
	SetColor(color);
	cout << string(size, char(219));
	SetColor(DARKGRAY);
}

my_Rectangle::my_Rectangle(int x, int y, int size, int color)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->color = color;
}

my_Rectangle::my_Rectangle()
{
}


my_Rectangle::~my_Rectangle()
{
}
