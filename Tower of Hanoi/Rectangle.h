#pragma once
#include "enums.h"

class my_Rectangle
{
	int x, y;
	Color color;
	int size;
public:
	void setPos(int x, int y);
	void setColor(Color color);
	void setSize(int size);
	void draw();
	my_Rectangle(int x, int y, int size, Color color);
	my_Rectangle();
	~my_Rectangle();
};

