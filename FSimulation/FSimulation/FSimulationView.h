
// FSimulationView.h : CFSimulationView ��Ľӿ�
//

#pragma once
#include "FSimulationDoc.h"
#include "AGV.h"

class CFSimulationView : public CView
{
protected: // �������л�����
	CFSimulationView();
	DECLARE_DYNCREATE(CFSimulationView)

// ����
public:
	CFSimulationDoc* CFSimulationView::GetDocument() const;
	//�����Ƕ����Լ������ݽṹ;
	AGV agvs;	//��������agv;
	int agv_num;
	int refresh_time;	//������ˢ��һ����Ļ���ػ�ͼ;
	int time_scale;//�������һ���룬��Ӧ�ڷ���С�����ٺ���;
	int Total_Transport;	//�����������ͻ�����;
	int Total_time;	//������ʱ�����;
	static double Horizontal_Road_scale;	//��ʵˮƽ��·����/���س���ֵ;
	static double Vertical_Road_scale;		//��ʵ��ֱ��·����/���س���ֵ;
	long priority;

	Map_Resource map1;
	queue<int> Destination_q;

	double system_time;	//ϵͳʱ��; ��λ����(s);
	LARGE_INTEGER nFreq;	//��ȷCPUʱ��Ƶ��;
	double dfFreq;// ������CPUʱ��Ƶ��

// �Լ������һЩ����
public:
	//���Լ�����Ĳ���;
	void Out_Port_Simulation_01(AGV &agvs);	//��������һģ���������;
	void On_Paint_Resource_01();	//��ͼ��������һ����;
	bool Shipment_Collision_Detection(Ports &shipment);
	bool AGV_Collision_Detection(int pos_x, int pos_y, double real_x, double real_y, short direction, double safe_distance, double safe_cross_distance);
	//������AGV���г�ͻ���ĺ���(VIP);
	void Set_AGV_cycle(Agv_attribute & agv_add, int init_x, int init_y, int destination, short direction);	//����AGV��ʼ��·����;
	void delay(long microsecond);	//��ȷ��ʱ����;
	void OnTimer_01();


// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFSimulationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnScenario_01();
};

#ifndef _DEBUG  // FSimulationView.cpp �еĵ��԰汾
inline CFSimulationDoc* CFSimulationView::GetDocument() const
   { return reinterpret_cast<CFSimulationDoc*>(m_pDocument); }
#endif

