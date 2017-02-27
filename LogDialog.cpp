// LogDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "LogDialog.h"
#include "afxdialogex.h"
#include "ExitDialog.h"

// CLogDialog �Ի���

IMPLEMENT_DYNAMIC(CLogDialog, CDialogEx)

CLogDialog::CLogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDialog::IDD, pParent)
{

}

CLogDialog::~CLogDialog()
{
}

void CLogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Teacher, m_teacher);
	DDX_Control(pDX, IDC_Student, m_student);
	DDX_Control(pDX, IDC_BUTTON1, m_enter);
	DDX_Control(pDX, IDC_Exit, m_exit);
	DDX_Control(pDX, IDC_Title, m_title);
}


BEGIN_MESSAGE_MAP(CLogDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogDialog::OnEnter)
	ON_BN_CLICKED(IDC_Exit, &CLogDialog::OnExit)
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLogDialog ��Ϣ�������

BOOL CLogDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//AnimateWindow(3000, AW_HOR_NEGATIVE | AW_SLIDE);//3���ڴ��ڴ������󵯳�
	//AnimateWindow(4000,AW_HIDE| AW_BLEND);
	ModifyStyle(WS_SYSMENU, 0); // ���عر���

	ModifyStyle(WS_CAPTION, 0); // ���ر���
	// ���ƾ�̬�ı������� �� ��С

	m_Font.CreatePointFont(150, _T("����"), NULL);
	m_teacher.SetFont(&m_Font, true);
	m_student.SetFont(&m_Font, true);

	m_Font1.CreatePointFont(100, _T("����"), NULL);
	m_enter.SetFont(&m_Font1, true);
	m_exit.SetFont(&m_Font1, true);

	m_Font2.CreatePointFont(200, _T("����"), NULL);
	m_title.SetFont(&m_Font2, true);
	//m_teacher.SetWindowText(_T("")); // ���þ�̬�ı�����
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}



void CLogDialog::OnEnter()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Enter = true;
	SendMessage(WM_CLOSE);
}


void CLogDialog::OnExit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SendMessage(WM_CLOSE);
}


HBRUSH CLogDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// ���ƾ�̬�ı�����ɫ�ͱ�����ɫ
	if (IDC_Teacher == pWnd->GetDlgCtrlID())//�жϷ�����Ϣ�Ŀռ��Ƿ��Ǹþ�̬�ı���
	{
		pDC->SetTextColor(RGB(255, 0, 0));//�����ı���ɫΪ��ɫ
		pDC->SetBkMode(OPAQUE);//�����ı�����ģʽΪ͸��
		//pDC->SetBkColor(RGB(0, 0, 255));//�����ı�����
		hbr = CreateSolidBrush(RGB(0, 255, 0));//�ؼ��ı���ɫΪ��ɫ
	}

	if (IDC_Student == pWnd->GetDlgCtrlID())//�жϷ�����Ϣ�Ŀռ��Ƿ��Ǹþ�̬�ı���
	{
		pDC->SetTextColor(RGB(255, 0, 0));//�����ı���ɫΪ��ɫ
		pDC->SetBkMode(OPAQUE);//�����ı�����ģʽΪ͸��
		//pDC->SetBkColor(RGB(0, 0, 255));//�����ı�����
		hbr = CreateSolidBrush(RGB(0, 255, 0));//�ؼ��ı���ɫΪ��ɫ
	}

	// TODO:  �ڴ˸��� DC ���κ�����

	// ���ñ���ͼƬ bmp��ʽ
	static CBrush gBr;
	static bool isInited = false;
	if (!isInited)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP2); // bmpͼƬ��ID
		gBr.CreatePatternBrush(&bitmap);
		COLORREF clearColor = -1;
		bitmap.DeleteObject();
		isInited = true;
	}
	if (pWnd == this)
	{
		pDC->SetBkMode(TRANSPARENT);
		return gBr; //�����ڱ���ʹ���������ˢ
	}
	else
	{
		pDC->SetBkMode(TRANSPARENT);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH); //�����ؼ�ʹ��͸������
	}


	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CLogDialog::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!Enter) {
		ExitDialog dlg;
		if (dlg.DoModal() == IDCANCEL) {
			return;
		}
	}
	CDialogEx::OnClose();
}
