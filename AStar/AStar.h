
/*
A*Ѱ·�㷨 by EOS.
����д�ú󣬽ӿڷ�װ�Ļ��ǱȽ�Ư����~
ͷ�ļ�
*/
#pragma once
#include "stdafx.h"

typedef unsigned char TileType;	//������������ʹ�õ�����
#define MAXROW  450
#define MAXCOL  450
#define MAXFAIL 5

#define NULL    0
#define G_OFFSET1 10			//ÿ��ͼ��Gֵ������ֵ
#define G_OFFSET2 14
#define TileSize  1				//ͼ���С
#define Tile_Lock 0     
#define Tile_Open 1     
#define Tile_Start 2    
#define Tile_End  3     
#define Tile_Path 4     
#define PenaltyD 4				//·��Զ���Զ��ʼ�ͷ�
#define PenaltyScale 2			//�ͷ����ʣ���������Ϊ2
//����ָʾλ�Ķ���;
#define Tile_UP  100			//��
#define Tile_DOWN  101			//��
#define Tile_LEFT  102			//��
#define Tile_RIGHT  103			//��
#define Tile_UP_RIGHT  104		//����
#define Tile_UP_LEFT  105		//����
#define Tile_DOWN_RIGHT  106	//����
#define Tile_DOWN_LEFT  107		//����

struct Point
{
	unsigned short i, j;		//i����,j����
	Point() {}
	Point(unsigned short _i, unsigned short _j) : i(_i), j(_j) {}
};

struct AStarNode
{//�ڵ�ṹ��
	int f, g, h;
	int row;  //�ýڵ�������
	int col;  //�ýڵ�������
	Point direct;//parent�ڵ�Ҫ�ƶ��ķ�����ܵ��ﱾ�ڵ�
	struct AStarNode * parent;
};

typedef struct AStarList
{//OPEN CLOSED ��ṹ��
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
	
	void PrintMap();//�����ã���ӡ��ͼ
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