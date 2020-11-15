
// CGWORK0918View.cpp: CCGWORK0918View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CGWORK0918.h"
#endif

#include "CGWORK0918Doc.h"
#include "CGWORK0918View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "SetColor.h"
#include "SetFillColor.h"


// CCGWORK0918View

IMPLEMENT_DYNCREATE(CCGWORK0918View, CView)

BEGIN_MESSAGE_MAP(CCGWORK0918View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_Ondraw_Ellipse, &CCGWORK0918View::OnOndrawEllipse)
	ON_COMMAND(ID_Ondraw_Lineto, &CCGWORK0918View::OnOndrawLineto)
	ON_COMMAND(ID_Ondraw_Rectangle, &CCGWORK0918View::OnOndrawRectangle)
	ON_COMMAND(ID_Ondraw_Setcolor, &CCGWORK0918View::OnOndrawSetcolor)
//	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Area_Filled_Polygon, &CCGWORK0918View::OnAreaFilledPolygon)
	ON_COMMAND(ID_Area_Filled_Setcolor, &CCGWORK0918View::OnAreaFilledSetcolor)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DrawBezier, &CCGWORK0918View::OnDrawbezier)
	ON_COMMAND(ID_Clear, &CCGWORK0918View::OnClear)
END_MESSAGE_MAP()

// CCGWORK0918View 构造/析构

CCGWORK0918View::CCGWORK0918View() noexcept
{
	// TODO: 在此处添加构造代码

}

CCGWORK0918View::~CCGWORK0918View()
{
}

BOOL CCGWORK0918View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCGWORK0918View 绘图

void CCGWORK0918View::OnDraw(CDC* pDC)
{
	// TODO: 在此处为本机数据添加绘制代码
}


// CCGWORK0918View 打印

BOOL CCGWORK0918View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCGWORK0918View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCGWORK0918View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCGWORK0918View 诊断

#ifdef _DEBUG
void CCGWORK0918View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK0918View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK0918Doc* CCGWORK0918View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK0918Doc)));
	return (CCGWORK0918Doc*)m_pDocument;
}
#endif //_DEBUG


//图形学函数 不调用MFC中的集成函数 只用SetPixel函数

void CCGWORK0918View::DDALine(CClientDC *dc, int x1, int y1, int x2, int y2)
{
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e;
	dy /= e;
	x = x1;
	y = y1;
	for (int i = 1; i <= e; i++)
	{
		dc->SetPixel((int)(x + 0.5), (int)(y + 0.5), RGB(r, g, b));
		x += dx;
		y += dy;
	}
	
}

void CCGWORK0918View::DrawRectangle(CClientDC* dc, int x1, int y1, int x2, int y2) {
	DDALine(dc, x1, y1, x2, y1);
	DDALine(dc, x1, y1, x1, y2);
	DDALine(dc, x1, y2, x2, y2);
	DDALine(dc, x2, y1, x2, y2);
}

