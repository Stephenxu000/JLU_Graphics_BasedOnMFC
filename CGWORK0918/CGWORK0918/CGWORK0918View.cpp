
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
#include "Setcube.h"
#include "CLine.h"
#include "CEllipse.h"
#include "CEllipseRegion.h"
#include "CRectangleRegion.h"

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
//	ON_COMMAND(ID_DarwCube, &CCGWORK0918View::OnDarwcube)
ON_COMMAND(ID_DarwCube, &CCGWORK0918View::OnDarwcube)
ON_COMMAND(ID_cube_x_pan, &CCGWORK0918View::OnCubeXPan)
ON_COMMAND(ID_cube_y_pan, &CCGWORK0918View::OnCubeYPan)
ON_COMMAND(ID_cube_z_pan, &CCGWORK0918View::OnCubeZPan)
ON_WM_KEYDOWN()
ON_COMMAND(ID_Set_cube, &CCGWORK0918View::OnSetCube)
ON_COMMAND(ID_changecube, &CCGWORK0918View::OnChangecube)
ON_COMMAND(ID_cube_rot_x, &CCGWORK0918View::OnCubeRotX)
ON_COMMAND(ID_cube_rot_y, &CCGWORK0918View::OnCubeRotY)
ON_COMMAND(ID_cube_rot_z, &CCGWORK0918View::OnCubeRotZ)
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
	CCGWORK0918Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//循环图元列表

	for (int i = 0; i < pDoc->m_MapList.GetSize(); i++)
	{
		//获得图元列表中的图元子类指针并将其造型成图元基类指针
		CMapElement* pMap = (CMapElement*)pDoc->m_MapList.GetAt(i);
		//调用draw函数绘制图元
	
		pMap->draw(pDC);
		//dc.SelectObject(Oldpen);
	}
	CClientDC dc(this);
	if (m_nType == 4) {
		DrawCube(&dc, cubetype);
	}

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
}


void CCGWORK0918View::DrawpointRectangle_5(CClientDC* dc,CPoint p,int c_r,int c_g,int c_b ,double distance) {

	//CPen pen(PS_DOT, 1, RGB(c_r, c_g, c_b));
	//CPen* Oldpen = dc->SelectObject(&pen);
	//dc->SetROP2(R2_NOTXORPEN);//设置绘图模式，以屏幕颜色的相反色绘图并上画笔
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
			/*dc->SelectObject(Oldpen);*/
		}
	}
	
}

