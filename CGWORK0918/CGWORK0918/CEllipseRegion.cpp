#include "pch.h"
#include "CEllipseRegion.h"

void CEllipseRegion::draw(CDC* pDC)
{
	//获得椭圆区域的控制点
	CPoint sp = GetStartPoint();
	CPoint ep = GetEndPoint();
	//绘制椭圆区域
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 1, RGB(Element_r, Element_g, Element_b));
	CPen* poldpen = pDC->SelectObject(&newPen);
	pDC->Ellipse(sp.x, sp.y, ep.x, ep.y);
	pDC->SelectObject(poldpen);
	newPen.DeleteObject();
}

int CEllipseRegion::GetType()
{
	//返回图元类型为椭圆区域
	return 3;
}