void CCGWORK0918View::DrawEllipse(CClientDC* dc, CPoint point1, CPoint point2) {
	double Ellipse_a = abs(point1.x - point2.x) / 2, Ellipse_b = abs(point1.y - point2.y) / 2;
	int x, y;
	double d1, d2;
	int detx = abs(point1.x + point2.x) / 2;
	int dety = abs(point1.y + point2.y) / 2;
	x = 0; y = Ellipse_b;
	d1 = Ellipse_b * Ellipse_b + Ellipse_a * Ellipse_a * (-Ellipse_b + 0.25);
	dc->SetPixel( x + detx, y + dety, RGB(r,g,b));
	while (Ellipse_b * Ellipse_b * (x + 1) < Ellipse_a * Ellipse_a * (y - 0.5)) {
		if (d1 < 0) {
			d1 += Ellipse_b * Ellipse_b * (2 * x + 3); x++;
		}
		else {
			d1 += (Ellipse_b * Ellipse_b * (2 * x + 3) + Ellipse_a * Ellipse_a * (-2 * y + 2)); x++; y--;
		}
		dc->SetPixel( detx + x, dety + y, RGB(r, g, b));
		dc->SetPixel( detx + x, dety - y, RGB(r, g, b));
		dc->SetPixel( detx - x, dety + y, RGB(r, g, b));
		dc->SetPixel( detx - x, dety - y, RGB(r, g, b));
	}
	d2 = Ellipse_b * Ellipse_b * (x + 0.5) * (x + 0.5) + Ellipse_a * Ellipse_a * (y - 1) * (y - 1) - Ellipse_a * Ellipse_a * Ellipse_b * Ellipse_b;
	while (y > 0) {
		if (d2 < 0) {
			d2 += Ellipse_b * Ellipse_b * (2 * x + 2) + Ellipse_a * Ellipse_a * (-2 * y + 3); x++; y--;
		}
		else {
			d2 += Ellipse_a * Ellipse_a * (-2 * y + 3); y--;
		}
		dc->SetPixel( detx + x, dety + y, RGB(r, g, b));
		dc->SetPixel( detx + x, dety - y, RGB(r, g, b));
		dc->SetPixel( detx - x, dety + y, RGB(r, g, b));
		dc->SetPixel( detx - x, dety - y, RGB(r, g, b));
	}
}

