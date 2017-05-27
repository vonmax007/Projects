
// DrawRobotView.cpp : CDrawRobotView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawRobot.h"
#endif

#include "DrawRobotDoc.h"
#include "DrawRobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawRobotView

IMPLEMENT_DYNCREATE(CDrawRobotView, CView)

BEGIN_MESSAGE_MAP(CDrawRobotView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawRobotView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawRobotView 构造/析构

CDrawRobotView::CDrawRobotView()
{
	// TODO: 在此处添加构造代码

}

CDrawRobotView::~CDrawRobotView()
{
}

BOOL CDrawRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawRobotView 绘制

void CDrawRobotView::OnDraw(CDC* pDC)
{
	CDrawRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	m_bitmap.LoadBitmap(IDB_BITMAP1); //从资源中装载入位图  

	pDC->SelectObject(&m_bitmap);            //选择位图对象  
	BITMAP bmInfo;
	m_bitmap.GetObject(sizeof(bmInfo), &bmInfo);    //获取位图信息  
													//将位图显示到视图中  
	pDC->BitBlt(0, 0, bmInfo.bmWidth, bmInfo.bmHeight, pDC, 0, 0, SRCCOPY);












}


// CDrawRobotView 打印


void CDrawRobotView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawRobotView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawRobotView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawRobotView 诊断

#ifdef _DEBUG
void CDrawRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawRobotDoc* CDrawRobotView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawRobotDoc)));
	return (CDrawRobotDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawRobotView 消息处理程序