void CCGWORK0918View::DrawBezRectangle(CClientDC* dc, CPoint p[]) {
	for (int i = 0; i < 3; i++)
	{
		DDALine(dc, p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
	}
}
void CCGWORK0918View::setCubePoint()//设置立方体顶点坐标
{
	cube_point[0].x= -cube_a;cube_point[0].y = cube_a; cube_point[0].z = cube_a;
	cube_point[1].x = cube_a; cube_point[1].y = cube_a; cube_point[1].z = cube_a;
	cube_point[2].x = cube_a; cube_point[2].y = -cube_a; cube_point[2].z = cube_a;
	cube_point[3].x = -cube_a; cube_point[3].y = -cube_a; cube_point[3].z = cube_a;
	cube_point[4].x = -cube_a; cube_point[4].y = cube_a; cube_point[4].z = -cube_a;
	cube_point[5].x = cube_a; cube_point[5].y = cube_a; cube_point[5].z = -cube_a;
	cube_point[6].x = cube_a; cube_point[6].y = -cube_a; cube_point[6].z = -cube_a;
	cube_point[7].x = -cube_a; cube_point[7].y =-cube_a; cube_point[7].z = -cube_a;
}
//void CCGWORK0918View::DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4, COLORREF c) {
//	CClientDC dc(this);
//
//	dc.MoveTo(P1);
//	dc.LineTo(P2);
//	dc.LineTo(P3);
//	dc.LineTo(P4);
//	dc.LineTo(P1);
//	CPen cPen;//生明画笔
//	dc.SetROP2(R2_COPYPEN);
//	cPen.CreatePen(PS_DASH, 1, c);
//	dc.SelectObject(&cPen);
//	dc.LineTo(P3);
//	//	dc.Rectangle(P1.x,P1.y,P3.x,P3.y);
//	cPen.DeleteObject();
//	CBrush brush;
//	brush.CreateSolidBrush(RGB(0, 0, 0));
//	CBrush* oldbrush = dc.SelectObject(&brush);
//	dc.SelectObject(&brush);
//	dc.SelectObject(oldbrush);
//	//dc.SelectObject(oldbrush);
//}
double** CCGWORK0918View::cube_translate(double** t) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++)
			t[i][j] += trans[j];
	}
	return t;
}
double** CCGWORK0918View::cube_rotate(double** t) {
	double Trigono[3][2];
	double tmp[3];
	double arc;
	int i, j;
	for (i = 0; i < 3; i++) {
		arc = (rot[i] * 3.1415926) / 180;
		Trigono[i][0] = sin(arc);
		Trigono[i][1] = cos(arc);
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++)//X轴
			tmp[j] = t[i][j];
		t[i][1] = tmp[1] * Trigono[0][1] - tmp[2] * Trigono[0][0];
		t[i][2] = tmp[1] * Trigono[0][0] + tmp[2] * Trigono[0][1];

		for (j = 0; j < 3; j++)//Y轴
			tmp[j] = t[i][j];
		t[i][2] = tmp[2] * Trigono[1][1] - tmp[0] * Trigono[1][0];
		t[i][0] = tmp[0] * Trigono[1][1] + tmp[2] * Trigono[1][0];

		for (j = 0; j < 3; j++)//Z轴
			tmp[j] = t[i][j];
		t[i][0] = tmp[0] * Trigono[2][1] - tmp[1] * Trigono[2][0];
		t[i][1] = tmp[0] * Trigono[2][0] + tmp[1] * Trigono[2][1];
	}
	return t;
}
void CCGWORK0918View::fillcubeface(CPoint* P, CClientDC* dc, int cube_r, int cube_g, int cube_b, int type) {
	int xl, xr, yt, yd;
	bool flag;
	int i, j, k;
	for (i = 0; i < 4; i++) {
		DDALine(dc, P[i].x, P[i].y,P[i + 1].x, P[i + 1].y);
	}
	if (!type)
		return;
	xl = P[0].x;
	xr = P[0].x;
	yt = P[0].y;
	yd = P[0].y;

	for (i = 0; i < 4; i++) {
		if (P[i].x < xl)
			xl = P[i].x;
		if (P[i].x > xr)
			xr = P[i].x;
		if (P[i].y < yt)
			yt = P[i].y;
		if (P[i].y > yd)
			yd = P[i].y;
	}
	CPoint Vect[4];
	int Consts[4];
	for (i = 0; i < 4; i++) {
		Vect[i].x = P[i + 1].x - P[i].x;
		Vect[i].y = P[i + 1].y - P[i].y;
		Consts[i] = P[i].y * Vect[i].x - P[i].x * Vect[i].y;
	}
	for (i = yt; i <= yd; i++)
		for (j = xl; j <= xr; j++) {
			flag = true;
			for (k = 0; k < 4; k++)
				if (Vect[k].y * j - Vect[k].x * i + Consts[k] > 0) {
					flag = false;
					break;
				}
			if (flag)
				dc->SetPixel(j, i, RGB(cube_r,cube_g,cube_b));
		}
}
void CCGWORK0918View::DrawCube(CClientDC* dc,int type) {
	
	/*for (int i = 0; i < 8; i++) {
		DrawpointRectangle_5(dc, cube_2Dpoint[i], i*50, i*45, i*100, 10);
	}
	DrawRect(cube_2Dpoint[0], cube_2Dpoint[4], cube_2Dpoint[7], cube_2Dpoint[3], RGB(cube_color[0][1], cube_color[0][2], cube_color[0][3]));
	DrawRect(cube_2Dpoint[1], cube_2Dpoint[5], cube_2Dpoint[6], cube_2Dpoint[2], RGB(cube_color[1][1], cube_color[1][2], cube_color[1][3]));
	DrawRect(cube_2Dpoint[0], cube_2Dpoint[4], cube_2Dpoint[5], cube_2Dpoint[1], RGB(cube_color[2][1], cube_color[2][2], cube_color[2][3]));
	DrawRect(cube_2Dpoint[3], cube_2Dpoint[7], cube_2Dpoint[6], cube_2Dpoint[2], RGB(cube_color[3][1], cube_color[3][2], cube_color[3][3]));
	DrawRect(cube_2Dpoint[0], cube_2Dpoint[3], cube_2Dpoint[2], cube_2Dpoint[1], RGB(cube_color[4][1], cube_color[4][2], cube_color[4][3]));
	DrawRect(cube_2Dpoint[4], cube_2Dpoint[7], cube_2Dpoint[6], cube_2Dpoint[5], RGB(cube_color[5][1], cube_color[5][2], cube_color[5][3]));*/
	CPoint projPoints[8];
	int isVisible[6] = { 1,1,1,1,1,1 };
	CPoint* P = new CPoint[5];
	int i, j, D, x0, y0, x1, x2, y1, y2;
	CRect Rect;
	GetClientRect(&Rect);
	x0 = (Rect.left + Rect.right) / 2;
	y0 = (Rect.top + Rect.bottom) / 2;
	D = min(x0, y0) / 2;

	double** target = new double* [8];
	for (i = 0; i < 8; i++)
		target[i] = new double[3];
	for (i = 0; i < 8; i++)
	{
		target[i][0] = cube_point[i].x;
		target[i][1] = cube_point[i].y;
		target[i][2] = cube_point[i].z;
	}
	target = cube_rotate(target);
	target = cube_translate(target);
	for (i = 0; i < 8; i++)
		target[i][2] = target[i][2] + 2 * D;

	for (i = 0; i < 8; i++) {
		projPoints[i].x = 2 * D * (target[i][0]) / (target[i][2] + D) + x0;
		projPoints[i].y = 2 * D * (target[i][1]) / (target[i][2] + D) + y0;
	}

	for (i = 0; i < 6; i++) {
		x1 = projPoints[cubefaces[i][0]].x - projPoints[cubefaces[i][1]].x;
		y1 = projPoints[cubefaces[i][0]].y - projPoints[cubefaces[i][1]].y;
		x2 = projPoints[cubefaces[i][2]].x - projPoints[cubefaces[i][1]].x;
		y2 = projPoints[cubefaces[i][2]].y - projPoints[cubefaces[i][1]].y;
		if (x1 * y2 - x2 * y1 >= 0 && type)
			isVisible[i] = 0;
	}

	for (i = 0; i < 6; i++) {
		if (isVisible[i]) {
			for (j = 0; j < 4; j++)
				P[j] = projPoints[cubefaces[i][j]];
			P[4] = P[0];
			fillcubeface(P, dc, cube_color[i][0],cube_color[i][1],cube_color[i][2], type);
		}
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
		CDC* pDC = this->GetDC();//获得设备环境对象
//获得文档指针
		CCGWORK0918Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (m_nType == 0) {
			//构造直线段图元对象指针
			CLine* line = new CLine();
			//设置控制点
			line->SetStartPoint(m_Newpoint);
			line->SetEndPoint(m_Oldpoint);
			line->Element_r = r;
			line->Element_g = g;
			line->Element_b = b;
			//绘制直线段图元
			//line->draw(pDC);
			//添加直线段图元对象指针到图元列表中
			pDoc->m_MapList.Add(line);
			//dc.SelectObject(Oldpen);

		}
		if (m_nType == 1) {
			int c;
			//确保m_StartPoint确实为矩形区域的左上角
			//m_EndPoint确实是矩形区域的右下角
			if (m_Newpoint.x > m_Oldpoint.x)
			{
				c = m_Newpoint.x;
				m_Newpoint.x = m_Oldpoint.x;
				m_Oldpoint.x = c;
			}
			if (m_Newpoint.y > m_Oldpoint.y)
			{
				c = m_Newpoint.y;
				m_Newpoint.y = m_Oldpoint.y;
				m_Oldpoint.y = c;
			}
			//终止控制点坐标值加1
			m_Oldpoint.x++; m_Oldpoint.y++;
			//构造矩形区域图元对象指针
			CRectangleRegion* rectangle = new CRectangleRegion();
			//设置控制点
			rectangle->SetStartPoint(m_Newpoint);
			rectangle->SetEndPoint(m_Oldpoint);
			rectangle->Element_r = r;
			rectangle->Element_g = g;
			rectangle->Element_b = b;
			//绘制矩形区域
			//rectangle->draw(pDC);
			//dc.SelectObject(Oldpen);
			//添加矩形区域图元对象指针到图元列表中
			pDoc->m_MapList.Add(rectangle);

		}
		if (m_nType == 2) {
			//构造椭圆图元对象指针
			CEllipse* ellipse = new CEllipse();
			//设置控制点
			ellipse->SetStartPoint(m_Newpoint);
			ellipse->SetEndPoint(m_Oldpoint);
			ellipse->Element_r = r;
			ellipse->Element_g = g;
			ellipse->Element_b = b;
			//绘制椭圆图元
			//ellipse->draw(pDC);
			//dc.SelectObject(Oldpen);
			//添加椭圆图元对象指针到图元列表中
			pDoc->m_MapList.Add(ellipse);

		}
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
				//dc.PolyBezier(bezier, 4);
				double x = 0, bx, by;
				CPoint mypoint;
				mypoint = bezier[0];
				for (double i = 0; i <= 1; i += 0.001)
				{
					x = i;
					double parameters[4] = { (1 - x) * (1 - x) * (1 - x), 3 * x * (1 - x) * (1 - x), 3 * x * x * (1 - x), x * x * x };
					bx = parameters[0] * bezier[0].x + parameters[1] * bezier[1].x + parameters[2] * bezier[2].x + parameters[3] * bezier[3].x;
					by = parameters[0] * bezier[0].y + parameters[1] * bezier[1].y + parameters[2] * bezier[2].y + parameters[3] * bezier[3].y;
					//dc.LineTo(bx, by);
					DDALine(&dc, mypoint.x, mypoint.y, bx, by);
					mypoint.x = bx;
					mypoint.y = by;
				}
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
	CCGWORK0918Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//清空图元列表
	m_nType = 0;
	pDoc->m_MapList.RemoveAll();
	Invalidate();
}


//void CCGWORK0918View::OnDarwcube()
//{
//	m_nType = 4;
//	CClientDC dc(this);
//	DrawCube(&dc);
//	// TODO: 在此添加命令处理程序代码
//}


void CCGWORK0918View::OnDarwcube()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	m_nType = 4;
	CClientDC dc(this);
	if_init = true;
	int d, x0, y0;
	CRect Rect;
	GetClientRect(&Rect);
	x0 = (Rect.left + Rect.right) / 2;
	y0 = (Rect.top + Rect.bottom) / 2;
	d = min(x0, y0) / 2;
	for (int i = 0; i < 3; i++) {
		trans[i] = 0;
		rot[i] = 0;
	}
	cubetype = false;
	setCubePoint();
	DrawCube(&dc,cubetype);
		// TODO: 在此添加命令处理程序代码
}




