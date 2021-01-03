#pragma once
#include "CMapElement.h"
class CEllipseRegion :
    public CMapElement
{
public:
	void draw(CDC* pDC);//绘制图元
	int GetType();//返回图元类型

};

