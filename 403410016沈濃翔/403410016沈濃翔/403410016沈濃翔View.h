
// 403410016沈濃翔View.h: CMy403410016沈濃翔View 類別的介面
//

#pragma once

#include "MainFrm.h"


class CMy403410016沈濃翔View : public CView
{
protected: // 僅從序列化建立
	CMy403410016沈濃翔View();
	DECLARE_DYNCREATE(CMy403410016沈濃翔View)

// 屬性
public:
	CMy403410016沈濃翔Doc* GetDocument() const;


// 作業
public:
	afx_msg void OnLButtonDown(UINT, CPoint point) {
		SetCapture();

		// 取得目前 Document 物件的指標
		CMy403410016沈濃翔Doc *pDoc = GetDocument();
		
		if (pDoc->shapenum == 1) { // 直線繪圖，取起點
			CMy403410016沈濃翔Doc::Line line;
			line.StartPoint = point;
			line.color = pDoc->color;
			pDoc->lArray.Add(line);
		}
		else if (pDoc->shapenum == 2) { //橢圓繪圖，取起點
			CMy403410016沈濃翔Doc::Ellipse ellipse;
			ellipse.startPoint = point;
			ellipse.color = pDoc->color;
			pDoc->eArray.Add(ellipse);
		}
	}
	afx_msg void OnMouseMove(UINT, CPoint point) {
		CString currentMousePosition;
		currentMousePosition.Format("X:%4d, Y:%4d", point.x, point.y);
		((CMainFrame*)GetParentFrame())->m_wndStatusBar.SetPaneText(3, currentMousePosition);
		if (this == GetCapture()) {
			CClientDC aDC(this);
			//aDC.Ellipse(point.x - 3, point.y - 3, point.x + 3, point.y + 3);

			// 取得目前 Document 物件的指標
			CMy403410016沈濃翔Doc *pDoc = (CMy403410016沈濃翔Doc *)GetDocument();
			if (pDoc->shapenum == 0) {
				aDC.SetPixel(point, pDoc->color);

				// 將軌跡點加入 Document 物件中
				CMy403410016沈濃翔Doc::Point myPoint;
				myPoint.SetPoint(point.x, point.y);
				myPoint.SetColor(pDoc->color);
				pDoc->AddPoint(myPoint);
			}
		}
	}
	afx_msg void OnLButtonUp(UINT, CPoint point) {
		ReleaseCapture();
		CMy403410016沈濃翔Doc *pDoc = GetDocument(); // 取得目前 Document 物件的指標

		// 是否選擇使用直線繪圖(shapenum == 1)
		if (pDoc->shapenum == 1) { // 直線繪圖
			CClientDC aDC(this);
			pDoc->lArray[pDoc->lArray.GetSize() - 1].EndPoint = point;

			CPen pen(PS_SOLID, 5, pDoc->color);
			CPen *oldPen = aDC.SelectObject(&pen);
			aDC.MoveTo(pDoc->lArray[pDoc->lArray.GetSize() - 1].StartPoint);
			aDC.LineTo(point);
		}
		else if (pDoc->shapenum == 2) { // 橢圓繪圖
			CClientDC aDC(this);// 這是什麼?
			pDoc->eArray[pDoc->eArray.GetSize() - 1].endPoint = point;

			CPoint startPoint = pDoc->eArray[pDoc->eArray.GetSize() - 1].startPoint;
			CRect rect(startPoint, point);

			CPen pen(PS_SOLID, 5, pDoc->color);
			CPen *oldPen = aDC.SelectObject(&pen);
			aDC.SelectStockObject(HOLLOW_BRUSH);
			aDC.Ellipse(rect);
		}
	}

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 程式碼實作
public:
	virtual ~CMy403410016沈濃翔View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnDrawPoint();
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawPoint(CCmdUI *pCmdUI);
	afx_msg void OnChDrawPoint();
	afx_msg void OnChDrawLine();
	afx_msg void OnDrawEllipse();
	afx_msg void OnUpdateDrawEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateChDrawPoint(CCmdUI *pCmdUI);
	afx_msg void OnUpdateChDrawLine(CCmdUI *pCmdUI);
	afx_msg void OnChDrawEllipse();
	afx_msg void OnUpdateChDrawEllipse(CCmdUI *pCmdUI);
	afx_msg void OnChColorRed();
	afx_msg void OnUpdateChColorRed(CCmdUI *pCmdUI);
	afx_msg void OnChColorGreen();
	afx_msg void OnUpdateChColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnChColorBlue();
	afx_msg void OnUpdateChColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnChColorOther1();
	afx_msg void OnColorOther1();
	afx_msg void OnColorOther2();
	afx_msg void OnUpdateColorOther1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateChColorOther1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorOther2(CCmdUI *pCmdUI);
	afx_msg void OnChColorOther2();
	afx_msg void OnUpdateChColorOther2(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // 對 403410016沈濃翔View.cpp 中的版本進行偵錯
inline CMy403410016沈濃翔Doc* CMy403410016沈濃翔View::GetDocument() const
   { return reinterpret_cast<CMy403410016沈濃翔Doc*>(m_pDocument); }
#endif

