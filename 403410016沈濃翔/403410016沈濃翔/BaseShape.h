// BaseStruct.h :  基本幾何結構資料
#include "stdafx.h"


class Shape	//形狀類別的基礎類別
{
public:
	CPoint StartPnt, EndPnt, Prepoint;	//定義形狀的終點與起點
	int LineWidth;
	// BOOL Draw1;
	int shapenum;	//形狀代號
	COLORREF color;
public:
	//建構子
	Shape()
	{
		LineWidth = 1;
		color = RGB(255, 0, 0);
	}
	//過載=運算子
	Shape & operator= (Shape & s)
	{
		StartPnt = s.StartPnt;	//設定起點
		EndPnt = s.EndPnt;	//設定終點
		return *this;
	}
	virtual void draw(CDC & aDC, COLORREF color, COLORREF fcolor, int width, BOOL Filled = false) = 0;
	int GetShapeNum()	//取得形狀代號
	{
		return shapenum;
	}
	void SetPoint(CPoint SPnt, CPoint EPnt)	//設定形狀的起點、終點
	{
		StartPnt = SPnt;
		EndPnt = EPnt;
	}
};


class MyPoint
{
public:
	CPoint point;	//定義形狀的終點與起點
	COLORREF color;
	int shapenum;
	MyPoint()
	{
		color = RGB(255, 0, 0);
		shapenum = 1;
		point = (0, 0);

	}
};


class MyLine : public Shape	//直線類別
{
public:
	MyLine()
	{
		color = RGB(255, 0, 0);
		shapenum = 2;
		StartPnt = (0, 0);
	}

	//建構子
	MyLine(CPoint StartPnt2, CPoint EndPnt2, COLORREF color2)
	{
		color = color2;
		shapenum = 2;
		StartPnt = StartPnt2;
		EndPnt = EndPnt2;

	}
	//過載=運算子
	MyLine & operator= (MyLine & l)
	{
		StartPnt = l.StartPnt;
		color = l.color;
		LineWidth = l.LineWidth;
		EndPnt = l.EndPnt;
		shapenum = l.shapenum;
		return *this;
	}
	void draw(CDC &dc, COLORREF color, COLORREF fcolor,
		int width, BOOL Filled = false)
	{
		CPen pen(PS_SOLID, width, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
	void draw2(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
	void draw3(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);	//移至直線起點
		dc.LineTo(EndPnt);	//移至直線終點
		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}
};

class MyRectangle : public Shape	//矩形類別
{
public:
	BOOL Filled;
	COLORREF fcolor;
	MyRectangle()
	{
		color = RGB(255, 0, 0);
		shapenum = 3;
		StartPnt = (0, 0);
	}
	MyRectangle(CPoint StartPnt2, CPoint EndPnt2, COLORREF color2)
	{
		color = color2;
		shapenum = 2;
		StartPnt = StartPnt2;
		EndPnt = EndPnt2;
	}
	//過載=運算子
	MyRectangle & operator= (MyRectangle & l)	//過載=運算子
	{
		Filled = l.Filled;
		fcolor = l.fcolor;
		StartPnt = l.StartPnt;
		color = l.color;
		LineWidth = l.LineWidth;
		EndPnt = l.EndPnt;
		shapenum = l.shapenum;
		return *this;
	}
	void draw(CDC & dc, COLORREF color, COLORREF fcolor, int width, BOOL Filled = false)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, width, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			//  m_newbrush.CreateSolidBrush(RGB(0,255,255));
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 55, 55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}

	void draw2(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}

	void draw3(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Rectangle(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}
};


class MyEllipse : public Shape	//橢圓形類別
{
public:
	BOOL Filled;
	COLORREF fcolor;
	MyEllipse()
	{
		color = RGB(255, 0, 0);
		shapenum = 3;
		StartPnt = (0, 0);
		Filled = 0;
	}
	MyEllipse(CPoint StartPnt2, CPoint EndPnt2, COLORREF color2)
	{
		color = color2;
		shapenum = 2;
		StartPnt = StartPnt2;
		EndPnt = EndPnt2;
	}
	//過載=運算子
	MyEllipse & operator= (MyEllipse & l)	//過載=運算子
	{
		Filled = l.Filled;
		fcolor = l.fcolor;
		StartPnt = l.StartPnt;
		color = l.color;
		LineWidth = l.LineWidth;
		EndPnt = l.EndPnt;
		shapenum = l.shapenum;
		return *this;
	}
	void draw(CDC & dc, COLORREF color, COLORREF fcolor, int width, BOOL Filled = false)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, width, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			//  m_newbrush.CreateSolidBrush(RGB(0,255,255));
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 55, 55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}

	void draw2(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, color);	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}
	void draw3(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//建立CRect物件
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		}
		dc.Ellipse(rect);	//繪出矩形
		dc.SelectObject(oldPen);	//還原畫筆物件
									//	m_newbrush.DeleteObject();
	}
};


class PalletTemplate	//橢圓形類別
{
public:
	CString PalletName;
	CString Filepath;
	CArray <MyEllipse, MyEllipse &>    EArray;
	CArray <MyRectangle, MyRectangle &>    RArray;
	CArray <MyLine, MyLine &>    LArray;
	CArray <MyPoint, MyPoint &>    PArray;
	PalletTemplate & operator= (PalletTemplate & l)	//過載=運算子
	{
		PalletName = l.PalletName;
		Filepath = l.Filepath;
		for (int i = 0; i<l.EArray.GetCount(); i++)
		{

			EArray.Add(l.EArray[i]);

		}
		for (int i = 0; i<l.RArray.GetCount(); i++)
		{

			RArray.Add(l.RArray[i]);

		}
		for (int i = 0; i<l.EArray.GetCount(); i++)
		{

			EArray.Add(l.EArray[i]);

		}
		for (int i = 0; i<l.LArray.GetCount(); i++)
		{

			LArray.Add(l.LArray[i]);

		}
		return *this;
	}
	void draw2(CDC &dc)
	{
		CPen pen(PS_SOLID, 5, RGB(234, 237, 120));	//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);	//設定DC物件使用pen物件
		for (int i = 0; i<LArray.GetCount(); i++)
		{
			CPoint x = LArray[i].StartPnt;
			CPoint y = LArray[i].EndPnt;

			dc.MoveTo(LArray[i].StartPnt);	//移至直線起點
			dc.LineTo(LArray[i].EndPnt);	//移至直線起點

		}

		for (int i = 0; i<RArray.GetCount(); i++)
		{
			CRect rect(RArray[i].StartPnt, RArray[i].EndPnt);	//建立CRect物件
			dc.Rectangle(rect);	//繪出矩形

		}
		for (int i = 0; i<EArray.GetCount(); i++)
		{
			CRect rect(EArray[i].StartPnt, EArray[i].EndPnt);	//建立CRect物件
			dc.Ellipse(rect);
		}


		dc.SelectObject(oldPen);	//還原選取的畫筆物件
	}

};


//
//class MyLine 
//{
//public:
//	CPoint StartPnt, EndPnt,Prepoint;	//定義形狀的終點與起點
//    BOOL Draw1;
//	COLORREF color;
//	MyLine()
//	{
//		color = RGB(255, 0, 0);
//		StartPnt=(0,0);
//	}
// 
//};