#pragma once
#include "CMapElement.h"
class CLine :
    public CMapElement
{
public:
	void DDALine(CDC* pdc, int x1, int y1, int x2, int y2);
	void draw(CDC* pDC);//绘制图元
	int GetType();//返回图元类型

};

