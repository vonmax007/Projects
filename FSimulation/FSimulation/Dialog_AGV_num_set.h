#pragma once
#include "afxwin.h"
#include "Resource.h"

// Dialog_AGV_num_set 对话框

class Dialog_AGV_num_set : public CDialog
{
	DECLARE_DYNAMIC(Dialog_AGV_num_set)

public:
	Dialog_AGV_num_set(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialog_AGV_num_set();

// 对话框数据
	enum { IDD = IDD_AGV_NUM_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_agv_num;
	CEdit m_agv_num_t;
	afx_msg void OnBnClickedOk_get_agv_num();
};