void CCGWORK0918View::MyAreaFilledPolygon(CClientDC* dc) {

	
	for (int i = Polygon_y1; i <= Polygon_y2; i++)
	{
		for (int j = Polygon_x1; j <= Polygon_x2; j++)
		{
			mask[i][j] = false;
		}
	}


	Polygon_point[Polygon_point_num].x = Polygon_point[0].x;
	Polygon_point[Polygon_point_num].y = Polygon_point[0].y;
	for (int i = 0; i < Polygon_point_num; i++)
	{
		double xs =Polygon_point[i].x;
		double dxs;
		int dys;
		if ((Polygon_point[i + 1].y -Polygon_point[i].y) != 0)
			dxs = (double)(Polygon_point[i + 1].x -Polygon_point[i].x) / (double)(Polygon_point[i + 1].y -Polygon_point[i].y);
		else
		{
			int x1 =Polygon_point[i].x;
			int x2 =Polygon_point[i + 1].x;
			if (x1 > x2)
			{
				x1 =Polygon_point[i + 1].x;
				x2 =Polygon_point[i].x;
			}
			for (int k = x1; k <= x2; k++)
				mask[Polygon_point[i].y][k] = !mask[Polygon_point[i].y][k];
			continue;
		}

		if ((Polygon_point[i + 1].y -Polygon_point[i].y) != 0)
			dys = abs(Polygon_point[i + 1].y -Polygon_point[i].y) / (Polygon_point[i + 1].y -Polygon_point[i].y);
		else
		{
			int y1 = Polygon_point[i].y;
			int y2 = Polygon_point[i + 1].y;
			if (y1 > y2)
			{
				y1 = Polygon_point[i + 1].y;
				y2 = Polygon_point[i].y;
			}
			for (int k = y1; k <= y2; k++)
				mask[k][Polygon_point[i].x] = !mask[k][Polygon_point[i].y];
			continue;
		}

		for (int j = Polygon_point[i].y; j != Polygon_point[i + 1].y; j = j + dys)
		{
			int Ixs = int(xs + 0.5);
			mask[j][Ixs] = !mask[j][Ixs];

			double x1;
			x1 = xs + dys * dxs;
			xs = x1;
		}
	}
	if ((Polygon_point[0].y - Polygon_point[1].y) * (Polygon_point[0].y - Polygon_point[Polygon_point_num - 1].y) > 0)
		mask[Polygon_point[0].y][Polygon_point[0].x] = false;
	for (int i = 1; i < Polygon_point_num; i++)
	{
		if ((Polygon_point[i].y - Polygon_point[i + 1].y) * (Polygon_point[i].y - Polygon_point[i - 1].y) > 0)
			mask[Polygon_point[i].y][Polygon_point[i].x] = false;
	}
	bool inside = false;
	for (int i = Polygon_y1; i <= Polygon_y2; i++)
	{
		inside = false;
		for (int j = Polygon_x1; j <= Polygon_x2; j++)
		{
			if (mask[i][j])
				inside = !inside;
			if (inside) {
				if (pattern[i % 26][j % 46] == 0)
							{
									dc->SetPixel(j, i, RGB(fill_r, fill_g, fill_b));
							}
			}
		}
	}
	return;
	//for (int y = y1; y <= y2; y++)
	//	for (int x = x1; x <= x2; x++)
	//		mask[y][x] = false; //形成轮廓线

	//Polygon_point[Polygon_point_num] = Polygon_start_point;
	//for (int i = 0; i < Polygon_point_num; i++) {
	//	double Ixs;
	//	double xs = Polygon_point[i].x;
	//	//double dxs = (Polygon_point[i + 1].x - Polygon_point[i].x) / (Polygon_point[i + 1].y - Polygon_point[i].y);
	//	//double dys = abs(Polygon_point[i + 1].y - Polygon_point[i].y) / (Polygon_point[i + 1].y - Polygon_point[i].y);
	//	double dxs, dys;
	//	if (Polygon_point[i + 1].y - Polygon_point[i].y != 0)
	//	{
	//		dxs = (Polygon_point[i + 1].x - Polygon_point[i].x) / (Polygon_point[i + 1].y - Polygon_point[i].y);
	//	}
	//	else {
	//		int x_max = Polygon_point[i].x;
	//		int x_min = Polygon_point[i + 1].x;
	//		if (x_max < x_min)
	//		{
	//			int temp = x_max;
	//			x_max = x_min;
	//			x_min = temp;
	//		}
	//		for (int k = x_min; k <= x_max; k++)
	//		{
	//			mask[Polygon_point[i].y][k] = !mask[Polygon_point[i].y][k];
	//		}
	//		continue;
	//	}
	//	if ((Polygon_point[i + 1].y - Polygon_point[i].y) != 0) {
	//		dys = abs(Polygon_point[i + 1].y - Polygon_point[i].y) / (Polygon_point[i + 1].y - Polygon_point[i].y);
	//	}
	//	else{
	//		int y_max = Polygon_point[i].y;
	//		int y_min = Polygon_point[i + 1].y;
	//		if (y_min > y_max)
	//		{
	//			int temp = y_max;
	//			y_max = y_min;
	//			y_min = temp;

	//		}
	//		for (int k = y_min; k <= y_max; k++)
	//			mask[k][Polygon_point[i].x] = !mask[k][Polygon_point[i].y];
	//		continue;
	//	}

	//	for (int j = Polygon_point[i].y; j != Polygon_point[i + 1].y; j = j + dys)
	//	{
	//		int Ixs = int(xs + 0.5);
	//		mask[j][Ixs] = !mask[j][Ixs];

	//		double x1;
	//		x1 = xs + dys * dxs;
	//		xs = x1;
	//	}
	//}
	//if ((Polygon_point[0].y - Polygon_point[1].y) * (Polygon_point[0].y - Polygon_point[Polygon_point_num - 1].y) > 0)
	//	mask[Polygon_point[0].y][Polygon_point[0].x] = false;
	//for (int i = 1; i < Polygon_point_num; i++)
	//{
	//	if ((Polygon_point[i].y - Polygon_point[i + 1].y) * (Polygon_point[i].y - Polygon_point[i - 1].y) > 0)
	//		mask[Polygon_point[i].y][Polygon_point[i].x] = false;
	//}
	//bool inside = false;
	//for (int y = y1; y <= y2; y++) {//按轮廓线填充
	//	 inside = false;
	//	for (int x = x1; x <= x2; x++) {
	//		if (mask[y][x])
	//			inside = !inside;
	//		if (inside)
	//			if (pattern[y % 17][x % 36] == 0)
	//			{
	//				dc->SetPixel(x, y, RGB(fill_r, fill_g, fill_b));
	//			}
	//			//else {
	//				//dc->SetPixel(x, y, RGB(255, 255, 255));
	//			//}
	//	}
	//}
}


