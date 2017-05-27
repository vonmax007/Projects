#pragma once


struct Agv_attribute
{
	int pos_x;
	int pos_y;	//��ͼλ��;

	double real_x;	//��ʵˮƽ�������,��λ��(m);
	double real_y;	//��ʵ��ֱ�������,��λ��(m);

	double velocity;	//agv�ٶ�;
	int destination;
	short turn;	//���·�λ�������ҵķ�λ��ʻ��־λ; ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
	short last_turn;	//��¼С����һ����ʻ����;
	short init_turn;	//��¼С����ʼλ�õ�;
	int count_sec;	//��¼AGVֹͣλ��ֹͣ�˶��ٺ���;
	long priority;
	//��������;
	//vector <agv_cycle> path;	//AGV����������·����;
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
	//void Agv_move(int time_inteval);//���㾭������ʱ��������ǰAGV�˶�״̬;
};


//�������ݽṹ;
//AGVÿһ��·����λ���Լ�ʱ��;
struct agv_cycle
{
	int path_start_x;
	int path_start_y;

	int path_end_x;
	int path_end_y;

	double start_time;
	double end_time;
};
