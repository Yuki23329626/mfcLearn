
// 403410016沈濃翔View.h: CMy403410016沈濃翔View 類別的介面
//

#pragma once


class CMy403410016沈濃翔View : public CView
{
protected: // 僅從序列化建立
	CMy403410016沈濃翔View();
	DECLARE_DYNCREATE(CMy403410016沈濃翔View)

// 屬性
public:
	CMy403410016沈濃翔Doc* GetDocument() const;
	COLORREF color;


// 作業
public:

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
};

#ifndef _DEBUG  // 對 403410016沈濃翔View.cpp 中的版本進行偵錯
inline CMy403410016沈濃翔Doc* CMy403410016沈濃翔View::GetDocument() const
   { return reinterpret_cast<CMy403410016沈濃翔Doc*>(m_pDocument); }
#endif

