#pragma once

#include "resource.h"
//�������Դ���ͱ���ΪZIPRES����WindowImplBase�Ķ���һ�£�������Ϊ������Դ����������Դ���ļ���

class CDYFrameWnd : public WindowImplBase
{
public:
	explicit CDYFrameWnd(LPCTSTR pszXMLPath) :strXMLPath_(pszXMLPath){};
	explicit CDYFrameWnd(){};

	virtual ~CDYFrameWnd();


	virtual LPCTSTR GetWindowClassName() const { return _T("Window"); }
	virtual CDuiString GetSkinFile()                { return _T("Window.xml"); }
	virtual CDuiString GetSkinFolder()              { return _T(""); }  //ΪUILIB_ZIPRESOURCEʱ���ò��������ʵ��
	virtual void  InitWindow();
	virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& /*bHandled*/);
	virtual void Notify(TNotifyUI& msg);
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual LPCTSTR GetResourceID() const
	{
		return MAKEINTRESOURCE(IDR_ZIP_SKIN);
	};
	virtual UILIB_RESOURCETYPE GetResourceType() const{ return UILIB_ZIPRESOURCE; };

protected:
	CDuiString strXMLPath_;

};