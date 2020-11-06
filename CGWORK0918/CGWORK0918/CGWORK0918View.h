
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
	bool m_pLMouseDown=false;
	bool isover = false;

	//CArray<line,Line> list;
// 操作
public:

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

