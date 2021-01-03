#pragma once
#include <afx.h>
#include <afxtempl.h>
class CMapElement :
    public CObject
{
private:
	CPoint m_StartPoint;//图元起始控制点
	CPoint m_EndPoint;//图元终止控制点

public:
	int Element_r = 0;
	int Element_g = 0;
	int Element_b = 0;
	CPoint Bezier[4];
	//设置图元起始控制点
	void SetStartPoint(CPoint point);
	//设置图元终止控制点
	void SetEndPoint(CPoint point);
	//获得图元起始控制点
	CPoint GetStartPoint();
	//获得图元终止控制点
	CPoint GetEndPoint();
	//绘制图元，由具体的图元子类覆盖实现
	virtual void draw(CDC* pDC);
	//获得图元类型，由具体的图元子类覆盖实现
	virtual int GetType();
};

