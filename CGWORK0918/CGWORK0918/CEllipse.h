#pragma once
#include "CMapElement.h"
class CEllipse :
    public CMapElement
{
public:
	void DrawEllipse(CDC* pdc, CPoint point1, CPoint point2);
	void draw(CDC* pDC);//����ͼԪ
	int GetType();//����ͼԪ����

};

