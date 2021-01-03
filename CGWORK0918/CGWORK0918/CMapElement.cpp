#include "pch.h"
#include "CMapElement.h"
void CMapElement::SetStartPoint(CPoint point)
{
	m_StartPoint = point;
}

void CMapElement::SetEndPoint(CPoint point)
{
	m_EndPoint = point;
}

CPoint CMapElement::GetStartPoint()
{
	return m_StartPoint;
}

CPoint CMapElement::GetEndPoint()
{
	return m_EndPoint;
}

void CMapElement::draw(CDC* pDC)
{

}

int CMapElement::GetType()
{
	return 0;
}

