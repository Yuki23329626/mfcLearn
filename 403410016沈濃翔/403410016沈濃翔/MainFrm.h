
// MainFrm.h: CMainFrame 類別的介面
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 僅從序列化建立
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 屬性
public:
	CMenu ChMainMenu, EnMainMenu;

// 作業
public:
	afx_msg void OnExit(){
		MessageBox("It's time to stop.", "Stop Window", MB_ICONSTOP);
		DestroyWindow();
	}

// 覆寫
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 程式碼實作
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CStatusBar m_wndStatusBar;
	CToolTipCtrl m_wndtooltip;

// 產生的訊息對應函式
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSwitchEnMenu();
	afx_msg void OnSwitchChMenu();
protected:
	CToolBar m_wndToolBar;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
