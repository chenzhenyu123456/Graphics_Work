#pragma once
#include "afxwin.h"


// CLogDialog �Ի���

class CLogDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDialog)

public:
	CLogDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogDialog();

// �Ի�������
	enum { IDD = IDD_LogDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_teacher;
	CStatic m_student;
	virtual BOOL OnInitDialog();
private:
	CFont m_Font, m_Font1, m_Font2;
public:
	afx_msg void OnEnter();
	afx_msg void OnExit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_enter;
	CButton m_exit;
	afx_msg void OnClose();
	CStatic m_title;
};

extern bool Enter;