void CCGWORK0918View::DrawpointRectangle_5(CClientDC* dc,CPoint p,int c_r,int c_g,int c_b ,double distance) {

	
	double x1, x2, y1, y2;
	x1 = p.x - distance/2;
	x2 = p.x + distance / 2;
	y1 = p.y - distance / 2;
	y2 = p.y + distance / 2;
	if (x1 < 0)
	{
		x1 = 0;
	}
	if (y1 < 0)
	{
		y1 = 0;
	}
	for (double x = x1; x < x2; x++)
	{
		for (double y = y1; y < y2; y++)
		{
			dc->SetPixel(x, y, RGB(c_r, c_g, c_b));
		}
	}
	
}

void CCGWORK0918View::DrawBezRectangle(CClientDC* dc, CPoint p[]) {
	for (int i = 0; i < 3; i++)
	{
		DDALine(dc, p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
	}
}

// CCGWORK0918View 消息处理程序

void CCGWORK0918View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	SetCapture(); //捕捉鼠标
	m_pLMouseDown = TRUE;//表示鼠标为按下的状态
	CRect rect;
	GetClientRect(&rect);//获得并保存用户区坐标
	ClientToScreen(&rect); //用用户区坐标重新计算屏幕坐标
	ClipCursor(&rect); //限制光标在用户区内
	m_Oldpoint = point;//保存光标的当前位置
	m_Newpoint = point;//存放画线的起始位置
	if (m_nType == 3 && Polygon_isstart == true)
	{

		CClientDC dc(this);
		CPen pen(PS_DOT, 1, RGB(r, g, b));
		CPen* Oldpen = dc.SelectObject(&pen);
		dc.SetROP2(R2_NOTXORPEN);
		DDALine(&dc, Polygon_point[Polygon_point_num - 1].x, Polygon_point[Polygon_point_num - 1].y, m_Oldpoint.x, m_Oldpoint.y);//消除之前画的线
		dc.SelectObject(Oldpen);
	}
	//}
	CView::OnLButtonDown(nFlags, point);
}



void CCGWORK0918View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pLMouseDown) {
		CClientDC dc(this);
		CPen pen(PS_DOT, 1, RGB(r, g, b));
		//CPen clear(PS_DOT, 1, RGB(0, 0, 0));
		CPen* Oldpen = dc.SelectObject(&pen);
		//CPen* clearpen = dc.SelectObject(&clear);
		dc.SetROP2(R2_NOTXORPEN);//设置绘图模式，以屏幕颜色的相反色绘图并上画笔
		switch (m_nType) {
		case 0:
			DDALine(&dc, m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);//消除之前画的线
			DDALine(&dc, m_Newpoint.x, m_Newpoint.y, point.x, point.y);//鼠标移动的橡皮线
			dc.SelectObject(Oldpen);
			break;
		case 1:
			//dc.Rectangle(m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);
			//dc.Rectangle(m_Newpoint.x, m_Newpoint.y, point.x, point.y);
			DrawRectangle(&dc, m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);//消除之前画的线
			DrawRectangle(&dc, m_Newpoint.x, m_Newpoint.y, point.x, point.y);//鼠标移动的橡皮线
			dc.SelectObject(Oldpen);
			break;
		case 2:
			DrawEllipse(&dc,m_Newpoint, m_Oldpoint);
			DrawEllipse(&dc, m_Newpoint, point);
			//dc.Ellipse(m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);
			//dc.SelectObject(clear);
			//dc.Ellipse(m_Newpoint.x, m_Newpoint.y, point.x, point.y);
			dc.SelectObject(Oldpen);
			break;
		case 3:
			DDALine(&dc, Polygon_point[Polygon_point_num-1].x,Polygon_point[Polygon_point_num - 1].y, m_Oldpoint.x, m_Oldpoint.y);//消除之前画的线
			DDALine(&dc, Polygon_point[Polygon_point_num - 1].x, Polygon_point[Polygon_point_num - 1].y, point.x, point.y);//鼠标移动的橡皮线
			dc.SelectObject(Oldpen);
			break;
		}
		m_Oldpoint = point; //存放当前鼠标位置
	}
	CView::OnMouseMove(nFlags, point);
}

