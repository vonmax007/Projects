#include "stdafx.h"

int main()
{
	//设置控制台输出大小~~
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;
	size.X = 1000;
	size.Y = 1000;
	SetConsoleScreenBufferSize(hOut, size);
	//设置控制台输出大小~~
	/*
	unsigned char real_map[MAXROW][MAXROW] = {0};
	for(int i=0;i<61;++i)
		for (int j = 0; j < 61; ++j)
		{
			if (i % 3 == 0 && i % 6 == 0 && j % 3 != 0)
				real_map[i][j] = Tile_LEFT;	//←
			if (i % 3 == 0 && i % 6 != 0 && j % 3 != 0)
				real_map[i][j] = Tile_RIGHT;	//→
			if (j % 3 == 0 && j % 6 == 0 && i % 3 != 0)
				real_map[i][j] = Tile_DOWN;	//←
			if (j % 3 == 0 && j % 6 != 0 && i % 3 != 0)
				real_map[i][j] = Tile_UP;	//→

			if (i % 3 == 0 && i % 6 == 0 && j % 3 == 0 && j % 6 != 0)
				real_map[i][j] = Tile_UP_LEFT;	//→
			if (i % 3 == 0 && i % 6 == 0 && j % 3 == 0 && j % 6 == 0)
				real_map[i][j] = Tile_DOWN_LEFT;	//→
			if (i % 3 == 0 && i % 6 != 0 && j % 3 == 0 && j % 6 != 0)
				real_map[i][j] = Tile_UP_RIGHT;	//→
			if (i % 3 == 0 && i % 6 != 0 && j % 3 == 0 && j % 6 == 0)
				real_map[i][j] = Tile_DOWN_RIGHT;	//→
		}
	real_map[12][0] = Tile_Lock;

	PathSet ps;
	AStar a;
	ps = a.findKPath(30,real_map, 61, 61, 0, 0, 60, 60);
	cout << ps.size() << "\n\n";
	a.destroy();
	*/

	unsigned char real_map[MAXROW][MAXROW] = { 0 };
	for (int i = 0; i<61; ++i)
		for (int j = 0; j < 61; ++j)
		{
			if (i % 3 == 0 || j % 3 == 0)real_map[i][j] = Tile_Open;
		}
	PathSet ps;
	AStar a;
	ps = a.findKPath(10, real_map, 61, 61, 21, 21, 30, 30);
	cout << ps.size() << "\n\n";
	a.destroy();

	return 0;
}