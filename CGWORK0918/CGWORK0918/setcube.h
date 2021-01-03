#pragma once


// setcube 对话框

class setcube : public CDialog
{
	DECLARE_DYNAMIC(setcube)

public:
	setcube(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~setcube();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Cube };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int b1;
	int b2;
	int b3;
	int b4;
	int b5;
	int b6;
	int g1;
	int g2;
	int g3;
	int g4;
	int g5;
	int g6;
	int r1;
	int r3;
	int r2;
	int r4;
	int r5;
	int r6;
	int angle;
	int cube_a;
	int length;
};
