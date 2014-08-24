#include "stdafx.h"
#include "UIFrame.h"


CDYFrameWnd::~CDYFrameWnd()
{

}

void  CDYFrameWnd::InitWindow()
{

}

LRESULT CDYFrameWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	switch (uMsg)
	{

	case WM_TOUCH:
		MessageBoxA(GetHWND(),"get wm_touch message",NULL,MB_OK);

		break;
	default:
		break;
	}
//	__super::MessageHandler(uMsg,wParam,lParam,bHandled);
	return FALSE;
}

class WindowCallback:public IDialogBuilderCallback
{
	virtual CControlUI* CreateControl(LPCTSTR pstrClass)
	{
		if (_tcsicmp(pstrClass, _T("Window2")) == 0)
		{
			CDialogBuilder builderManualOpera;
			CControlUI* ptemp = builderManualOpera.Create(_T("Window2.xml"),NULL,NULL,NULL,NULL);
			return ptemp;
		}

		return NULL;
	};

};

CControlUI* CDYFrameWnd::CreateControl(LPCTSTR pstrClass)
{
	if (_tcsicmp(pstrClass, _T("Window1")) == 0)
	{
		WindowCallback bk;
		CDialogBuilder builderManualOpera;
		//	����GetPaintManager(),Window������Window1��sizeӰ��
		//CControlUI* pUIManualOpera_ = builderManualOpera.Create(_T("Window1.xml"), NULL, &bk, GetPaintManager(), NULL);
		CControlUI* pUIManualOpera_ = builderManualOpera.Create(_T("Window1.xml"), NULL, &bk, NULL, NULL);
		return pUIManualOpera_;
	}
	if (_tcsicmp(pstrClass, _T("Window2")) == 0)
	{
		CDialogBuilder builderManualOpera;
		CControlUI* ptemp = builderManualOpera.Create(_T("Window2.xml"));
		return ptemp;
	}

	return NULL;
}

void CDYFrameWnd::Notify(TNotifyUI& msg)
{
	char szInfo[128];
	if (msg.sType == DUI_MSGTYPE_COLORCHANGED)
	{
		
		DWORD color = msg.wParam;
		sprintf(szInfo, "ARGB=(%d,%d,%d,%d)", 0xFF & color >> 24, 0xFF & color >> 16, 0xFF & color >> 8, 0xFF & color);
		MessageBoxA(GetHWND(), szInfo,"��ɫ", MB_OK);
	}

	__super::Notify(msg);
}
