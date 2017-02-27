
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Graphics_Work.h"

#include "MainFrm.h"
#include "LogDialog.h"
#include "ExitDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

bool Enter;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.ShowWindow(SW_HIDE);//���ع�����
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//ȫ����ʾ
	RECT rc;
	::GetWindowRect(::GetDesktopWindow(), &rc);
	this->MoveWindow(&rc);
	
	CLogDialog Dlg; // ��ʼ����
	Dlg.DoModal();

	SetTimer(1, 10, NULL);
	if (!Enter) {
		exit(0);
	}


	return 0;
}

 BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style &= ~FWS_ADDTOTITLE | WS_VISIBLE | WS_MAXIMIZE;//ȡ�������ϵ��ĵ�����
	cs.lpszName = _T("С�ͻ�ͼϵͳ"); // �ļ��Ϸ�����������
	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������
// �ֲ�
/*BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	m_splitter.CreateStatic(this, 1, 1); // ���������������ܳ���16
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CGraphics_WorkView), CSize(520, 600), pContext);
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	}
}
*/

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("��ǰʱ�� %H:%M:%S");

	CClientDC dc(this); 
	CSize sz = dc.GetTextExtent(str);
	int index = 0;
	index = m_wndStatusBar.CommandToIndex(ID_INDICATOR_NUM);
	m_wndStatusBar.SetPaneInfo(index, ID_INDICATOR_NUM, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(index, str);

	CMDIFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ExitDialog dlg;
	if (dlg.DoModal() == IDCANCEL) {
		return;
	}
	CMDIFrameWnd::OnClose();
}
