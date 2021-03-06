
// 403410016沈濃翔Doc.h: CMy403410016沈濃翔Doc 類別的介面
//


#pragma once

class CMy403410016沈濃翔Doc : public CDocument
{
protected: // 僅從序列化建立
	CMy403410016沈濃翔Doc();
	DECLARE_DYNCREATE(CMy403410016沈濃翔Doc)

public:
	class Point {
		CPoint point;
		COLORREF color;
	public:
		CPoint GetPoint() {
			return point;
		}
		COLORREF GetColor() {
			return color;
		}
		void SetPoint(int x, int y) {
			point.x = x, point.y = y;
		}
		void SetColor(COLORREF inputColor) {
			color = inputColor;
		}
	};

	class Line {
	public:
		CPoint StartPoint, EndPoint, PrePoint;
		BOOL Draw1; // 做什麼用的??
		COLORREF color;

		Line() {
			color = RGB(255, 0, 0);
			StartPoint = (0, 0);
		}
		COLORREF GetColor() {
			return color;
		}
	};

	class Ellipse {
	public:
		CPoint startPoint, endPoint;
		COLORREF color;
	};

// 屬性
public:
	CArray<Point, Point &> pArray;
	CArray<Line, Line &> lArray;
	CArray<Ellipse, Ellipse &>eArray;
	COLORREF color;
	int shapenum;
// 作業
public:

	void AddPoint(Point point) {
		pArray.Add(point);
	}

	Point GetPoint(int i) {
		return pArray[i];
	}

	int GetSize() {
		return pArray.GetSize();
	}

	void RemoveAll() {
		pArray.RemoveAll();
		lArray.RemoveAll();
	}



// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 程式碼實作
public:
	virtual ~CMy403410016沈濃翔Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 為搜尋處理常式設定搜尋內容的 Helper 函式
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