//Cpen pen(PS_DOT,3,RGB(0,255,0);
// CPen *Oldpen=dc.SelectObject(&pen);
//dc.SelectObject(Oldpen);
void CCGWORK0918View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pLMouseDown)
	{
		m_pLMouseDown = FALSE;//标志鼠标释放
		ReleaseCapture();//释放鼠标捕捉
		ClipCursor(NULL);//使光标可以随意移动
		if (m_nType == 3)
		{
			
			CPen pen(PS_DOT, 1, RGB(r, g, b));
			CPen* Oldpen = dc.SelectObject(&pen);
			if (Polygon_isstart == false)
			{
				//m_Newpoint = point;
				Polygon_isstart = true;//开始
				Polygon_point[Polygon_point_num++] = point;
				Polygon_x1 = Polygon_x2 = point.x;
				Polygon_y1 = Polygon_y2 = point.y;
				Polygon_start_point = point;
				m_Oldpoint = point;
			}
			else {
				m_Newpoint = point;
				Polygon_point[Polygon_point_num++] = point;
				//更新范围
				if (Polygon_x1 > point.x)
				{
					Polygon_x1 = point.x;
				}
				if (Polygon_x2 < point.x)
				{
					Polygon_x2 = point.x;
				}
				if (Polygon_y1 > point.y)
				{
					Polygon_y1 = point.y;
				}
				if (Polygon_y2 < point.y)
				{
					Polygon_y2 = point.y;
				}
				DDALine(&dc, Polygon_point[Polygon_point_num - 1].x, Polygon_point[Polygon_point_num - 1].y, Polygon_point[Polygon_point_num - 2].x, Polygon_point[Polygon_point_num - 2].y);
				dc.SelectObject(Oldpen);
				m_Oldpoint = point;//更新旧点
			}
		}
		if (m_nType == 15) {

			if (bezier_num == 3) {
				//当前共有3个点 加入第四个点
				bezier[bezier_num++] = point;
				DrawpointRectangle_5(&dc, point, 0, 0, 0, 5);
				//四点连线 绘制控制多边形
				DrawBezRectangle(&dc, bezier);
				//绘制曲线
				dc.PolyBezier(bezier, 4);


			}
			else if (bezier_num <= 2) {
				bezier[bezier_num++] = point;
				DrawpointRectangle_5(&dc, point, 0, 0, 0, 5);
			}
			if(bezier_num==4) {
				//新的一条曲线 重新开始计数
				bezier_num = 0;
				for (int i = 0; i < 4; i++)
				{
					bezier[i] = NULL;
				}
			}
			/*if (m_nCount == 0) {
				CClientDC dc(this);
				for (i = 0; i < 4; i++) {
					newP[i].x = P[i].x;
					newP[i].y = P[i].y;
				}
				bez_to_points(newP, N, newbezier, npoints);
				for (int i = 0; i <= npoints; i++) {
					bezier[i].x = (int)newbezier[i].x;
					bezier[i].y = (int)newbezier[i].y;
				}
				dc.Polyline(bezier, npoints + 1);
			}*/
		}
	}
	CView::OnLButtonUp(nFlags, point);
}




void CCGWORK0918View::OnOndrawLineto()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 0;
	//Invalidate();//清屏
}


void CCGWORK0918View::OnOndrawRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 1;
	//Invalidate();
}

