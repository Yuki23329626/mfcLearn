
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_LINE, &CMy403410016沈濃翔View::OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CMy403410016沈濃翔View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POINT, &CMy403410016沈濃翔View::OnUpdateDrawPoint)
	ON_COMMAND(ID_32789, &CMy403410016沈濃翔View::OnChDrawPoint)
	ON_COMMAND(ID_32790, &CMy403410016沈濃翔View::OnChDrawLine)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CMy403410016沈濃翔View::OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CMy403410016沈濃翔View::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_32789, &CMy403410016沈濃翔View::OnUpdateChDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_32790, &CMy403410016沈濃翔View::OnUpdateChDrawLine)
	ON_COMMAND(ID_32791, &CMy403410016沈濃翔View::OnChDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_32791, &CMy403410016沈濃翔View::OnUpdateChDrawEllipse)
	ON_COMMAND(ID_32792, &CMy403410016沈濃翔View::OnChColorRed)
	ON_UPDATE_COMMAND_UI(ID_32792, &CMy403410016沈濃翔View::OnUpdateChColorRed)
	ON_COMMAND(ID_32793, &CMy403410016沈濃翔View::OnChColorGreen)
	ON_UPDATE_COMMAND_UI(ID_32793, &CMy403410016沈濃翔View::OnUpdateChColorGreen)
	ON_COMMAND(ID_32794, &CMy403410016沈濃翔View::OnChColorBlue)
	ON_UPDATE_COMMAND_UI(ID_32794, &CMy403410016沈濃翔View::OnUpdateChColorBlue)
	ON_COMMAND(ID_32795, &CMy403410016沈濃翔View::OnChColorOther1)
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

		CPen pen(PS_SOLID, 5, pDoc->color);
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
}
void CMy403410016沈濃翔View::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(255, 0, 0));
}
void CMy403410016沈濃翔View::OnChColorRed()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(255, 0, 0);
}
void CMy403410016沈濃翔View::OnUpdateChColorRed(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(255, 0, 0));
}

// 選單_顏色_綠色
void CMy403410016沈濃翔View::OnColorGreen()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 255, 0);
}
void CMy403410016沈濃翔View::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(0, 255, 0));
}
void CMy403410016沈濃翔View::OnChColorGreen()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 255, 0);
}
void CMy403410016沈濃翔View::OnUpdateChColorGreen(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(0, 255, 0));
}

// 選單_顏色_藍色
void CMy403410016沈濃翔View::OnColorBlue()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 0, 255);
}
void CMy403410016沈濃翔View::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(0, 0, 255));
}
void CMy403410016沈濃翔View::OnChColorBlue()
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pDoc->color = RGB(0, 0, 255);
}
void CMy403410016沈濃翔View::OnUpdateChColorBlue(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->color == RGB(0, 0, 255));
}

// 其他顏色一
void CMy403410016沈濃翔View::OnChColorOther1()
{

}

// 選單_繪圖_點
void CMy403410016沈濃翔View::OnDrawPoint()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 0;
}
void CMy403410016沈濃翔View::OnUpdateDrawPoint(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 0);
}
void CMy403410016沈濃翔View::OnChDrawPoint()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 0;
}
void CMy403410016沈濃翔View::OnUpdateChDrawPoint(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 0);
}

// 選單_繪圖_線
void CMy403410016沈濃翔View::OnDrawLine()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 1;
}
void CMy403410016沈濃翔View::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 1);
}
void CMy403410016沈濃翔View::OnChDrawLine()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 1;
}
void CMy403410016沈濃翔View::OnUpdateChDrawLine(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 1);
}

// 選單_繪圖_橢圓
void CMy403410016沈濃翔View::OnDrawEllipse()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 2;
}
void CMy403410016沈濃翔View::OnUpdateDrawEllipse(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 2);
}
void CMy403410016沈濃翔View::OnChDrawEllipse()
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pDoc->shapenum = 2;
}
void CMy403410016沈濃翔View::OnUpdateChDrawEllipse(CCmdUI *pCmdUI)
{
	CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
	pCmdUI->SetCheck(pDoc->shapenum == 2);
}
