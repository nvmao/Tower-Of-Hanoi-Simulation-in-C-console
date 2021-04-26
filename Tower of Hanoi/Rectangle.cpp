#include "my_Rectangle.h"
#include "freeLibrary.h"
#include <iomanip>


void my_Rectangle::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void my_Rectangle::setColor(Color color)
{
	this->color = color;
}

void my_Rectangle::setSize(int size)
{
	this->size = size;
}

void my_Rectangle::draw()
{
	gotoxy(x, y);
	cout << setw(size) << char(209);
}

my_Rectangle::my_Rectangle(int x, int y, int size, Color color)
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
