#pragma once
#include "afxwin.h"


// ExitDialog �Ի���

class ExitDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ExitDialog)

public:
	ExitDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ExitDialog();

// �Ի�������
	enum { IDD = IDD_Exit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_sure;
	virtual BOOL OnInitDialog();
private:
	CFont m_Font, m_Font1;
public:
	CButton m_ok;
	CButton m_cancle;
};
