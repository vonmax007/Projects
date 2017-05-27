
// FSimulationView.cpp : CFSimulationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFSimulationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CFSimulationView::OnScenario_01)
END_MESSAGE_MAP()

// CFSimulationView 构造/析构

CFSimulationView::CFSimulationView()
{
	// TODO: 在此处添加构造代码
	//初始化所有参数;
	
	time_scale = 10;												//计算机1毫秒，对应于小车仿真10毫秒;
	agv_num = 4;													//初始只有4辆AGV;
	refresh_time = 100;												//100毫秒绘制一次图;
	agvs.Initialize_Agv();
	Total_Transport = 0;											//场景最终运送货物量;
	Total_time = 0;													//场景总时间计数;
	priority = 0;

	map1.Initialize_Resource();										//场景一的初始化;
	system_time = 0.0;												//系统时钟从0.0s开始;
	QueryPerformanceFrequency(&nFreq);								//初始查询CPU时钟频率;
	dfFreq = (double)nFreq.QuadPart;								//CPU时钟频率浮点表示;
	/*
		载入模拟目的地的文件;
	*/


	ifstream ifile;	//此文件有10万行;
	ifile.open("E:\\Projects\\Destination_dat.txt");
	char buffer[100];
	int num;	//真实目的地;
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFSimulationView 绘制

void CFSimulationView::OnDraw(CDC* /*pDC*/)
{
	CFSimulationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFSimulationView 打印


void CFSimulationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFSimulationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFSimulationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFSimulationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CFSimulationView 诊断

#ifdef _DEBUG
void CFSimulationView::AssertValid() const
{
	CView::AssertValid();
}

void CFSimulationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFSimulationDoc* CFSimulationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFSimulationDoc)));
	return (CFSimulationDoc*)m_pDocument;
}
#endif //_DEBUG


// CFSimulationView 消息处理程序


void CFSimulationView::OnScenario_01()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("Failed to create time event !"));
}
