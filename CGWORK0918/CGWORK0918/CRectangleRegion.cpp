#include "pch.h"
#include "CRectangleRegion.h"
void CRectangleRegion::DDALine(CDC* pdc, int x1, int y1, int x2, int y2)
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

void CRectangleRegion::DrawRectangle(CDC* pdc, int x1, int y1, int x2, int y2) {
	DDALine(pdc, x1, y1, x2, y1);
	DDALine(pdc, x1, y1, x1, y2);
	DDALine(pdc, x1, y2, x2, y2);
	DDALine(pdc, x2, y1, x2, y2);
}
void CRectangleRegion::draw(CDC* pDC)
{
	//获得矩形区域控制点
	CPoint sp = GetStartPoint();
	CPoint ep = GetEndPoint();
	//绘制矩形区域
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 1, RGB(Element_r, Element_g, Element_b));
	CPen* poldpen = pDC->SelectObject(&newPen);
	DrawRectangle(pDC, sp.x, sp.y, ep.x, ep.y);
	pDC->SelectObject(poldpen);
	newPen.DeleteObject();
}

int CRectangleRegion::GetType()
{
	//返回图元类型为矩形区域
	return 4;
}
