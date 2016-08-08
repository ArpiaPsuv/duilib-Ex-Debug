#include "stdafx.h"
#include "WKEWebkitBrowserWnd.h"



int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    //ʵ���������Ⱦ�����
    CPaintManagerUI::SetInstance(hInstance);

    //Initializes the COM library on the current thread and identifies,��ʼ��COM��, Ϊ����COM���ṩ֧��
    HRESULT Hr = ::CoInitialize(NULL);
    if (FAILED(Hr))
    {
        return 0;
    }

    WKEWebkitBrowserWnd pFrame;
    pFrame.Create(NULL, _T("*UIWindows"), UI_WNDSTYLE_FRAME, 0);
    pFrame.CenterWindow();

    //	������Ӱ

    CShadowWindow shadowwnd;
    CShadowWindow::Initialize(hInstance);
    shadowwnd.Create(pFrame.GetHWND());
    shadowwnd.SetSize(4);
    shadowwnd.SetPosition(4,4);
    shadowwnd.SetColor(RGB(22,22,22));

    pFrame.ShowModal();


    //�˳������ͷ�COM��
    ::CoUninitialize();

    return 0;
}