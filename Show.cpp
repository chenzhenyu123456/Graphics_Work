// Show.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "Show.h"
#include "afxdialogex.h"


// CShow �Ի���

IMPLEMENT_DYNAMIC(CShow, CDialogEx)

CShow::CShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShow::IDD, pParent)
{

}

CShow::~CShow()
{
}

void CShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShow, CDialogEx)
END_MESSAGE_MAP()


// CShow ��Ϣ�������


BOOL CShow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ModifyStyle(WS_SYSMENU, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
