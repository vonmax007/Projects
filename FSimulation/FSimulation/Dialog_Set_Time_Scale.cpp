// Dialog_Set_Time_Scale.cpp : 实现文件
//

#include "stdafx.h"

#include "Dialog_Set_Time_Scale.h"
#include "afxdialogex.h"


// Dialog_Set_Time_Scale 对话框

IMPLEMENT_DYNAMIC(Dialog_Set_Time_Scale, CDialog)

Dialog_Set_Time_Scale::Dialog_Set_Time_Scale(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_Set_Time_Scale::IDD, pParent)
{
	
}

Dialog_Set_Time_Scale::~Dialog_Set_Time_Scale()
{
	
}

BOOL Dialog_Set_Time_Scale::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	
	time_scale = 10;
	m_slider.SetRange(0,1000);//设置滑动范围
	m_slider.SetTicFreq(10);//每10个单位画一刻度;

	return TRUE;  // return TRUE unless you set the focus to a control
               // EXCEPTION: OCX Property Pages should return FALSE
}

void Dialog_Set_Time_Scale::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_1, m_satement);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_EDIT1, m_edit_scale);
}




BEGIN_MESSAGE_MAP(Dialog_Set_Time_Scale, CDialog)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &Dialog_Set_Time_Scale::OnBnClickedOk)
END_MESSAGE_MAP()


// Dialog_Set_Time_Scale 消息处理程序


void Dialog_Set_Time_Scale::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CSliderCtrl *pSilder=(CSliderCtrl*)pScrollBar;  
	
	int ns = m_slider.GetPos();
	CString str;
	str.Format(_T("%d"), ns);
	//MessageBox(str);
	m_edit_scale.SetWindowTextW(str);
	UpdateData(TRUE);  
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Dialog_Set_Time_Scale::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit_scale.GetWindowTextW(str);

	time_scale = _ttoi(str);//转化成int形式;
	str = _T("您设置了时间放缩比例为程序 1毫秒 为实际小车 ") + str + _T(" 秒 ");
	MessageBox(str);
	CDialog::OnOK();
}
