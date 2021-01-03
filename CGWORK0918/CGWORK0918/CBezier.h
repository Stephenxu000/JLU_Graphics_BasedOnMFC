#pragma once
#include "CMapElement.h"

class CBezier :
    public CMapElement
{
public:
	void Bezier(CDC* pdc, CPoint  bezier[4]);
	void draw(CDC* pDC);//绘制图元
	int GetType();//返回图元类型
};

