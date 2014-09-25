// RichList.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "RichList.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��


// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);




int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	CPaintManagerUI::SetInstance(hInstance);

	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;

	CRichListWnd* pFrame = new CRichListWnd;
	if( pFrame == NULL ) return 0;
	pFrame->Create(NULL, _T("DuiLib Dem"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 500, 400);
	pFrame->CenterWindow();
	::ShowWindow(pFrame->GetHWND(), SW_SHOW);
	//�ڴ�й¶���
	_CrtDumpMemoryLeaks();
	pFrame->ShowModal();


	::CoUninitialize();
	return 0;

}
//////////////////////////////////////////////////////////////////////////

DUI_BEGIN_MESSAGE_MAP(CRichListWnd, WindowImplBase)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK,OnClick)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED,OnSelectChanged)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK,OnItemClick)
	DUI_END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////
	LPCTSTR CRichListWnd::GetWindowClassName( void ) const
{
	return _T("RichListWnd");
}

void CRichListWnd::OnFinalMessage( HWND hWnd)
{
	__super::OnFinalMessage(hWnd);
	delete this;
}

void CRichListWnd::Notify( TNotifyUI &msg )
{
	return WindowImplBase::Notify(msg);
}

void CRichListWnd::InitWindow()
{

}

LRESULT CRichListWnd::OnMouseHover(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
	CControlUI* pHover = m_PaintManager.FindControl(pt);
	if( pHover == NULL ) return 0;
	/*��ʾ��ͣ�������б��ͼ����ʱ����̬�任����ͼ��״̬��ʾ*/
	if(pHover->GetName() == _T("down_ico"))
	{
		MessageBox(NULL, _T("�����ĳ�ؼ����簴ť����ͣ�󣬶�Ŀ��ؼ�����������ı���״̬ͼ���С"), _T("DUILIB DEMO"), MB_OK);
		((CButtonUI *)pHover)->ApplyAttributeList(
			_T("normalimage=\"file='downlist_pause.png' dest='15,9,32,26'\""));                
	}
	return 0;
}


UILIB_RESOURCETYPE CRichListWnd::GetResourceType() const
{
	return UILIB_FILE;
}

void CRichListWnd::OnItemClick( TNotifyUI &msg )
{
	TCHAR alert_msg[64] = {0};
	int index = ((CListContainerElementUI *)msg.pSender)->GetIndex();
	wsprintf(alert_msg, _T("ѡ������%d, ���ұ����ڵ�������Ŀ��..."), index);
	MessageBox(NULL, alert_msg, _T("DUILIB DEMO"), MB_OK);            

	CControlUI *find_ctrl =m_PaintManager.FindSubControlByName(msg.pSender, _T("down_name"));

	if(find_ctrl)
	{
		MessageBox(NULL, 
			find_ctrl->GetText()+_T(" ѡ���е�������Ŀ����.."), 
			_T("DUILIB DEMO"), MB_OK);   
		((CLabelUI *)find_ctrl)->SetText(_T("�ɳ���̬���ú������..."));
	}
	else
	{
		MessageBox(NULL, _T("��������δΪ�ؼ�����name�����Ҳ���Ҫ�����Ŀؼ�"), 
			_T("DUILIB DEMO"), MB_OK);   
	}

	find_ctrl =m_PaintManager.FindSubControlByName(msg.pSender, _T("down_progress"));

	if(find_ctrl)
	{
		TCHAR alert_msg[256] = {0};
		wsprintf(alert_msg, _T("������ֵ:%d"), ((CProgressUI *)find_ctrl)->GetValue());
		MessageBox(NULL, alert_msg, _T("DUILIB DEMO"), MB_OK);   

		((CProgressUI *)find_ctrl)->SetValue(30);
		MessageBox(NULL, _T("�޸��˽�����ֵ"), _T("DUILIB DEMO"), MB_OK);   
	}
}


void CRichListWnd::OnSelectChanged( TNotifyUI &msg )
{
	if(msg.pSender->GetName() == _T("down_list"))
	{
		static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab_main")))->SelectItem(0);
	}
	else if(msg.pSender->GetName() == _T("down_his"))
	{
		static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab_main")))->SelectItem(1);
	}
}