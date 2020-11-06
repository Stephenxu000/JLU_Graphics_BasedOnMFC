
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
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Area_Filled_Polygon, &CCGWORK0918View::OnAreaFilledPolygon)
	ON_COMMAND(ID_Area_Filled_Setcolor, &CCGWORK0918View::OnAreaFilledSetcolor)
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


// CCGWORK0918View 消息处理程序

void CCGWORK0918View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Oldpoint = point;//保存光标的当前位置
	m_Newpoint = point;//存放画线的起始位置
	SetCapture(); //捕捉鼠标
	m_pLMouseDown = TRUE;//表示鼠标为按下的状态
	CRect rect;
	GetClientRect(&rect);//获得并保存用户区坐标
	ClientToScreen(&rect); //用用户区坐标重新计算屏幕坐标
	ClipCursor(&rect); //限制光标在用户区内
	//默认处理，调用基类消息处理函数
	if (m_nType == 3)
	{

	}
	CView::OnLButtonDown(nFlags, point);
}



void CCGWORK0918View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pLMouseDown) {
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);//设置绘图模式，以屏幕颜色的相反色绘图
		switch (m_nType) {
		case 0:
			dc.MoveTo(m_Newpoint);
			dc.LineTo(m_Oldpoint);
			dc.MoveTo(m_Newpoint);
			dc.LineTo(point);
			break;
		case 1:
			dc.Rectangle(m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);
			dc.Rectangle(m_Newpoint.x, m_Newpoint.y, point.x, point.y);
			break;
		case 2:
			dc.Ellipse(m_Newpoint.x, m_Newpoint.y, m_Oldpoint.x, m_Oldpoint.y);
			dc.Ellipse(m_Newpoint.x, m_Newpoint.y, point.x, point.y);
			break;
		
		}
		m_Oldpoint = point; //存放当前鼠标位置
	}
	CView::OnMouseMove(nFlags, point);
}


void CCGWORK0918View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pLMouseDown)
	{
		m_pLMouseDown = FALSE;//标志鼠标释放
		ReleaseCapture();//释放鼠标捕捉
		ClipCursor(NULL);//使光标可以随意移动
	}
	CView::OnLButtonUp(nFlags, point);
}




void CCGWORK0918View::OnOndrawLineto()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 0;
	Invalidate();//清屏
}


void CCGWORK0918View::OnOndrawRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 1;
	Invalidate();
}

void CCGWORK0918View::OnOndrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 2;
	Invalidate();
}

void CCGWORK0918View::OnOndrawSetcolor()
{
	// TODO: 在此添加命令处理程序代码
}



void CCGWORK0918View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDblClk(nFlags, point);
}


void CCGWORK0918View::OnAreaFilledPolygon()
{
	
	m_nType = 3;
	//Invalidate();
	// TODO: 在此添加命令处理程序代码
}


void CCGWORK0918View::OnAreaFilledSetcolor()
{
	// TODO: 在此添加命令处理程序代码
}
