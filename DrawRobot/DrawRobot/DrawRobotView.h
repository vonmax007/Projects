
// DrawRobotView.h : CDrawRobotView ��Ľӿ�
//

#pragma once


class CDrawRobotView : public CView
{
protected: // �������л�����
	CDrawRobotView();
	DECLARE_DYNCREATE(CDrawRobotView)

// ����
public:
	CDrawRobotDoc* GetDocument() const;

// ����
public:
	CBitmap m_bitmap;          //λͼ�����



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
	virtual ~CDrawRobotView();
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
};

#ifndef _DEBUG  // DrawRobotView.cpp �еĵ��԰汾
inline CDrawRobotDoc* CDrawRobotView::GetDocument() const
   { return reinterpret_cast<CDrawRobotDoc*>(m_pDocument); }
#endif

