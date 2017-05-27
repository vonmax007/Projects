#pragma once

//Tuple数据结构;
//主要是为了用两个点表示道路的布设情况;
struct Tuple_t
{
	//起点;
	int start_x;
	int start_y;
	//终点;
	int end_x;
	int end_y;
	bool direction;	//指示方向的;横向街道中 → 为正,反之为负; 在垂直向街道中， ↓ 为正，反之为负;
	double length;	//此路径长度,单位为米(m);
	//保留属性;
};

//端口数据结构;
//主要表示出货口、投递口的大小和方位;
struct Ports
{
	//左上点;
	int UP_LEFT_x;
	int UP_LEFT_y;
	
	//右下点;
	int DOWN_RIGHT_x;
	int DOWN_RIGHT_y;

	double height;	//实际长度;
	double width;	//实际宽度;

	//保留属性;
	int agv_capacity;	//端口能容纳AGV数量，如果是Shipment，则是有意义的；
	//只是目前Dock是没有容量限制;
	//上下方位或者左右的方位行驶标志位; 
	short delivery_direction;	//标志位,是出货口的出货方向;	 停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
};

//文字注释数据结构;
//主要表示注释的文字内容和方位;
struct Comments
{
	//位置;
	int x;
	int y;
	
	//字符串;
	CString comments;	//CString 型
};

class Map_Resource
{
public:
	Map_Resource(void);
	~Map_Resource(void);
	void Initialize_Resource();
//private:?
public:
	//添加的数据结构;
	vector<Tuple_t>Horizontal_Road;
	vector<Tuple_t>Vertical_Road;
	vector<Ports>Shipment;
	vector<Ports>Dock;
	vector<Comments>comments;
};

