#pragma once
#include "afxwin.h"


// CChooseDialog �Ի���

class CChooseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseDialog)

public:
	CChooseDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChooseDialog();

// �Ի�������
	enum { IDD = IDD_Choose };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit C_Cnumber;
	afx_msg void OnBnClickedCancle();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedOk();
	CString m_Vnumber;
};
