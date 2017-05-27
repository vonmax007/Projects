
// DrawRobotView.cpp : CDrawRobotView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawRobotView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawRobotView ����/����

CDrawRobotView::CDrawRobotView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawRobotView::~CDrawRobotView()
{
}

BOOL CDrawRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawRobotView ����

void CDrawRobotView::OnDraw(CDC* pDC)
{
	CDrawRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	m_bitmap.LoadBitmap(IDB_BITMAP1); //����Դ��װ����λͼ  

	pDC->SelectObject(&m_bitmap);            //ѡ��λͼ����  
	BITMAP bmInfo;
	m_bitmap.GetObject(sizeof(bmInfo), &bmInfo);    //��ȡλͼ��Ϣ  
													//��λͼ��ʾ����ͼ��  
	pDC->BitBlt(0, 0, bmInfo.bmWidth, bmInfo.bmHeight, pDC, 0, 0, SRCCOPY);












}


// CDrawRobotView ��ӡ


void CDrawRobotView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CDrawRobotView ���

#ifdef _DEBUG
void CDrawRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawRobotDoc* CDrawRobotView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawRobotDoc)));
	return (CDrawRobotDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawRobotView ��Ϣ�������
