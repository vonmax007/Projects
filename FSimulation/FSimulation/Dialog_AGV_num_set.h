#pragma once
#include "afxwin.h"
#include "Resource.h"

// Dialog_AGV_num_set �Ի���

class Dialog_AGV_num_set : public CDialog
{
	DECLARE_DYNAMIC(Dialog_AGV_num_set)

public:
	Dialog_AGV_num_set(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog_AGV_num_set();

// �Ի�������
	enum { IDD = IDD_AGV_NUM_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_agv_num;
	CEdit m_agv_num_t;
	afx_msg void OnBnClickedOk_get_agv_num();
};
