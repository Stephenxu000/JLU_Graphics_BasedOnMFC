#pragma once
#include "CMapElement.h"
class CLine :
    public CMapElement
{
public:
	void DDALine(CDC* pdc, int x1, int y1, int x2, int y2);
	void draw(CDC* pDC);//����ͼԪ
	int GetType();//����ͼԪ����

};

