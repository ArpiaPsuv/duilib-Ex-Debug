#include "stdafx.h"
#include "UIFrame.h"


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//ʵ���������Ⱦ�����
	CPaintManagerUI::SetInstance(hInstance);
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   // ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��

	//Initializes the COM library on the current thread and identifies,��ʼ��COM��, Ϊ����COM���ṩ֧��
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	CDYFrameWnd *pFrame = new CDYFrameWnd();
	pFrame->Create(NULL, _T("*UIWindows"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->ShowWindow();
	pFrame->CenterWindow();
	pFrame->ShowModal();

	//�˳������ͷ�COM��
	getchar();
	::CoUninitialize();

	return 0;
}