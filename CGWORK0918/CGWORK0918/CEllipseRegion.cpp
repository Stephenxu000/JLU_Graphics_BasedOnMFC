#include "pch.h"
#include "CEllipseRegion.h"

void CEllipseRegion::draw(CDC* pDC)
{
	//�����Բ����Ŀ��Ƶ�
	CPoint sp = GetStartPoint();
	CPoint ep = GetEndPoint();
	//������Բ����
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 1, RGB(Element_r, Element_g, Element_b));
	CPen* poldpen = pDC->SelectObject(&newPen);
	pDC->Ellipse(sp.x, sp.y, ep.x, ep.y);
	pDC->SelectObject(poldpen);
	newPen.DeleteObject();
}

int CEllipseRegion::GetType()
{
	//����ͼԪ����Ϊ��Բ����
	return 3;
}
