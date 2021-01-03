#pragma once
#include "CMapElement.h"
class CEllipse :
    public CMapElement
{
public:
	void DrawEllipse(CDC* pdc, CPoint point1, CPoint point2);
	void draw(CDC* pDC);//绘制图元
	int GetType();//返回图元类型

};

