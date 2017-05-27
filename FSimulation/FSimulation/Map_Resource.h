#pragma once

//Tuple���ݽṹ;
//��Ҫ��Ϊ�����������ʾ��·�Ĳ������;
struct Tuple_t
{
	//���;
	int start_x;
	int start_y;
	//�յ�;
	int end_x;
	int end_y;
	bool direction;	//ָʾ�����;����ֵ��� �� Ϊ��,��֮Ϊ��; �ڴ�ֱ��ֵ��У� �� Ϊ������֮Ϊ��;
	double length;	//��·������,��λΪ��(m);
	//��������;
};

//�˿����ݽṹ;
//��Ҫ��ʾ�����ڡ�Ͷ�ݿڵĴ�С�ͷ�λ;
struct Ports
{
	//���ϵ�;
	int UP_LEFT_x;
	int UP_LEFT_y;
	
	//���µ�;
	int DOWN_RIGHT_x;
	int DOWN_RIGHT_y;

	double height;	//ʵ�ʳ���;
	double width;	//ʵ�ʿ��;

	//��������;
	int agv_capacity;	//�˿�������AGV�����������Shipment������������ģ�
	//ֻ��ĿǰDock��û����������;
	//���·�λ�������ҵķ�λ��ʻ��־λ; 
	short delivery_direction;	//��־λ,�ǳ����ڵĳ�������;	 ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
};

//����ע�����ݽṹ;
//��Ҫ��ʾע�͵��������ݺͷ�λ;
struct Comments
{
	//λ��;
	int x;
	int y;
	
	//�ַ���;
	CString comments;	//CString ��
};

class Map_Resource
{
public:
	Map_Resource(void);
	~Map_Resource(void);
	void Initialize_Resource();
//private:?
public:
	//��ӵ����ݽṹ;
	vector<Tuple_t>Horizontal_Road;
	vector<Tuple_t>Vertical_Road;
	vector<Ports>Shipment;
	vector<Ports>Dock;
	vector<Comments>comments;
};

