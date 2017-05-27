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
	//一次检查所有AGV小车;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		agv_t->pos_x = agv_t->real_x;
		agv_t->pos_y = agv_t->real_y;
	}
}


//实际上是50ms内AGV的运动行为;
//短时钟间隔，增加实时性和精确性;
void AGV::Agv_Precise_move()
{
	//上下方位或者左右的方位行驶标志位; 停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
	//一次检查所有AGV小车;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		bool collision = AGV_Collision_Detection( *agv_t, 1.0, 0.5 );
		if( !collision )//如果没有冲突，才会更新移动;
		{
			double des_x = 150.0  *(agv_t->destination - 1) + 205.0;	//目标分拣口x值;
			double des_y = 345.0;										//目的分拣口y值;

			//判断是否在第一条横行线;
			if(agv_t->turn == 2 )// 小车 ← 行驶;
			{
				//判断是否到达指定下行轴线;
				if( agv_t->init_turn == 2 && (agv_t->real_x - des_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_x = des_x;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 3;	//改为竖行;
				}
				//判断是否到达指定下行轴线;
				else if( agv_t->init_turn == 1 && (agv_t->real_x - 95.0 < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_x = 95.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 3;	//改为竖行;
				}
				else agv_t->real_x -= ((agv_t->velocity * 0.05) / CFSimulationView::Horizontal_Road_scale);	//更新其50ms内的行驶情况;
			}//上下方位或者左右的方位行驶标志位; 停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
			else if(agv_t->turn == 1 )// 小车 → 行驶;
			{
				//判断是否到达指定上行轴线;
				if( agv_t->init_turn == 2 && (1295.0 - agv_t->real_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_x = 1295.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 4;	//改为竖行;
				}
				//判断是否到达指定上行轴线;
				else if( agv_t->init_turn == 1 && (des_x - agv_t->real_x < (agv_t->velocity * 0.05 / CFSimulationView::Horizontal_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_x = des_x;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 4;	//改为竖行;
				}
				else agv_t->real_x += (agv_t->velocity * 0.05) / CFSimulationView::Horizontal_Road_scale;	//更新其50ms内的行驶情况;
			}//→ 为1，← 为2，↓ 为3，↑ 为4 
			else if(agv_t->turn == 3 )// 小车 ↓ 行驶;
			{
				
				//判断是否到达指定分拣格口;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 2 && (des_y - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = des_y;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 0;	//改为停止状态,pull over;
				}
				//判断是否到达指定下行轴线;
				else if( agv_t->init_turn == 2 && agv_t->last_turn == 0 && (445.0 - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = 445.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 1;	//改为停止状态,pull over;
				}
				//判断是否到达指定下行轴线;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 2 && (495.0 - agv_t->real_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = 495.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 0;	//改为停止状态,pull over;
				}
				else agv_t->real_y += (agv_t->velocity * 0.05) / CFSimulationView::Vertical_Road_scale;	//更新其50ms内的行驶情况;
			}//→ 为1，← 为2，↓ 为3，↑ 为4 
			else if(agv_t->turn == 4 )// 小车 ↑ 行驶;
			{
				//判断是否到达指定下行轴线;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 1 && (agv_t->real_y - 195.0 < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = 195.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 0;	//改为停止状态,pull over;
				}
				//判断是否到达指定分拣格口;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 1 && (agv_t->real_y - des_y < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = des_y;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 0;	//改为停止状态,pull over;
				}
				//判断是否到达指定下行轴线;
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 0 && (agv_t->real_y - 195.0 < (agv_t->velocity * 0.05 / CFSimulationView::Vertical_Road_scale)) )//到达转折口0.01m附近,50ms内就可以穿过路口;
				{
					agv_t->real_y = 195.0;	//更新其50ms内的行驶情况;
					agv_t->last_turn = agv_t->turn;	//记录原方向;
					agv_t->turn = 2;	//改为停止状态,pull over;
				}
				else agv_t->real_y -= (agv_t->velocity * 0.05) / CFSimulationView::Vertical_Road_scale;	//更新其50ms内的行驶情况;
			}//→ 为1，← 为2，↓ 为3，↑ 为4 
			else if(agv_t->turn == 0 )// 小车 停止状态;
			{
				//判断是否到达指定下行轴线;
				if( agv_t->init_turn == 2 && agv_t->last_turn == 3 )
				{
					if(agv_t->count_sec ++ < 20);//读秒1000ms
					else
					{
						agv_t->last_turn = agv_t->turn;	//记录原方向;
						agv_t->turn = 3;
						//MessageBox(NULL, _T("Test"), _T("提示"), MB_OK);
					}
				}
				else if( agv_t->init_turn == 2 && agv_t->last_turn == 4 )//返回了原出货口;
				{
					//do something;
				}
				//判断下横道小车情况;
				if( agv_t->init_turn == 1 && agv_t->last_turn == 4 )
				{
					if(agv_t->count_sec ++ < 20);//读秒1000ms
					else
					{
						agv_t->last_turn = agv_t->turn;	//记录原方向;
						agv_t->turn = 4;
					}
				}
				else if( agv_t->init_turn == 1 && agv_t->last_turn == 3 )//返回了原出货口;
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


//检测是否会有AGV冲突的函数;
//上下方位或者左右的方位行驶标志位; 停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
//safe_distance单位是米（m）; 而AGV位置单位是像素点;....
bool AGV::AGV_Collision_Detection(Agv_attribute & agv, double safe_distance,double safe_cross_distance)
{
	//bool collision = false;	//初始默认不会碰撞;
	//检查现有所有AGV小车;
	for(vector <Agv_attribute>::iterator agv_t = all_agv.begin();
		agv_t != all_agv.end(); ++agv_t)
	{
		if(agv_t->pos_x == agv.pos_x && agv_t->pos_y == agv.pos_y)continue;	//跳过自己;
		else //检查其余AGV;
		{
			double x2 = (agv_t->real_x - agv.real_x) * (agv_t->real_x - agv.real_x) * CFSimulationView::Horizontal_Road_scale * CFSimulationView::Horizontal_Road_scale;
			double y2 = (agv_t->real_y - agv.real_y) * (agv_t->real_y - agv.real_y) * CFSimulationView::Vertical_Road_scale * CFSimulationView::Vertical_Road_scale;

			//首先检查同向情况;
			if( (agv.turn == 1 && agv_t->turn == 1 || agv.turn == 2 && agv_t->turn == 2) && 
				(agv.pos_y == agv_t->pos_y) && 
				( abs(agv.real_x - agv_t->real_x) * CFSimulationView::Horizontal_Road_scale < safe_distance ) && 
				(agv.priority < agv_t->priority) )return true;	//同一道路同向之横向情况; 优先级低就会判断为冲突;
			

			else if( (agv.turn == 3 && agv_t->turn == 3 || agv.turn == 4 && agv_t->turn == 4) && 
				(agv.pos_x == agv_t->pos_x) &&
				( abs(agv.real_y - agv_t->real_y) * CFSimulationView::Vertical_Road_scale < safe_distance ) && 
				(agv.priority < agv_t->priority) )return true;	//同向之竖向情况;

			//再者检测路口冲突;
			//停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
			else if( (agv.turn == 3 && agv_t->turn == 2 ) && //↓← 其一;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance) && 
				(agv.priority < agv_t->priority) )return true;//这里是交叉路口的判断情况，及其容易出问题！！！，
			//在增加转弯和加速减速时，需要修改;

			else if( (agv.turn == 2 && agv_t->turn == 3 ) && //↓← 其二;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;//这里是交叉路口的判断情况，及其容易出问题！！！，
			//在增加转弯和加速减速时，需要修改;

			else if( (agv.turn == 3 && agv_t->turn == 1 ) && //→↓ 其一;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 1 && agv_t->turn == 3 ) && //→↓ 其二;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			//停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
			else if( (agv.turn == 4 && agv_t->turn == 2 ) && //↑← 其一;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 2 && agv_t->turn == 4 ) && //↑← 其二;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			//停止状态为0， → 为1，← 为2，↓ 为3，↑ 为4 ;
			else if( (agv.turn == 4 && agv_t->turn == 1 ) && //→↑ 其一;
				( agv.real_x > agv_t->real_x ) && ( agv.real_y > agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;

			else if( (agv.turn == 1 && agv_t->turn == 4 ) && //→↑ 其二;
				( agv.real_x < agv_t->real_x ) && ( agv.real_y < agv_t->real_y ) &&	//判断交叉情况;
				( x2 + y2 <  safe_cross_distance ) && 
				(agv.priority < agv_t->priority) )return true;
		}
	}

	return false;//默认是不会碰撞的;
}