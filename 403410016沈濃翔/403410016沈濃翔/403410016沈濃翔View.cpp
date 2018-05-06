
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
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy403410016沈濃翔View

IMPLEMENT_DYNCREATE(CMy403410016沈濃翔View, CView)

BEGIN_MESSAGE_MAP(CMy403410016沈濃翔View, CView)
	// ToolBar Menu
	ON_COMMAND(ID_DrawPoint, &CMy403410016沈濃翔View::OnDrawPoint)
	ON_COMMAND(ID_DrawLine, &CMy403410016沈濃翔View::OnDrawLine)
	ON_COMMAND(ID_DrawEllipse, &CMy403410016沈濃翔View::OnDrawEllipse)
	ON_COMMAND(ID_ColorRed, &CMy403410016沈濃翔View::OnColorRed)
	ON_COMMAND(ID_ColorGreen, &CMy403410016沈濃翔View::OnColorGreen)
	ON_COMMAND(ID_ColorBlue, &CMy403410016沈濃翔View::OnColorBlue)
	ON_COMMAND(ID_ColorX, &CMy403410016沈濃翔View::OnColorOther1)
	ON_COMMAND(ID_ColorY, &CMy403410016沈濃翔View::OnColorOther2)
	ON_UPDATE_COMMAND_UI(ID_DrawPoint, &CMy403410016沈濃翔View::OnUpdateDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_DrawLine, &CMy403410016沈濃翔View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DrawEllipse, &CMy403410016沈濃翔View::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_ColorRed, &CMy403410016沈濃翔View::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_ColorGreen, &CMy403410016沈濃翔View::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_ColorBlue, &CMy403410016沈濃翔View::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_ColorX, &CMy403410016沈濃翔View::OnUpdateColorOther1)
	ON_UPDATE_COMMAND_UI(ID_ColorY, &CMy403410016沈濃翔View::OnUpdateColorOther2)

	// Menu
	ON_COMMAND(ID_DRAW_POINT, &CMy403410016沈濃翔View::OnDrawPoint)
	ON_COMMAND(ID_32789, &CMy403410016沈濃翔View::OnDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POINT, &CMy403410016沈濃翔View::OnUpdateDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_32789, &CMy403410016沈濃翔View::OnUpdateDrawPoint)

	ON_COMMAND(ID_DRAW_LINE, &CMy403410016沈濃翔View::OnDrawLine)
	ON_COMMAND(ID_32790, &CMy403410016沈濃翔View::OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CMy403410016沈濃翔View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_32790, &CMy403410016沈濃翔View::OnUpdateDrawLine)

	ON_COMMAND(ID_DRAW_ELLIPSE, &CMy403410016沈濃翔View::OnDrawEllipse)
	ON_COMMAND(ID_32791, &CMy403410016沈濃翔View::OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CMy403410016沈濃翔View::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_32791, &CMy403410016沈濃翔View::OnUpdateDrawEllipse)

	ON_COMMAND(ID_COLOR_RED, &CMy403410016沈濃翔View::OnColorRed)
	ON_COMMAND(ID_32792, &CMy403410016沈濃翔View::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CMy403410016沈濃翔View::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_32792, &CMy403410016沈濃翔View::OnUpdateColorRed)

	ON_COMMAND(ID_COLOR_GREEN, &CMy403410016沈濃翔View::OnColorGreen)
	ON_COMMAND(ID_32793, &CMy403410016沈濃翔View::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CMy403410016沈濃翔View::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_32793, &CMy403410016沈濃翔View::OnUpdateColorGreen)

	ON_COMMAND(ID_COLOR_BLUE, &CMy403410016沈濃翔View::OnColorBlue)
	ON_COMMAND(ID_32794, &CMy403410016沈濃翔View::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CMy403410016沈濃翔View::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_32794, &CMy403410016沈濃翔View::OnUpdateColorBlue)
	
	ON_COMMAND(ID_32795, &CMy403410016沈濃翔View::OnColorOther1)
	ON_COMMAND(ID_32795, &CMy403410016沈濃翔View::OnColorOther1)
	ON_UPDATE_COMMAND_UI(ID_COLOR_OTHER1, &CMy403410016沈濃翔View::OnUpdateColorOther1)
	ON_UPDATE_COMMAND_UI(ID_32795, &CMy403410016沈濃翔View::OnUpdateColorOther1)

	ON_COMMAND(ID_COLOR_OTHER3, &CMy403410016沈濃翔View::OnColorOther2)
	ON_COMMAND(ID_32796, &CMy403410016沈濃翔View::OnColorOther2)
	ON_UPDATE_COMMAND_UI(ID_COLOR_OTHER3, &CMy403410016沈濃翔View::OnUpdateColorOther2)
	ON_UPDATE_COMMAND_UI(ID_32796, &CMy403410016沈濃翔View::OnUpdateColorOther2)

	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()

END_MESSAGE_MAP()

// CMy403410016沈濃翔View 建構/解構

