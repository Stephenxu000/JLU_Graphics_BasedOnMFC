
// CGWORK0918View.h: CCGWORK0918View 类的接口
//

#pragma once


class CCGWORK0918View : public CView
{
protected: // 仅从序列化创建
	CCGWORK0918View() noexcept;
	DECLARE_DYNCREATE(CCGWORK0918View)

// 特性
public:
	CCGWORK0918Doc* GetDocument() const;
	int m_nType = 0;//绘制类型
	CPoint m_Oldpoint;
	CPoint m_Newpoint;
	CPoint Polygon_start_point;//多边形开始点
	bool Polygon_isstart = false;//记录是否开始多边形
	int r = 0, g = 0, b = 0;//记录当前颜色
	int fill_r = 0, fill_g = 0, fill_b = 0;//记录填充颜色
	int  Polygon_point_num = 0;
	int mask[15000][15000];//多边形轮廓线
	int Polygon_x1 = 0, Polygon_y1 = 0, Polygon_x2 = 0, Polygon_y2 = 0;//记录最大最小范围
	CPoint  Polygon_point[100];
	//填充种子
	int pattern[17][36] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
		1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
		1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,
		1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	bool m_pLMouseDown=false;
	

	//CArray<line,Line> list;
// 操作
public:
	void DDALine(CClientDC *dc, int x1, int y1, int x2, int y2);//绘制直线
	void DrawRectangle(CClientDC* dc, int x1, int y1, int x2, int y2);//绘制矩形
	void DrawEllipse(CClientDC* dc, CPoint point1, CPoint point2);//绘制圆形
	void MyAreaFilledPolygon(CClientDC* dc);//区域填充
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCGWORK0918View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnOndrawEllipse();
	afx_msg void OnOndrawLineto();
	afx_msg void OnOndrawRectangle();
	afx_msg void OnOndrawSetcolor();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAreaFilledPolygon();
	afx_msg void OnAreaFilledSetcolor();
};

#ifndef _DEBUG  // CGWORK0918View.cpp 中的调试版本
inline CCGWORK0918Doc* CCGWORK0918View::GetDocument() const
   { return reinterpret_cast<CCGWORK0918Doc*>(m_pDocument); }
#endif

