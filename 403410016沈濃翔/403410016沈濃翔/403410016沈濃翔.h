
// 403410016沈濃翔.h: 403410016沈濃翔 應用程式的主要標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CMy403410016沈濃翔App:
// 查看 403410016沈濃翔.cpp 以了解此類別的實作
//

class CMy403410016沈濃翔App : public CWinApp
{
public:
	CMy403410016沈濃翔App();


// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy403410016沈濃翔App theApp;
