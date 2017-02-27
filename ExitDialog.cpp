// ExitDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "ExitDialog.h"
#include "afxdialogex.h"


// ExitDialog �Ի���

IMPLEMENT_DYNAMIC(ExitDialog, CDialogEx)

ExitDialog::ExitDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(ExitDialog::IDD, pParent)
{

}

ExitDialog::~ExitDialog()
{
}

void ExitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Sure, m_sure);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancle);
}


BEGIN_MESSAGE_MAP(ExitDialog, CDialogEx)
END_MESSAGE_MAP()


// ExitDialog ��Ϣ�������


BOOL ExitDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ModifyStyle(WS_SYSMENU, 0);
	//ModifyStyle(WS_CAPTION, 0);
	m_Font.CreatePointFont(150, _T("����"), NULL);
	m_sure.SetFont(&m_Font, true);

	m_Font1.CreatePointFont(100, _T("����"), NULL);
	m_ok.SetFont(&m_Font1, true);
	m_cancle.SetFont(&m_Font1, true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
