#include "FreeLibrary.h"
#include "my_Rectangle.h"
#include <vector>

class Pos
{
public:
	int height = 0;
	int x;
	Pos(){}
	Pos(int x,int height)
	{
		this->x = x;
		this->height = height;
	}
	void up()
	{
		height++;
	}
	void down()
	{
		height--;
	}
};
//

class Tower
{
	int size ;

	vector<my_Rectangle*> tower;
	my_Rectangle* rectangles;
	my_Rectangle *origin_Posision_rec;
	int height = 3;
	Pos a;
	Pos b;
	Pos c;
	int sleep_time = 10;
public:

	int get_sleep_time() const
	{
		return sleep_time;
	}

	void set_sleep_time(int sleep_time)
	{
		this->sleep_time = sleep_time;
	}
	int get_size() { return size; }
	Tower(int size)
	{
		this->size = size;
		rectangles = new my_Rectangle[size];
		origin_Posision_rec = new my_Rectangle[size];

		 a = Pos(10, size);
		 b = Pos(50, 0);
		 c = Pos(90, 0);
		int y = 5;
		int x = size;
		int rectangele_size = 3;
		int color = 1;
		for(int i = 0 ;i <= size;i++)
		{
			rectangles[i] = my_Rectangle(x + a.x, y, rectangele_size, color);
			color++;
			x--;
			y++;
			rectangele_size += 2;
		}

		for(int i = 0 ; i < size;i++)
		{
			origin_Posision_rec[i] = rectangles[i];
		}

		draw_a_b_c();
	}

	void move(int n, Pos& p1, Pos& p2)
	{

		p1.height--;
		n = n - 1;
		rectangles[n].clean();
		rectangles[n].setPos(rectangles[n].getX() - p1.x + p2.x, origin_Posision_rec[size - 1 - p2.height].getY());

		p2.height++;

	}
	
	void tower_of_hanoi(int n,Pos &from, Pos &to, Pos &aux)
	{
		if(n == 1)
		{
			move(1,from, to);
			draw();
			Sleep(sleep_time);
			return;
		}
		tower_of_hanoi(n - 1, from, aux, to);
		move(n, from, to);
		draw();
		Sleep(sleep_time);
		tower_of_hanoi(n - 1, aux, to, from);
		
	}

	void draw_a_b_c()
	{
		
		gotoxy(size+1+ a.x, rectangles[size - 1].getY() + 1); cout << 'A';
		gotoxy(size+1+ b.x, rectangles[size - 1].getY() + 1); cout << 'B';
		gotoxy(size+1+ c.x, rectangles[size - 1].getY() + 1); cout << 'C';
	}

	void draw()
	{
		
		for(int i = 0 ; i < size;i++)
		{
			rectangles[i].draw();
		}
	}

	~Tower()
	{
		//delete
	}
};



int main()
{
	ShowCursor(false);

	Tower tower(10);

	tower.draw();

	auto a = Pos(10, tower.get_size());
	auto b = Pos(50, 0);
	auto c = Pos(90, 0);

	tower.draw();
	Sleep(2000);
	tower.set_sleep_time(50);
	
	tower.tower_of_hanoi(tower.get_size(), a, c, b);

	tower.draw();


	cin.get();
}
