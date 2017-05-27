// Dialog_AGV_num_set.cpp : 实现文件
//

#include "stdafx.h"
#include "FSimulation.h"
#include "Dialog_AGV_num_set.h"
#include "afxdialogex.h"


// Dialog_AGV_num_set 对话框

IMPLEMENT_DYNAMIC(Dialog_AGV_num_set, CDialog)

Dialog_AGV_num_set::Dialog_AGV_num_set(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_AGV_num_set::IDD, pParent)
	, m_agv_num(_T(""))
{

}

Dialog_AGV_num_set::~Dialog_AGV_num_set()
{
}

void Dialog_AGV_num_set::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_agv_num);
	DDX_Control(pDX, IDC_EDIT1, m_agv_num_t);
}


BEGIN_MESSAGE_MAP(Dialog_AGV_num_set, CDialog)
	ON_BN_CLICKED(IDOK, &Dialog_AGV_num_set::OnBnClickedOk_get_agv_num)
END_MESSAGE_MAP()


// Dialog_AGV_num_set 消息处理程序


void Dialog_AGV_num_set::OnBnClickedOk_get_agv_num()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}
