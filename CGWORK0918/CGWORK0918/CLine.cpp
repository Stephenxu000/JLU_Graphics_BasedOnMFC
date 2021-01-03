#include "pch.h"
#include "CLine.h"
void CLine::DDALine(CDC* pdc, int x1, int y1, int x2, int y2)
{
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e;
	dy /= e;
	x = x1;
	y = y1;
	for (int i = 1; i <= e; i++)
	{
		pdc->SetPixel((int)(x + 0.5), (int)(y + 0.5), RGB(Element_r, Element_g, Element_b));
		x += dx;
		y += dy;
	}
}
void CLine::draw(CDC* pDC)
{
	//绘制直线段
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 1, RGB(Element_r, Element_g, Element_b));
	CPen* poldpen = pDC->SelectObject(&newPen);
	/*pDC->MoveTo(GetStartPoint());
	pDC->LineTo(GetEndPoint());*/
	DDALine(pDC, GetStartPoint().x, GetStartPoint().y, GetEndPoint().x, GetEndPoint().y);
	pDC->SelectObject(poldpen);
	newPen.DeleteObject();
}

int CLine::GetType()
{
	//返回图元类型为直线段
	return 1;
}