CMy403410016沈濃翔View::CMy403410016沈濃翔View()
{
	// TODO: 在此加入建構程式碼
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

void CMy403410016沈濃翔View::OnDraw(CDC* pDC)
{
	// 取得目前 Document 物件的指標
	CMy403410016沈濃翔Doc* pDoc = GetDocument();
	CString drawStyle;
	switch (pDoc->shapenum)
	{
	case 0:
		drawStyle = "Point";
		break;
	case 1:
		drawStyle = "Line";
		break;
	case 2:
		drawStyle = "Ellipse";
		break;
	default:
		break;
	}
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, drawStyle);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 重繪點
	for (int i = 0; i < pDoc->pArray.GetSize(); i++) {
		CPoint point;
		point.SetPoint(pDoc->GetPoint(i).GetPoint().x, pDoc->GetPoint(i).GetPoint().y);
		pDC->SetPixel(point, pDoc->GetPoint(i).GetColor());
	}

	// 重繪直線
	for (int i = 0; i < pDoc->lArray.GetSize(); i++) {
		CPen pen(PS_SOLID, 5, pDoc->color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->MoveTo(pDoc->lArray.GetAt(i).StartPoint);
		pDC->LineTo(pDoc->lArray.GetAt(i).EndPoint);
	}

	// 重繪橢圓
	for (int i = 0; i < pDoc->eArray.GetSize(); i++) {
		int height = abs(pDoc->eArray.GetAt(i).startPoint.y - pDoc->eArray.GetAt(i).endPoint.y);
		int length = abs(pDoc->eArray.GetAt(i).startPoint.x - pDoc->eArray.GetAt(i).endPoint.x);
		CPoint center = CPoint((pDoc->eArray.GetAt(i).startPoint.x + pDoc->eArray.GetAt(i).endPoint.x) / 2,
			(pDoc->eArray.GetAt(i).startPoint.y + pDoc->eArray.GetAt(i).endPoint.y) / 2);

		CPen pen(PS_SOLID, 5, pDoc->eArray.GetAt(i).color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->SelectStockObject(HOLLOW_BRUSH);
		pDC->Ellipse(center.x - length / 2, center.y - height / 2, center.x + length / 2, center.y + height / 2);
	}
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
// 選單_顏色_紅色
void CMy403410016沈濃翔View::OnColorRed()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(255, 0, 0);
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Color Red");
}
void CMy403410016沈濃翔View::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	if (pDoc->shapenum == 2) {
		pCmdUI->Enable(0);
	} else pCmdUI->SetCheck(pDoc->color == RGB(255, 0, 0));
}

// 選單_顏色_綠色
void CMy403410016沈濃翔View::OnColorGreen()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 255, 0);
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Color Green");
}
void CMy403410016沈濃翔View::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	if (pDoc->shapenum == 0) { // If draw point is enabled.
		pCmdUI->Enable(0);
	}
	else pCmdUI->SetCheck(pDoc->color == RGB(0, 255, 0));
}

// 選單_顏色_藍色
void CMy403410016沈濃翔View::OnColorBlue()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 0, 255);
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Color Blue");
}
void CMy403410016沈濃翔View::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	if (pDoc->shapenum == 2) {
		pCmdUI->Enable(0);
	}
	else pCmdUI->SetCheck(pDoc->color == RGB(0, 0, 255));
}

// Menu Other Color 1 (Orange)
void CMy403410016沈濃翔View::OnColorOther1()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(255, 115, 0);
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Color Other 1");
}
void CMy403410016沈濃翔View::OnUpdateColorOther1(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	if (pDoc->shapenum == 0) { // If draw point is enabled.
		pCmdUI->Enable(0);
	} else if (pDoc->shapenum == 2) {
		pCmdUI->Enable(0);
	}
	else pCmdUI->SetCheck(pDoc->color == RGB(255, 115, 0));
}


// Menu Command Other Color 2 (Brown)
void CMy403410016沈濃翔View::OnColorOther2()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(127, 67, 7);
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Color Other2");
}
void CMy403410016沈濃翔View::OnUpdateColorOther2(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	if (pDoc->shapenum == 0) { // If draw point is enabled.
		pCmdUI->Enable(0);
	}
	else pCmdUI->SetCheck(pDoc->color == RGB(127, 67, 7));
}

// 選單_繪圖_點
void CMy403410016沈濃翔View::OnDrawPoint()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 0;
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Draw Point");
}
void CMy403410016沈濃翔View::OnUpdateDrawPoint(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 0);
}

// 選單_繪圖_線
void CMy403410016沈濃翔View::OnDrawLine()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 1;
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Draw Line");
}
void CMy403410016沈濃翔View::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 1);
}

// 選單_繪圖_橢圓
void CMy403410016沈濃翔View::OnDrawEllipse()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 2;
	((CMainFrame *)GetParentFrame())->m_wndStatusBar.SetPaneText(4, "Draw Ellipse");
}
void CMy403410016沈濃翔View::OnUpdateDrawEllipse(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	if ((pDoc->shapenum != 0) || (pDoc->color != RGB(0, 0, 255))) {
		pCmdUI->Enable(0);
	} else pCmdUI->SetCheck(pDoc->shapenum == 2);
}
