#pragma once


// SetColor 对话框

class SetColor : public CDialog
{
	DECLARE_DYNAMIC(SetColor)

public:
	SetColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetColor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETCOLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_b;
	int m_g;
	int m_r;
};
