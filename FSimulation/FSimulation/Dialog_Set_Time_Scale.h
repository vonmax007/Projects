#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"

// Dialog_Set_Time_Scale �Ի���

class Dialog_Set_Time_Scale : public CDialog
{
	DECLARE_DYNAMIC(Dialog_Set_Time_Scale)

public:
	Dialog_Set_Time_Scale(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog_Set_Time_Scale();

// �Ի�������
	enum { IDD = IDD_DIALOG_SET_TIME_SCALE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	//�Զ��庯��;
	BOOL OnInitDialog();
public:
	CStatic m_satement;
	CSliderCtrl m_slider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CEdit m_edit_scale;
	int time_scale;
	afx_msg void OnBnClickedOk();
};
#pragma once


