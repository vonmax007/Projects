#include "StdAfx.h"
#include "Map_Resource.h"

Map_Resource::Map_Resource(void)
{
}

Map_Resource::~Map_Resource(void)
{
}

//��ʼ�����е�·��ʩ;
void Map_Resource::Initialize_Resource()
{
	//��ӵ����ݽṹ;
	
	//Horizontal_Road.push_back(Tuple_t({150,200,1000,200}));
	
	Tuple_t r1 = {100,200,1300,200, 0,};
	Horizontal_Road.push_back(r1);
	
	Tuple_t r2 = {100,250,1300,250, 0};
	Horizontal_Road.push_back(r2);

	Tuple_t r3 = {100,450,1300,450, 1};
	Horizontal_Road.push_back(r3);

	Tuple_t r4 = {100,500,1300,500, 1};
	Horizontal_Road.push_back(r4);

	//vector<Tuple_t>Vertical_Road;
	

	//��ʼ�����ּ�ڣ���Ҫ�˸�;
	//˳����ƴ�ֱ���·;
	Tuple_t vr[16];//�����Ƿּ����������е�·

	Ports docks[10];
	Ports dock00 = {150,325,200,375,0.5,0.5};
	int width_inteval = 150;
	for(int i=0;i<8;++i)
	{
		docks[i].UP_LEFT_x = dock00.UP_LEFT_x + i * width_inteval;
		docks[i].UP_LEFT_y = 325;
		docks[i].DOWN_RIGHT_x = docks[i].UP_LEFT_x + 50;	//���ؿ��Ϊ50;
		docks[i].DOWN_RIGHT_y = 375;

		Dock.push_back(docks[i]);
		
		vr[2*i].start_x = docks[i].UP_LEFT_x - 10;
		vr[2*i].start_y = 200;	//200��y�Ὺʼ��ˮƽ��׼;
		vr[2*i].end_x = docks[i].UP_LEFT_x - 10;
		vr[2*i].end_y = 500;	//500��y�������ˮƽ��׼;
		vr[2*i].direction = 0;	//���Ϸ���;
		vr[2*i].length = 30.0;	//�ٶ���30m��������·����;
		Vertical_Road.push_back(vr[2*i]);
		//�ұߵڶ�����;
		vr[2*i+1].start_x = docks[i].DOWN_RIGHT_x + 10;
		vr[2*i+1].start_y = 200;	//200��y�Ὺʼ��ˮƽ��׼;
		vr[2*i+1].end_x = docks[i].DOWN_RIGHT_x + 10;
		vr[2*i+1].end_y = 500;	//500��y�������ˮƽ��׼;
		vr[2*i+1].direction = 1;	//���·���;
		vr[2*i+1].length = 30.0;	//�ٶ���30m��������·����;
		Vertical_Road.push_back(vr[2*i+1]);
	}

	//˳����������ഹֱ���·;
	Tuple_t vr1 = {100,200,100,500,1,30.0};
	Vertical_Road.push_back(vr1);
	Tuple_t vr2 = {1300,200,1300,500,0,30.0};
	Vertical_Road.push_back(vr2);

	//��Ƴ�����Shipment;
	//vector<Ports>Shipment;
	Ports shipment00 = {1300,193,1330,207,3.0,1.0, 50, 2};//�˳������ǵ�һ����������ʱ����Ϊ1; �� ����;
	Ports shipment01 = {1300,243,1330,257,3.0,1.0, 50, 2};//�˳������ǵڶ�����������ʱ����Ϊ1; �� ����;
	Ports shipment02 = {70,443,100,457,3.0,1.0, 50, 1};//�˳������ǵ�һ����������ʱ����Ϊ1; �� ����;
	Ports shipment03 = {70,493,100,507,3.0,1.0, 50, 1};//�˳������ǵ�һ����������ʱ����Ϊ1; �� ����;
	Shipment.push_back(shipment00);
	Shipment.push_back(shipment01);
	Shipment.push_back(shipment02);
	Shipment.push_back(shipment03);
	//���������������ע��;
	//vector<Comments>comments;
	Comments cm00 = {1290,175,_T("������ 1")};
	Comments cm01 = {1290,225,_T("������ 2")};
	Comments cm02 = {70,428,_T("������ 3")};
	Comments cm03 = {70,478,_T("������ 4")};

	comments.push_back(cm00);
	comments.push_back(cm01);
	comments.push_back(cm02);
	comments.push_back(cm03);
}
