// BaseStruct.h :  �򥻴X�󵲺c���
#include "stdafx.h"


class Shape	//�Ϊ����O����¦���O
{
public:
	CPoint StartPnt, EndPnt, Prepoint;	//�w�q�Ϊ������I�P�_�I
	int LineWidth;
	// BOOL Draw1;
	int shapenum;	//�Ϊ��N��
	COLORREF color;
public:
	//�غc�l
	Shape()
	{
		LineWidth = 1;
		color = RGB(255, 0, 0);
	}
	//�L��=�B��l
	Shape & operator= (Shape & s)
	{
		StartPnt = s.StartPnt;	//�]�w�_�I
		EndPnt = s.EndPnt;	//�]�w���I
		return *this;
	}
	virtual void draw(CDC & aDC, COLORREF color, COLORREF fcolor, int width, BOOL Filled = false) = 0;
	int GetShapeNum()	//���o�Ϊ��N��
	{
		return shapenum;
	}
	void SetPoint(CPoint SPnt, CPoint EPnt)	//�]�w�Ϊ����_�I�B���I
	{
		StartPnt = SPnt;
		EndPnt = EPnt;
	}
};


class MyPoint
{
public:
	CPoint point;	//�w�q�Ϊ������I�P�_�I
	COLORREF color;
	int shapenum;
	MyPoint()
	{
		color = RGB(255, 0, 0);
		shapenum = 1;
		point = (0, 0);

	}
};


class MyLine : public Shape	//���u���O
{
public:
	MyLine()
	{
		color = RGB(255, 0, 0);
		shapenum = 2;
		StartPnt = (0, 0);
	}

	//�غc�l
	MyLine(CPoint StartPnt2, CPoint EndPnt2, COLORREF color2)
	{
		color = color2;
		shapenum = 2;
		StartPnt = StartPnt2;
		EndPnt = EndPnt2;

	}
	//�L��=�B��l
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
		CPen pen(PS_SOLID, width, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);	//���ܪ��u�_�I
		dc.LineTo(EndPnt);	//���ܪ��u���I
		dc.SelectObject(oldPen);	//�٭������e������
	}
	void draw2(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);	//���ܪ��u�_�I
		dc.LineTo(EndPnt);	//���ܪ��u���I
		dc.SelectObject(oldPen);	//�٭������e������
	}
	void draw3(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);	//���ܪ��u�_�I
		dc.LineTo(EndPnt);	//���ܪ��u���I
		dc.SelectObject(oldPen);	//�٭������e������
	}
};

class MyRectangle : public Shape	//�x�����O
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
	//�L��=�B��l
	MyRectangle & operator= (MyRectangle & l)	//�L��=�B��l
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
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, width, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			//  m_newbrush.CreateSolidBrush(RGB(0,255,255));
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 55, 55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Rectangle(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}

	void draw2(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Rectangle(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}

	void draw3(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Rectangle(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}
};


class MyEllipse : public Shape	//�������O
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
	//�L��=�B��l
	MyEllipse & operator= (MyEllipse & l)	//�L��=�B��l
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
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, width, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			//  m_newbrush.CreateSolidBrush(RGB(0,255,255));
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 55, 55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Ellipse(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}

	void draw2(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, color);	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			//	m_newbrush.CreateHatchBrush(HS_FDIAGONAL,RGB(0,55,55));
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Ellipse(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}
	void draw3(CDC & dc)
	{
		CRect rect(StartPnt, EndPnt);	//�إ�CRect����
		CBrush m_newbrush;
		CPen pen(PS_SOLID, LineWidth, RGB(0, 0, 0));	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����

		if (Filled)
		{
			m_newbrush.CreateSolidBrush(fcolor);
			dc.SelectObject(&m_newbrush);
		}
		else
		{
			dc.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		}
		dc.Ellipse(rect);	//ø�X�x��
		dc.SelectObject(oldPen);	//�٭�e������
									//	m_newbrush.DeleteObject();
	}
};


class PalletTemplate	//�������O
{
public:
	CString PalletName;
	CString Filepath;
	CArray <MyEllipse, MyEllipse &>    EArray;
	CArray <MyRectangle, MyRectangle &>    RArray;
	CArray <MyLine, MyLine &>    LArray;
	CArray <MyPoint, MyPoint &>    PArray;
	PalletTemplate & operator= (PalletTemplate & l)	//�L��=�B��l
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
		CPen pen(PS_SOLID, 5, RGB(234, 237, 120));	//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);	//�]�wDC����ϥ�pen����
		for (int i = 0; i<LArray.GetCount(); i++)
		{
			CPoint x = LArray[i].StartPnt;
			CPoint y = LArray[i].EndPnt;

			dc.MoveTo(LArray[i].StartPnt);	//���ܪ��u�_�I
			dc.LineTo(LArray[i].EndPnt);	//���ܪ��u�_�I

		}

		for (int i = 0; i<RArray.GetCount(); i++)
		{
			CRect rect(RArray[i].StartPnt, RArray[i].EndPnt);	//�إ�CRect����
			dc.Rectangle(rect);	//ø�X�x��

		}
		for (int i = 0; i<EArray.GetCount(); i++)
		{
			CRect rect(EArray[i].StartPnt, EArray[i].EndPnt);	//�إ�CRect����
			dc.Ellipse(rect);
		}


		dc.SelectObject(oldPen);	//�٭������e������
	}

};


//
//class MyLine 
//{
//public:
//	CPoint StartPnt, EndPnt,Prepoint;	//�w�q�Ϊ������I�P�_�I
//    BOOL Draw1;
//	COLORREF color;
//	MyLine()
//	{
//		color = RGB(255, 0, 0);
//		StartPnt=(0,0);
//	}
// 
//};