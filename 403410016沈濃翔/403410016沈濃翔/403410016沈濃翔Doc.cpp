
// 403410016沈濃翔Doc.cpp: CMy403410016沈濃翔Doc 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "403410016沈濃翔.h"
#endif

#include "403410016沈濃翔Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy403410016沈濃翔Doc

IMPLEMENT_DYNCREATE(CMy403410016沈濃翔Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy403410016沈濃翔Doc, CDocument)
END_MESSAGE_MAP()


// CMy403410016沈濃翔Doc 建構/解構

CMy403410016沈濃翔Doc::CMy403410016沈濃翔Doc()
{
	// TODO: 在此加入一次建構程式碼
	SetTitle("Document / Demo");
	color = RGB(255, 0, 0);
	shapenum = 0;
}

CMy403410016沈濃翔Doc::~CMy403410016沈濃翔Doc()
{
}

BOOL CMy403410016沈濃翔Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CMy403410016沈濃翔Doc 序列化

void CMy403410016沈濃翔Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此加入儲存程式碼
	}
	else
	{
		// TODO: 在此加入載入程式碼
	}
}

#ifdef SHARED_HANDLERS

// 縮圖的支援
void CMy403410016沈濃翔Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改這段程式碼以繪製文件的資料
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜尋處理常式的支援
void CMy403410016沈濃翔Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 設定來自文件資料的搜尋內容。
	// 內容部分應該以 ";" 隔開

	// 範例:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy403410016沈濃翔Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy403410016沈濃翔Doc 診斷

#ifdef _DEBUG
void CMy403410016沈濃翔Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy403410016沈濃翔Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy403410016沈濃翔Doc 命令
