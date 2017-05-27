
/*
A*寻路算法 by EOS.
功能写好后，接口封装的还是比较漂亮的~
头文件
*/
#pragma once
#include "stdafx.h"

typedef unsigned char TileType;	//声明各方格所使用的类型
#define MAXROW  450
#define MAXCOL  450
#define MAXFAIL 5

#define NULL    0
#define G_OFFSET1 10			//每个图块G值的增加值
#define G_OFFSET2 14
#define TileSize  1				//图块大小
#define Tile_Lock 0     
#define Tile_Open 1     
#define Tile_Start 2    
#define Tile_End  3     
#define Tile_Path 4     
#define PenaltyD 4				//路径远离多远开始惩罚
#define PenaltyScale 2			//惩罚倍率，这里设置为2
//方向指示位的定义;
#define Tile_UP  100			//↑
#define Tile_DOWN  101			//↓
#define Tile_LEFT  102			//←
#define Tile_RIGHT  103			//→
#define Tile_UP_RIGHT  104		//↑→
#define Tile_UP_LEFT  105		//←↑
#define Tile_DOWN_RIGHT  106	//↓→
#define Tile_DOWN_LEFT  107		//←↓

struct Point
{
	unsigned short i, j;		//i是行,j是列
	Point() {}
	Point(unsigned short _i, unsigned short _j) : i(_i), j(_j) {}
};

struct AStarNode
{//节点结构体
	int f, g, h;
	int row;  //该节点所在行
	int col;  //该节点所在列
	Point direct;//parent节点要移动的方向就能到达本节点
	struct AStarNode * parent;
};

typedef struct AStarList
{//OPEN CLOSED 表结构体
	AStarNode * npoint;
	struct AStarList * next;
}AStarList;

class AStar
{
public:
	AStar();
	~AStar();

	static AStar* getInstance();
	static void destroy();
	void modifyPath(std::list <Point> path, int StartX, int StartY, int EndX, int EndY);
	std::list <std::list <Point>> findKPath(int k, TileType inMap[MAXROW][MAXCOL], int inRow, int inCol, int StartX, int StartY, int EndX, int EndY);
	
	void PrintMap();//测试用，打印地图
	AStarNode* getNodeFromOpen();
	void pushOpen(AStarNode * suc);
	void pushClosed(AStarNode * suc);
	int getH(int row, int col);
	int getRowPosition(int x);
	int getColPosition(int y);
	AStarNode* checkOpen(int row, int col);
	bool isInClose(int row, int col);
	void creatNextLapNode(AStarNode *bestNode, int row, int col, int G_OFFSET);
	bool isSamePath(std::list <Point> path1, std::list <Point> path2);
	bool AStar::isPathExisted(std::list <std::list <Point>> PathSet, std::list <Point> path);
	bool isCanMove(int frow, int fcol, int row, int col);
	void seachSeccessionNode(AStarNode *bestNode);
	
private:
	TileType ** map;
	TileType ** isMapModified;
	//bool ** isMapModified;
	int rows;
	int cols;
	int destinationRow;
	int destinationCol;
};