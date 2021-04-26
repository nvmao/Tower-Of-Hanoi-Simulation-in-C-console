#pragma once
#include "enums.h"

class my_Rectangle
{
	int x, y;
	int color;
	int size;
public:
	int get_size()
	{
		return size;
	}
	void setPos(int x, int y);
	void setColor(int color);
	void setSize(int size);
	int getX();
	int getY();
	void clean();
	void draw();
	my_Rectangle(int x, int y, int size, int color);
	my_Rectangle();
	~my_Rectangle();
};

