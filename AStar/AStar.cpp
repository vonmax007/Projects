
/*
因为是频繁的在头部插入，所以链表是首选
TileType unsigned char主要是为了节省空间，因为本来状态就不多255绝对够用了
源文件
*/

#include "stdafx.h"
#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}
//保持两张表
static AStarList* Open = NULL;
static AStarList* Closed = NULL;



static AStar* m_only_AStar = nullptr;
AStar* AStar::getInstance()
{
	if (!m_only_AStar)
	{
		m_only_AStar = new AStar;
	}

	return m_only_AStar;
}

void AStar::destroy()
{
	if (m_only_AStar)
	{
		delete m_only_AStar;
		m_only_AStar = nullptr;
	}
}

void ClearList(AStarList* list)
{
	AStarList* temp = list->next;
	AStarNode *p_node;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		AStarList* head = temp;
		temp = temp->next;
		p_node = head->npoint;
		delete p_node;
		delete head;
		list->next = temp;
	}
}

void ClearOpenData()
{	//清空Open表
	ClearList(Open);
}

void ClearClosedData()
{	//清空Close表
	ClearList(Closed);
}

void AStar::PrintMap()
{	//输出地图
	int i, j;
	for (i = 0; i<rows; i++)
	{
		for (j = 0; j<cols; j++)
		{
			if (map[i][j] == Tile_Open || map[i][j] == Tile_UP || 
				map[i][j] == Tile_DOWN || map[i][j] == Tile_LEFT
				|| map[i][j] == Tile_RIGHT || map[i][j] == Tile_UP_LEFT
				|| map[i][j] == Tile_UP_RIGHT || map[i][j] == Tile_DOWN_LEFT
				|| map[i][j] == Tile_DOWN_RIGHT) {
				printf("□");
			}
			else if (map[i][j] == Tile_Lock) {
				printf("■");
			}
			else if (map[i][j] == Tile_Start) {
				printf("☆");
			}
			else if (map[i][j] == Tile_End) {
				printf("★");
			}
			else if (map[i][j] == Tile_Path) {
				printf("●");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

AStarNode* AStar::getNodeFromOpen()
{	//选取Open表上f值最小的节点，返回该节点地址
	AStarList* temp = Open->next,
		*min = Open->next,
		*minp = Open;
	AStarNode * minx;
	if (temp == NULL)
		return NULL;

	while (temp->next != NULL)
	{
		if ((temp->next->npoint->f) < (min->npoint->f))
		{
			min = temp->next;//min表示f最小的链表节
			minp = temp;//指向min的指针，为的是在后面的释放中用到
		}
		temp = temp->next;//temp指向下一个链表节
	}
	minx = min->npoint;
	temp = minp->next;
	minp->next = minp->next->next;
	delete temp;
	return minx;
}

void AStar::pushOpen(AStarNode * suc)
{//把节点放入Open表中
	AStarList * temp;
	temp = new AStarList;
	temp->npoint = suc;

	temp->next = Open->next;
	Open->next = temp;
}

void AStar::pushClosed(AStarNode * suc)
{//把节点放入Close表中
	AStarList * temp;
	temp = new AStarList;
	temp->npoint = suc;
	temp->next = Closed->next;
	Closed->next = temp;
}

int AStar::getH(int row, int col)
{//得到该图块的H值
	int h;
	if(short(isMapModified[row][col]) == 0)	//未修改（惩罚）,则返回原始值
		h = abs(destinationRow - row) + abs(destinationCol - col) + 1;
	else h = pow(PenaltyScale, short(isMapModified[row][col])) * (abs(destinationRow - row) + abs(destinationCol - col) + 1);
	return h * 10;
}

int AStar::getRowPosition(int x)
{//得到该位置所在地图行
	return (x / TileSize);
}

int AStar::getColPosition(int y)
{//得到该位置所在地图列
	return (y / TileSize);
}

bool AStar::isCanMove(int frow, int fcol, int row, int col)
{//检测该图块是否可通行
	if (col < 0 || col >= cols)
		return false;
	if (row < 0 || row >= rows)
		return false;
	if (map[row][col] == Tile_Lock)
		return false;

	if ((row == frow - 1 && col == fcol) &&
		(map[row][col] == Tile_DOWN ||
			map[row][col] == Tile_DOWN_LEFT ||
			map[row][col] == Tile_DOWN_RIGHT)
		)return false;	//访问不可通行上方

	if ((row == frow + 1 && col == fcol) &&
		(map[row][col] == Tile_UP ||
			map[row][col] == Tile_UP_LEFT ||
			map[row][col] == Tile_UP_RIGHT)
		)return false;	//访问不可通行下方

	if ((row == frow && col == fcol - 1) &&
		(map[row][col] == Tile_RIGHT ||
			map[row][col] == Tile_UP_RIGHT ||
			map[row][col] == Tile_DOWN_RIGHT)
		)return false;	//访问不可通行左方

	if ((row == frow && col == fcol + 1) &&
		(map[row][col] == Tile_LEFT ||
			map[row][col] == Tile_UP_LEFT ||
			map[row][col] == Tile_DOWN_LEFT)
		)return false;	//访问不可通行右方

	return true;
}

AStarNode* AStar::checkOpen(int row, int col)
{	//校验Open表
	AStarList* temp = Open->next;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))
		{
			return temp->npoint;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

bool AStar::isInClose(int row, int col)
{//是否存在于Close表
	AStarList* temp = Closed->next;
	if (temp == NULL)
		return false;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))
		{
			return true;
		}
		else
		{
			temp = temp->next;
		}
	}
	return false;
}

void AStar::creatNextLapNode(AStarNode *bestNode, int row, int col, int G_OFFSET)
{//创建下一圈的node
	int g = bestNode->g + G_OFFSET;
	if (!isInClose(row, col))
	{
		AStarNode *oldNode = NULL;
		if ((oldNode = checkOpen(row, col)) != NULL)
		{
			if (oldNode->g > g)
			{
				oldNode->direct.i = bestNode->row;
				oldNode->direct.j = bestNode->col;
				oldNode->parent = bestNode;
				oldNode->g = g;
				oldNode->f = g + oldNode->h;
			}
		}
		else
		{
			AStarNode *node = new AStarNode;
			node->parent = bestNode;
			node->g = g;
			node->h = getH(row, col);
			node->f = node->g + node->h;
			node->row = row;
			node->col = col;
			node->direct.i = bestNode->row;
			node->direct.j = bestNode->col;

			pushOpen(node);
		}
	}
}

void AStar::seachSeccessionNode(AStarNode *bestNode)
{//根据传入的节点生成子节点
	int row, col;
	//上部节点
	if (isCanMove(bestNode->row, bestNode->col, row = bestNode->row - 1, col = bestNode->col))
	{
		creatNextLapNode(bestNode, row, col, G_OFFSET1);
	}
	//下部节点
	if (isCanMove(bestNode->row, bestNode->col, row = bestNode->row + 1, col = bestNode->col))
	{
		creatNextLapNode(bestNode, row, col, G_OFFSET1);
	}
	//左部节点
	//cout << map[bestNode->row][bestNode->col - 1] << endl;
	if (isCanMove(bestNode->row, bestNode->col, row = bestNode->row, col = bestNode->col - 1))
	{
		creatNextLapNode(bestNode, row, col, G_OFFSET1);
	}
	//右部节点
	if (isCanMove(bestNode->row, bestNode->col, row = bestNode->row, col = bestNode->col + 1))
	{
		creatNextLapNode(bestNode, row, col, G_OFFSET1);
	}
	//下面是为未来走四周斜角时做准备的
	////左上角
	//if(isCanMove(row = bestNode->row-1, col = bestNode->col - 1))
	//{
	//  creatNextLapNode(bestNode, row, col,G_OFFSET2);
	//}
	////右上角
	//if(isCanMove(row = bestNode->row+1, col = bestNode->col - 1))
	//{
	//  creatNextLapNode(bestNode, row, col,G_OFFSET2);
	//}
	////左下角
	//if(isCanMove(row = bestNode->row-1, col = bestNode->col + 1))
	//{
	//  creatNextLapNode(bestNode, row, col,G_OFFSET2);
	//}
	////右下角
	//if(isCanMove(row = bestNode->row+1, col = bestNode->col + 1))
	//{
	//  creatNextLapNode(bestNode, row, col,G_OFFSET2);
	//}

	pushClosed(bestNode);
}

bool AStar::isSamePath(std::list <Point> path1, std::list <Point> path2)
{
	if (path1.size() != path2.size())return false;	//直接返回其不同路径也
	std::list <Point>::iterator it1, it2;
	for (it1 = path1.begin(), it2 = path2.begin(); 
		 it1 != path1.end(), it2 != path2.end();
		++it1, ++it2)
	{
		if (it1->i != it2->i || it1->j != it2->j)return false;
	}
	return true;
}

bool AStar::isPathExisted(std::list <std::list <Point>> PathSet, std::list <Point> path)
{
	std::list <std::list <Point>>::iterator its;
	for (its = PathSet.begin(); its != PathSet.end(); ++its)
	{
		if (isSamePath(*its, path))return true;
	}
	return false;
}

void AStar::modifyPath(std::list <Point> path, int StartX, int StartY, int EndX, int EndY)
{
	//修改指定路径上的资源
	double a, b;				//alpha and belta
	srand((unsigned)time(NULL)); //srand(3)
	a = rand() / double(RAND_MAX);
	std::list <Point>::iterator it;
	for (it = path.begin(); it != path.end(); ++it)
	{
		bool b1 = (abs(it->i - StartX) + abs(it->j - StartY) < PenaltyD);
		bool b2 = (abs(it->i - EndX) + abs(it->j - EndY) < PenaltyD);
		if (b1 || b2)continue;//如果在起点或终点附近，不惩罚;
		else
		{
			//这里b没有用时间种子随机，因为CPU太快了，时间随机太接近相等
			b = rand() / double(RAND_MAX);	//以概率belta < alpha 惩罚
			if (b < a)isMapModified[it->i][it->j] += 1;
			//map[it->i][it->j] = Tile_Lock;
		}
	}
}


std::list <std::list <Point>> AStar::findKPath(int k, TileType inMap[MAXROW][MAXCOL], int inRow, int inCol, int StartX, int StartY, int EndX, int EndY)
{
	//主函数,产生k条路径
	PathSet kpath;
	auto astar = AStar::getInstance();

	Open = new AStarList;
	Open->next = nullptr;
	Closed = new AStarList;
	Closed->next = nullptr;

	rows = inRow;
	cols = inCol;
	//动态创建内嵌map,isMapModified 对象，以节省空间
	map = new TileType *[rows];
	isMapModified = new TileType *[rows];
	for (short i = 0; i < rows; ++i)
	{
		map[i] = new TileType[cols];
		isMapModified[i] = new TileType[cols];
	}
		
	//接收传进来的值;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			map[i][j] = inMap[i][j];
			isMapModified[i][j] = 0;	//初始默认是未被修改的
			if (i == StartX && j == StartY)
			{
				map[i][j] = Tile_Start;
			}
			if (i == EndX && j == EndY)
			{
				map[i][j] = Tile_End;
			}
		}
	}
	PrintMap();
	std::cout << "\n\n *****************************  \n\n";

	int pathCount = 0;
	int failCount = 0;
	while (pathCount < k && failCount < MAXFAIL)
	{
		AStarNode *startNode = new AStarNode;
		AStarNode *bestNode = NULL;
		destinationRow = getRowPosition(EndX);
		destinationCol = getColPosition(EndY);

		startNode->parent = NULL;
		startNode->row = getRowPosition(StartX);
		startNode->col = getColPosition(StartY);
		startNode->g = 0;
		startNode->h = getH(startNode->row, startNode->col);
		startNode->f = startNode->g + startNode->h;
		startNode->direct.i = startNode->row;
		startNode->direct.j = startNode->col;
		pushOpen(startNode);

		std::list<Point> path;
		Point point;
		while (true)
		{
			bestNode = getNodeFromOpen(); //从OPEN表中取出f值最小的节点
			if (bestNode == NULL)//未找到路径
			{
				break;
			}
			else if (bestNode->row == destinationRow && bestNode->col == destinationCol)
			{
				map[bestNode->row][bestNode->col] = Tile_Path;
				point.i = bestNode->row;
				point.j = bestNode->col;
				path.push_front(point);//实际运行去掉,不然会到达最后一个格子再折返
				while (!(bestNode->direct.i == StartX&&bestNode->direct.j == StartY))
				{
					map[bestNode->direct.i][bestNode->direct.j] = Tile_Path;
					bestNode = bestNode->parent;

					point.i = bestNode->row;
					point.j = bestNode->col;
					path.push_front(point);
				}
				break;
			}

			seachSeccessionNode(bestNode);
		}
		if (!isPathExisted(kpath, path))
		{
			kpath.push_front(path);
			PrintMap();
			modifyPath(path, StartX, StartY, EndX, EndY);
			failCount = 0;	//清空失败统计
			pathCount++;	//路径统计值更新
		}
		else failCount ++;

		ClearOpenData();
		ClearClosedData();
	}

	//清理步骤
	delete(Open);
	delete(Closed);
	return kpath;
}