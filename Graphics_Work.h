
// Graphics_Work.h : Graphics_Work Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGraphics_WorkApp:
// �йش����ʵ�֣������ Graphics_Work.cpp
//

class CGraphics_WorkApp : public CWinApp
{
public:
	CGraphics_WorkApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShow();
};

extern CGraphics_WorkApp theApp;
