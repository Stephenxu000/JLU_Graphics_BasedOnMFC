#include "pch.h"
#include "CEllipse.h"
void CEllipse::DrawEllipse(CDC* pdc, CPoint point1, CPoint point2) {
	double Ellipse_a = abs(point1.x - point2.x) / 2, Ellipse_b = abs(point1.y - point2.y) / 2;
	int x, y;
	double d1, d2;
	int detx = abs(point1.x + point2.x) / 2;
	int dety = abs(point1.y + point2.y) / 2;
	x = 0; y = Ellipse_b;
	d1 = Ellipse_b * Ellipse_b + Ellipse_a * Ellipse_a * (-Ellipse_b + 0.25);
	pdc->SetPixel(x + detx, y + dety, RGB(Element_r, Element_g, Element_b));
	while (Ellipse_b * Ellipse_b * (x + 1) < Ellipse_a * Ellipse_a * (y - 0.5)) {
		if (d1 < 0) {
			d1 += Ellipse_b * Ellipse_b * (2 * x + 3); x++;
		}
		else {
			d1 += (Ellipse_b * Ellipse_b * (2 * x + 3) + Ellipse_a * Ellipse_a * (-2 * y + 2)); x++; y--;
		}
		pdc->SetPixel(detx + x, dety + y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx + x, dety - y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx - x, dety + y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx - x, dety - y, RGB(Element_r, Element_g, Element_b));
	}
	d2 = Ellipse_b * Ellipse_b * (x + 0.5) * (x + 0.5) + Ellipse_a * Ellipse_a * (y - 1) * (y - 1) - Ellipse_a * Ellipse_a * Ellipse_b * Ellipse_b;
	while (y > 0) {
		if (d2 < 0) {
			d2 += Ellipse_b * Ellipse_b * (2 * x + 2) + Ellipse_a * Ellipse_a * (-2 * y + 3); x++; y--;
		}
		else {
			d2 += Ellipse_a * Ellipse_a * (-2 * y + 3); y--;
		}
		pdc->SetPixel(detx + x, dety + y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx + x, dety - y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx - x, dety + y, RGB(Element_r, Element_g, Element_b));
		pdc->SetPixel(detx - x, dety - y, RGB(Element_r, Element_g, Element_b));
	}
}
void CEllipse::draw(CDC* pDC)
{
	//获得椭圆的控制点
	CPoint sp = GetStartPoint();
	CPoint ep = GetEndPoint();
	//绘制椭圆边界线
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 1, RGB(Element_r, Element_g, Element_b));
	CPen* poldpen = pDC->SelectObject(&newPen);
	DrawEllipse(pDC, sp, ep);
	/*pDC->Arc(sp.x, sp.y, ep.x, ep.y, sp.x, sp.y, ep.x, ep.y);
	pDC->Arc(sp.x, sp.y, ep.x, ep.y, ep.x, ep.y, sp.x, sp.y);*/
	pDC->SelectObject(poldpen);
	newPen.DeleteObject();
}

int CEllipse::GetType()
{
	//返回图元类型为椭圆
	return 2;
}
