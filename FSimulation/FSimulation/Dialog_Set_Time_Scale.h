#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"

// Dialog_Set_Time_Scale 对话框

class Dialog_Set_Time_Scale : public CDialog
{
	DECLARE_DYNAMIC(Dialog_Set_Time_Scale)

public:
	Dialog_Set_Time_Scale(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialog_Set_Time_Scale();

// 对话框数据
	enum { IDD = IDD_DIALOG_SET_TIME_SCALE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	//自定义函数;
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


