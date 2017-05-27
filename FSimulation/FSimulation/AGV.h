#pragma once


struct Agv_attribute
{
	int pos_x;
	int pos_y;	//绘图位置;

	double real_x;	//真实水平坐标度量,单位米(m);
	double real_y;	//真实竖直坐标度量,单位米(m);

	double velocity;	//agv速度;
	int destination;
	short turn;	//上下方位或者左右的方位行驶标志位; 停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
	short last_turn;	//记录小车上一次行驶方向;
	short init_turn;	//记录小车初始位置的;
	int count_sec;	//记录AGV停止位置停止了多少毫秒;
	long priority;
	//保留属性;
	//vector <agv_cycle> path;	//AGV经过的所有路径段;
};

class AGV
{
public:
	AGV(void);
	~AGV(void);
	vector <Agv_attribute> all_agv;
	void Initialize_Agv();
	void Agv_Drawing_move();
	void Agv_Precise_move();
	bool AGV_Collision_Detection(Agv_attribute & agv, double safe_distance,double safe_cross_distance);
	//void Agv_move(int time_inteval);//计算经过多少时间间隔，当前AGV运动状态;
};


//保留数据结构;
//AGV每一段路径的位置以及时间;
struct agv_cycle
{
	int path_start_x;
	int path_start_y;

	int path_end_x;
	int path_end_y;

	double start_time;
	double end_time;
};
