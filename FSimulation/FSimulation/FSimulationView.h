
// FSimulationView.h : CFSimulationView 类的接口
//

#pragma once
#include "FSimulationDoc.h"
#include "AGV.h"

class CFSimulationView : public CView
{
protected: // 仅从序列化创建
	CFSimulationView();
	DECLARE_DYNCREATE(CFSimulationView)

// 特性
public:
	CFSimulationDoc* CFSimulationView::GetDocument() const;
	//这里是定义自己的数据结构;
	AGV agvs;	//载入所有agv;
	int agv_num;
	int refresh_time;	//定义多久刷新一次屏幕，重绘图;
	int time_scale;//计算机中一毫秒，对应于仿真小车多少毫秒;
	int Total_Transport;	//场景最终运送货物量;
	int Total_time;	//场景总时间计数;
	static double Horizontal_Road_scale;	//真实水平道路长度/像素长比值;
	static double Vertical_Road_scale;		//真实竖直道路长度/像素长比值;
	long priority;

	Map_Resource map1;
	queue<int> Destination_q;

	double system_time;	//系统时钟; 单位是秒(s);
	LARGE_INTEGER nFreq;	//精确CPU时钟频率;
	double dfFreq;// 浮点型CPU时钟频率

// 自己定义的一些操作
public:
	//我自己定义的操作;
	void Out_Port_Simulation_01(AGV &agvs);	//基础场景一模拟出货函数;
	void On_Paint_Resource_01();	//绘图基础场景一函数;
	bool Shipment_Collision_Detection(Ports &shipment);
	bool AGV_Collision_Detection(int pos_x, int pos_y, double real_x, double real_y, short direction, double safe_distance, double safe_cross_distance);
	//和现有AGV进行冲突检测的函数(VIP);
	void Set_AGV_cycle(Agv_attribute & agv_add, int init_x, int init_y, int destination, short direction);	//计算AGV初始环路函数;
	void delay(long microsecond);	//精确延时函数;
	void OnTimer_01();


// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFSimulationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnScenario_01();
};

#ifndef _DEBUG  // FSimulationView.cpp 中的调试版本
inline CFSimulationDoc* CFSimulationView::GetDocument() const
   { return reinterpret_cast<CFSimulationDoc*>(m_pDocument); }
#endif

