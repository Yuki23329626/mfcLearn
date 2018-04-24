
// 403410016沈濃翔View.cpp: CMy403410016沈濃翔View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "403410016沈濃翔.h"
#endif

#include "403410016沈濃翔Doc.h"
#include "403410016沈濃翔View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy403410016沈濃翔View

IMPLEMENT_DYNCREATE(CMy403410016沈濃翔View, CView)

BEGIN_MESSAGE_MAP(CMy403410016沈濃翔View, CView)
	ON_COMMAND(ID_COLOR_RED, &CMy403410016沈濃翔View::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMy403410016沈濃翔View::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMy403410016沈濃翔View::OnColorBlue)
	ON_COMMAND(ID_DRAW_POINT, &CMy403410016沈濃翔View::OnDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CMy403410016沈濃翔View::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CMy403410016沈濃翔View::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CMy403410016沈濃翔View::OnUpdateColorBlue)
END_MESSAGE_MAP()

// CMy403410016沈濃翔View 建構/解構

CMy403410016沈濃翔View::CMy403410016沈濃翔View()
{
	// TODO: 在此加入建構程式碼
	color = RGB(255, 0, 0);
}

CMy403410016沈濃翔View::~CMy403410016沈濃翔View()
{
}

BOOL CMy403410016沈濃翔View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMy403410016沈濃翔View 繪圖

void CMy403410016沈濃翔View::OnDraw(CDC* /*pDC*/)
{
	CMy403410016沈濃翔Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}


// CMy403410016沈濃翔View 診斷

#ifdef _DEBUG
void CMy403410016沈濃翔View::AssertValid() const
{
	CView::AssertValid();
}

void CMy403410016沈濃翔View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy403410016沈濃翔Doc* CMy403410016沈濃翔View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy403410016沈濃翔Doc)));
	return (CMy403410016沈濃翔Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy403410016沈濃翔View 訊息處理常式


void CMy403410016沈濃翔View::OnColorRed()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color = RGB(255, 0, 0);
}


void CMy403410016沈濃翔View::OnColorGreen()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color = RGB(0, 255, 0);
}


void CMy403410016沈濃翔View::OnColorBlue()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color = RGB(0, 0, 255);
}


void CMy403410016沈濃翔View::OnDrawPoint()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMy403410016沈濃翔View *doc = (CMy403410016沈濃翔View *)GetDocument();

}


void CMy403410016沈濃翔View::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	pCmdUI->SetCheck(color == RGB(255, 0, 0));
}


void CMy403410016沈濃翔View::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	pCmdUI->SetCheck(color == RGB(0, 255, 0));
}


void CMy403410016沈濃翔View::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	pCmdUI->SetCheck(color == RGB(0, 0, 255));
}
