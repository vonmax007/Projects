#include "StdAfx.h"
#include "AGV.h"


AGV::AGV(void)
{
}

AGV::~AGV(void)
{
}

//

void AGV::Initialize_Agv()
{
	/*Agv_attribute agv1 = {1295,195,1,5, 2};
	Agv_attribute agv2 = {1295,245,1,1, 2};
	all_agv.push_back(agv1);
	all_agv.push_back(agv2);*/
}


void AGV::Agv_Drawing_move()
{
	//һ�μ������AGVС��;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		agv_t->pos_x = agv_t->real_x;
		agv_t->pos_y = agv_t->real_y;
	}
}


//ʵ������50ms��AGV���˶���Ϊ;
//��ʱ�Ӽ��������ʵʱ�Ժ;�ȷ��;
void AGV::Agv_Precise_move()
{
	//���·�λ�������ҵķ�λ��ʻ��־λ; ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
	//һ�μ������AGVС��;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		bool collision = AGV_Collision_Detection( *agv_t, 1.0, 0.5 );
		if( !collision )//���û�г�ͻ���Ż�����ƶ�;
		{
			double des_x = 150.0  *(agv_t->destination - 1) + 205.0;	//Ŀ��ּ��xֵ;
			double des_y = 345.0;										//Ŀ�ķּ��yֵ;

			//�ж��Ƿ��ڵ�һ��������;
			if(agv_t->turn == 2 )// С�� �� ��ʻ;
			{
				//�ж��Ƿ񵽴�ָ����������;
				if( agv_t->init_turn == 2 && (agv_t->real_x - des_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_x = des_x;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 3;	//��Ϊ����;
				}
				//�ж��Ƿ񵽴�ָ����������;
				else if( agv_t->init_turn == 1 && (agv_t->real_x - 95.0 < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_x = 95.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 3;	//��Ϊ����;
				}
				else agv_t->real_x -= ((agv_t->velocity * 0.05) / CFSimulationView::Horizontal_Road_scale);	//������50ms�ڵ���ʻ���;
			}//���·�λ�������ҵķ�λ��ʻ��־λ; ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
			else if(agv_t->turn == 1 )// С�� �� ��ʻ;
			{
				//�ж��Ƿ񵽴�ָ����������;
				if( agv_t->init_turn == 2 && (1295.0 - agv_t->real_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_x = 1295.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 4;	//��Ϊ����;
				}
				//�ж��Ƿ񵽴�ָ����������;
				else if( agv_t->init_turn == 1 && (des_x - agv_t->real_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_x = des_x;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 4;	//��Ϊ����;
				}
				else agv_t->real_x += (agv_t->velocity * 0.05) / CFSimulationView::Horizontal_Road_scale;	//������50ms�ڵ���ʻ���;
			}//�� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 
			else if(agv_t->turn == 3 )// С�� �� ��ʻ;
			{
				
				//�ж��Ƿ񵽴�ָ���ּ���;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 2 && (des_y - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = des_y;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 0;	//��Ϊֹͣ״̬,pull over;
				}
				//�ж��Ƿ񵽴�ָ����������;
				else if( agv_t->init_turn == 2 && agv_t->last_turn == 0 && (445.0 - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = 445.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 1;	//��Ϊֹͣ״̬,pull over;
				}
				//�ж��Ƿ񵽴�ָ����������;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 2 && (495.0 - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = 495.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 0;	//��Ϊֹͣ״̬,pull over;
				}
				else agv_t->real_y += (agv_t->velocity * 0.05) / CFSimulationView::Vertical_Road_scale;	//������50ms�ڵ���ʻ���;
			}//�� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 
			else if(agv_t->turn == 4 )// С�� �� ��ʻ;
			{
				//�ж��Ƿ񵽴�ָ����������;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 1 && (agv_t->real_y - 195.0 < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = 195.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 0;	//��Ϊֹͣ״̬,pull over;
				}
				//�ж��Ƿ񵽴�ָ���ּ���;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 1 && (agv_t->real_y - des_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = des_y;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 0;	//��Ϊֹͣ״̬,pull over;
				}
				//�ж��Ƿ񵽴�ָ����������;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 0 && (agv_t->real_y - 195.0 < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//����ת�ۿ�0.01m����,50ms�ھͿ��Դ���·��;
				{
					agv_t->real_y = 195.0;	//������50ms�ڵ���ʻ���;
					agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
					agv_t->turn = 2;	//��Ϊֹͣ״̬,pull over;
				}
				else agv_t->real_y -= (agv_t->velocity * 0.05) / CFSimulationView::Vertical_Road_scale;	//������50ms�ڵ���ʻ���;
			}//�� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 
			else if(agv_t->turn == 0 )// С�� ֹͣ״̬;
			{
				//�ж��Ƿ񵽴�ָ����������;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 3 )
				{
					if(agv_t->count_sec ++ < 20);//����1000ms
					else
					{
						agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
						agv_t->turn = 3;
						//MessageBox(NULL, _T("Test"), _T("��ʾ"), MB_OK);
					}
				}
				else if( agv_t->init_turn == 2 && agv_t->last_turn == 4 )//������ԭ������;
				{
					//do something;
				}
				//�ж��º��С�����;
				if( agv_t->init_turn == 1 && agv_t->last_turn == 4 )
				{
					if(agv_t->count_sec ++ < 20);//����1000ms
					else
					{
						agv_t->last_turn = agv_t->turn;	//��¼ԭ����;
						agv_t->turn = 4;
					}
				}
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 3 )//������ԭ������;
				{
					//do something;
				}
			}	
		}
		else
		{
			//curret do nothing; just wait;
			continue;
		}
	}
}


