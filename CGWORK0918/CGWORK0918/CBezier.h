#pragma once
#include "CMapElement.h"

class CBezier :
    public CMapElement
{
public:
	void Bezier(CDC* pdc, CPoint  bezier[4]);
	void draw(CDC* pDC);//����ͼԪ
	int GetType();//����ͼԪ����
};

