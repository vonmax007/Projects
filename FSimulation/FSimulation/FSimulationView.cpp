
// FSimulationView.cpp : CFSimulationView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "FSimulation.h"
#endif

#include "FSimulationDoc.h"
#include "FSimulationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

double CFSimulationView::Horizontal_Road_scale = 0.05;
double CFSimulationView::Vertical_Road_scale = 0.05;
// CFSimulationView

IMPLEMENT_DYNCREATE(CFSimulationView, CView)

BEGIN_MESSAGE_MAP(CFSimulationView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFSimulationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CFSimulationView::OnScenario_01)
END_MESSAGE_MAP()

// CFSimulationView ����/����

CFSimulationView::CFSimulationView()
{
	// TODO: �ڴ˴���ӹ������
	//��ʼ�����в���;
	
	time_scale = 10;												//�����1���룬��Ӧ��С������10����;
	agv_num = 4;													//��ʼֻ��4��AGV;
	refresh_time = 100;												//100�������һ��ͼ;
	agvs.Initialize_Agv();
	Total_Transport = 0;											//�����������ͻ�����;
	Total_time = 0;													//������ʱ�����;
	priority = 0;

	map1.Initialize_Resource();										//����һ�ĳ�ʼ��;
	system_time = 0.0;												//ϵͳʱ�Ӵ�0.0s��ʼ;
	QueryPerformanceFrequency(&nFreq);								//��ʼ��ѯCPUʱ��Ƶ��;
	dfFreq = (double)nFreq.QuadPart;								//CPUʱ��Ƶ�ʸ����ʾ;
	/*
		����ģ��Ŀ�ĵص��ļ�;
	*/


	ifstream ifile;	//���ļ���10����;
	ifile.open("E:\\Projects\\Destination_dat.txt");
	char buffer[100];
	int num;	//��ʵĿ�ĵ�;
	while (!ifile.eof() )  
    {  
        ifile.getline (buffer,100);  
		num = buffer[0] - '0';
		Destination_q.push(num);
    }ifile.close();
}

CFSimulationView::~CFSimulationView()
{
}

BOOL CFSimulationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFSimulationView ����

void CFSimulationView::OnDraw(CDC* /*pDC*/)
{
	CFSimulationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFSimulationView ��ӡ


void CFSimulationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFSimulationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFSimulationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFSimulationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CFSimulationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFSimulationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFSimulationView ���

#ifdef _DEBUG
void CFSimulationView::AssertValid() const
{
	CView::AssertValid();
}

void CFSimulationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFSimulationDoc* CFSimulationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFSimulationDoc)));
	return (CFSimulationDoc*)m_pDocument;
}
#endif //_DEBUG


// CFSimulationView ��Ϣ�������


void CFSimulationView::OnScenario_01()
{
	// TODO: �ڴ���������������
	MessageBox(_T("Failed to create time event !"));
}