void CCGWORK0918View::OnOndrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 2;
	//Invalidate();
}

void CCGWORK0918View::OnOndrawSetcolor()
{
	// TODO: 在此添加命令处理程序代码
	SetColor dia;//构造对话框对象
	dia.m_r = r;
	dia.m_g = g;
	dia.m_b = b;//设置当前值到对话框中
	if (dia.DoModal() == IDOK) {
		r = dia.m_r; g = dia.m_g; b = dia.m_b;
	}
}

void CCGWORK0918View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_nType == 3)
	{
		if (Polygon_isstart == true)
		{
			Polygon_isstart = false;
			CClientDC dc(this);
			CPen pen(PS_DOT, 1, RGB(r, g, b));
			CPen* Oldpen = dc.SelectObject(&pen);
			DDALine(&dc, Polygon_point[Polygon_point_num - 1].x, Polygon_point[Polygon_point_num - 1].y, Polygon_point[0].x, Polygon_point[0].y);
			dc.SelectObject(Oldpen);
			MyAreaFilledPolygon(&dc);
			for (int i = 0; i <= Polygon_point_num; i++)
			{
				Polygon_point[i] = NULL;
			}
			Polygon_point_num = 0;

			m_Oldpoint = NULL;
			m_Newpoint = NULL;
			Polygon_start_point = NULL;
		}


	}
	CView::OnRButtonDown(nFlags, point);
}

//改成右键结束输入的原因：左键双击必然会导致左键单击导致一个点的输入。无法用橡皮线看。
//void CCGWORK0918View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	if (m_nType == 3)
//	{
//		if (Polygon_isstart == true)
//		{
//			Polygon_isstart = false;
//			CClientDC dc(this);
//			CPen pen(PS_DOT, 1, RGB(r, g, b));
//			CPen* Oldpen = dc.SelectObject(&pen);
//			DDALine(&dc, Polygon_point[Polygon_point_num - 1].x, Polygon_point[Polygon_point_num - 1].y, Polygon_point[0].x, Polygon_point[0].y);
//			//DDALine(&dc, m_Newpoint.x, m_Newpoint.y, Polygon_start_point.x, Polygon_start_point.y);
//			dc.SelectObject(Oldpen);
//			MyAreaFilledPolygon(&dc);
//				for (int i = 0; i <= Polygon_point_num; i++)
//				{
//					Polygon_point[i] = NULL;
//				}
//				Polygon_point_num = 0;
//				
//				m_Oldpoint = NULL;
//				m_Newpoint = NULL;
//				Polygon_start_point = NULL;
//		}
//		
//
//	}
//	
//	CView::OnLButtonDblClk(nFlags, point);
//}


void CCGWORK0918View::OnAreaFilledPolygon()
{
	
	m_nType = 3;
	Polygon_isstart = false;
	for (int i = 0; i <= Polygon_point_num; i++)
	{
		Polygon_point[i] = NULL;
	}
	Polygon_point_num = 0;

	m_Oldpoint = NULL;
	m_Newpoint = NULL;
	Polygon_start_point = NULL;
	//Invalidate();
	// TODO: 在此添加命令处理程序代码
}


void CCGWORK0918View::OnAreaFilledSetcolor()
{
	// TODO: 在此添加命令处理程序代码
	SetFillColor dia;//构造对话框对象
	dia.b_b = b;
	dia.b_g = g;
	dia.b_r = r;
	dia.f_b = fill_b;
	dia.f_g = fill_g;
	dia.f_r = fill_r;
	if (dia.DoModal() == IDOK) {//确定返回IDOK
		r = dia.b_r;
		g = dia.b_g;
		b = dia.b_b;
		fill_r = dia.f_r;
		fill_g = dia.f_g;
		fill_b = dia.f_b;
	}
}






void CCGWORK0918View::OnDrawbezier()
{
	m_nType = 15;
	// TODO: 在此添加命令处理程序代码


}



void CCGWORK0918View::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}