void CCGWORK0918View::OnCubeXPan()
{
	// TODO: 在此添加命令处理程序代码
	//m_nType = 5;
	cubestate = 1;
}


void CCGWORK0918View::OnCubeYPan()
{
	// TODO: 在此添加命令处理程序代码
	//m_nType = 6;
	cubestate = 2;
}


void CCGWORK0918View::OnCubeZPan()
{
	// TODO: 在此添加命令处理程序代码
	//m_nType = 7;
	cubestate = 3;
}


void CCGWORK0918View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (m_nType == 4) {
		if (!cubestate) {
			CView::OnKeyDown(nChar, nRepCnt, nFlags);
			return;
		}
		switch (nChar) {
		case 'A'://VK_A:
			if (cubestate > 3)
				rot[cubestate - 4] += angle;
			else
				trans[cubestate - 1] += cube_length;
			break;
		case 'L'://VK_L:
			if (cubestate > 3)
				rot[cubestate - 4] -= angle;
			else
				trans[cubestate - 1] -= cube_length;
			break;
		}
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CCGWORK0918View::OnSetCube()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	setcube dia;//构造对话框对象
	dia.r1 = cube_color[0][0]; dia.g1 = cube_color[0][1]; dia.b1 = cube_color[0][2];
	dia.r2 = cube_color[1][0]; dia.g2 = cube_color[1][1]; dia.b2 = cube_color[1][2];
	dia.r3 = cube_color[2][0]; dia.g3 = cube_color[2][1]; dia.b3 = cube_color[2][2];
	dia.r4 = cube_color[3][0]; dia.g4 = cube_color[3][1]; dia.b4 = cube_color[3][2];
	dia.r5 = cube_color[4][0]; dia.g5 = cube_color[4][1]; dia.b5 = cube_color[4][2];
	dia.r6 = cube_color[5][0]; dia.g6 = cube_color[5][1]; dia.b6 = cube_color[5][2];
	dia.angle = angle;
	dia.length = cube_length;
	dia.cube_a = cube_a*2;
	if (dia.DoModal() == IDOK) {//确定返回IDOK
		angle = dia.angle;
		cube_length = dia.length;
		cube_a = dia.cube_a/2;
		cube_color[0][0] = dia.r1; cube_color[0][1] = dia.g1; cube_color[0][2] = dia.b1;
		cube_color[1][0] = dia.r2; cube_color[1][1] = dia.g2; cube_color[1][2] = dia.b2;
		cube_color[2][0] = dia.r3; cube_color[2][1] = dia.g3; cube_color[2][2] = dia.b3;
		cube_color[3][0] = dia.r4; cube_color[3][1] = dia.g4; cube_color[3][2] = dia.b4;
		cube_color[4][0] = dia.r5; cube_color[4][1] = dia.g5; cube_color[4][2] = dia.b5;
		cube_color[5][0] = dia.r6; cube_color[5][1] = dia.g6; cube_color[5][2] = dia.b6;
	}
}



void CCGWORK0918View::OnChangecube()
{
	cubetype = !cubetype;
	Invalidate();
	// TODO: 在此添加命令处理程序代码
}


void CCGWORK0918View::OnCubeRotX()
{
	// TODO: 在此添加命令处理程序代码
	cubestate = 4;
}


void CCGWORK0918View::OnCubeRotY()
{
	// TODO: 在此添加命令处理程序代码
	cubestate = 5;
}


void CCGWORK0918View::OnCubeRotZ()
{
	// TODO: 在此添加命令处理程序代码
	cubestate = 6;
}
