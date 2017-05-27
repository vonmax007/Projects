// Dialog_Set_Time_Scale.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "Dialog_Set_Time_Scale.h"
#include "afxdialogex.h"


// Dialog_Set_Time_Scale �Ի���

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
	m_slider.SetRange(0,1000);//���û�����Χ
	m_slider.SetTicFreq(10);//ÿ10����λ��һ�̶�;

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


// Dialog_Set_Time_Scale ��Ϣ�������


void Dialog_Set_Time_Scale::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	m_edit_scale.GetWindowTextW(str);

	time_scale = _ttoi(str);//ת����int��ʽ;
	str = _T("��������ʱ���������Ϊ���� 1���� Ϊʵ��С�� ") + str + _T(" �� ");
	MessageBox(str);
	CDialog::OnOK();
}