//����Ƿ����AGV��ͻ�ĺ���;
//���·�λ�������ҵķ�λ��ʻ��־λ; ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
//safe_distance��λ���ף�m��; ��AGVλ�õ�λ�����ص�;....
bool AGV::AGV_Collision_Detection(Agv_attribute & agv, double safe_distance,double safe_cross_distance)
{
	//bool collision = false;	//��ʼĬ�ϲ�����ײ;
	//�����������AGVС��;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		if(agv_t->pos_x == agv.pos_x && agv_t->pos_y == agv.pos_y)continue;	//�����Լ�;
		else //�������AGV;
		{
			double x2 = (agv_t->real_x - agv.real_x) * (agv_t->real_x - agv.real_x) * CFSimulationView::Horizontal_Road_scale * CFSimulationView::Horizontal_Road_scale;
			double y2 = (agv_t->real_y - agv.real_y) * (agv_t->real_y - agv.real_y) * CFSimulationView::Vertical_Road_scale * CFSimulationView::Vertical_Road_scale;

			//���ȼ��ͬ�����;
			if( (agv.turn == 1 && agv_t->turn == 1 || agv.turn == 2 && agv_t->turn == 2) && 
				(agv.pos_y == agv_t->pos_y) && 
				( abs(agv.real_x - agv_t->real_x) * CFSimulationView::Horizontal_Road_scale < safe_distance ) && 
				(agv.priority < agv_t->priority) )return true;	//ͬһ��·ͬ��֮�������; ���ȼ��;ͻ��ж�Ϊ��ͻ;
			

			else if( (agv.turn == 3 && agv_t->turn == 3 || agv.turn == 4 && agv_t->turn == 4) && 
				(agv.pos_x == agv_t->pos_x) &&
				( abs(agv.real_y - agv_t->real_y) * CFSimulationView::Vertical_Road_scale < safe_distance ) && 
				(agv.priority < agv_t->priority) )return true;	//ͬ��֮�������;

			//���߼��·�ڳ�ͻ;
			//ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
			else if( (agv.turn == 3 && agv_t->turn == 2 ) && //���� ��һ;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance) && 
				(agv.priority < agv_t->priority) )return true;//�����ǽ���·�ڵ��ж�������������׳����⣡������
			//������ת��ͼ��ټ���ʱ����Ҫ�޸�;

			else if( (agv.turn == 2 && agv_t->turn == 3 ) && //���� ���;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;//�����ǽ���·�ڵ��ж�������������׳����⣡������
			//������ת��ͼ��ټ���ʱ����Ҫ�޸�;

			else if( (agv.turn == 3 && agv_t->turn == 1 ) && //���� ��һ;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 1 && agv_t->turn == 3 ) && //���� ���;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			//ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
			else if( (agv.turn == 4 && agv_t->turn == 2 ) && //���� ��һ;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 2 && agv_t->turn == 4 ) && //���� ���;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			//ֹͣ״̬Ϊ0�� �� Ϊ1���� Ϊ2���� Ϊ3���� Ϊ4 ;
			else if( (agv.turn == 4 && agv_t->turn == 1 ) && //���� ��һ;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 1 && agv_t->turn == 4 ) && //���� ���;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//�жϽ������;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;
		}
	}

	return false;//Ĭ���ǲ�����ײ��;
}