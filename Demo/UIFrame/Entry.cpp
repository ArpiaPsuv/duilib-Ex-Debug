#include "stdafx.h"
#include "UIFrame.h"


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

	//CDYFrameWnd *pFrame = new CDYFrameWnd();
	//pFrame->Create(NULL, _T("*UIWindows"), UI_WNDSTYLE_FRAME, 0);
	//pFrame->ShowWindow();
	//pFrame->CenterWindow();
	//pFrame->ShowModal();

	CDYFrameWnd pFrame;
	pFrame.Create(NULL, _T("*UIWindows"), UI_WNDSTYLE_FRAME, 0);
	pFrame.ShowWindow();
	pFrame.CenterWindow();
	pFrame.ShowModal();
	//�˳������ͷ�COM��
	
	::CoUninitialize();

	return 0;
}