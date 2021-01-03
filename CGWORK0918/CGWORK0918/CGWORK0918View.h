
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
	typedef struct CPoint3 {
		LONG x;
		LONG y;
		LONG z;
	};//三维点
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
	int pattern[26][46] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	bool m_pLMouseDown=false;
	CPoint bezier[4];//记录bezier曲线四点
	int bezier_num = 0;//当前第几个点
	int cube_a = 250;//多边形边长的一半
	CPoint3 cube_point[8];//定义立方体
	CPoint cube_2Dpoint[8];//立方体的二维点
	int cube_length = 1;//移动距离
	bool if_init = false;
	int angle = 10;//旋转角度
	int* rot=new int[3];
	int* trans=new int[3];
	int cube_color[6][3] = {0};
	int cubetype=1;
	int cubefaces[6][4] = {
		{0,1,2,3},
		{7,6,5,4},
		{1,5,6,2},
		{0,3,7,4},
		{0,4,5,1},
		{3,2,6,7},
	};
	int cubestate;
	//CArray<line,Line> list;
// 操作
public:
	void DDALine(CClientDC *dc, int x1, int y1, int x2, int y2);//绘制直线
	void DrawRectangle(CClientDC* dc, int x1, int y1, int x2, int y2);//绘制矩形
	void DrawEllipse(CClientDC* dc, CPoint point1, CPoint point2);//绘制圆形
	void MyAreaFilledPolygon(CClientDC* dc);//多边形区域填充
	void DrawpointRectangle_5(CClientDC* dc,CPoint p, int c_r, int c_g, int c_b, double distance);//以控制点为中心画边长为x的小矩形。
	void DrawBezRectangle(CClientDC* dc, CPoint p[]);//绘制控制多边形
	void DrawCube(CClientDC* dc,int type);//绘制立方体
	void setCubePoint();//立方体点初始化
	void fillcubeface(CPoint* P, CClientDC* dc, int cube_r, int cube_g, int cube_b, int type);
	
	//void DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4, COLORREF c);
	double** cube_translate(double** t);
	double** cube_rotate(double** t);
	
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
	afx_msg
	void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnOndrawEllipse();
	afx_msg void OnOndrawLineto();
	afx_msg void OnOndrawRectangle();
	afx_msg void OnOndrawSetcolor();
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAreaFilledPolygon();
	afx_msg void OnAreaFilledSetcolor();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawbezier();
	afx_msg void OnClear();
//	afx_msg void OnDarwcube();
	afx_msg void OnDarwcube();
	afx_msg void OnCubeXPan();
	afx_msg void OnCubeYPan();
	afx_msg void OnCubeZPan();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetCube();
	afx_msg void OnChangecube();
	afx_msg void OnCubeRotX();
	afx_msg void OnCubeRotY();
	afx_msg void OnCubeRotZ();
};

#ifndef _DEBUG  // CGWORK0918View.cpp 中的调试版本
inline CCGWORK0918Doc* CCGWORK0918View::GetDocument() const
   { return reinterpret_cast<CCGWORK0918Doc*>(m_pDocument); }
#endif

