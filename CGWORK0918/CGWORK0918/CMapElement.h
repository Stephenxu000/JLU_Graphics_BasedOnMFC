#pragma once
#include <afx.h>
#include <afxtempl.h>
class CMapElement :
    public CObject
{
private:
	CPoint m_StartPoint;//ͼԪ��ʼ���Ƶ�
	CPoint m_EndPoint;//ͼԪ��ֹ���Ƶ�

public:
	int Element_r = 0;
	int Element_g = 0;
	int Element_b = 0;
	CPoint Bezier[4];
	//����ͼԪ��ʼ���Ƶ�
	void SetStartPoint(CPoint point);
	//����ͼԪ��ֹ���Ƶ�
	void SetEndPoint(CPoint point);
	//���ͼԪ��ʼ���Ƶ�
	CPoint GetStartPoint();
	//���ͼԪ��ֹ���Ƶ�
	CPoint GetEndPoint();
	//����ͼԪ���ɾ����ͼԪ���า��ʵ��
	virtual void draw(CDC* pDC);
	//���ͼԪ���ͣ��ɾ����ͼԪ���า��ʵ��
	virtual int GetType();
};

