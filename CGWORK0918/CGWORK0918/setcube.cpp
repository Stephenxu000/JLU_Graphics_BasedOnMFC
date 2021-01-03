// setcube.cpp: 实现文件
//

#include "pch.h"
#include "setcube.h"
#include "afxdialogex.h"
#include "resource.h"


// setcube 对话框

IMPLEMENT_DYNAMIC(setcube, CDialog)

setcube::setcube(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Cube, pParent)
	, b1(0)
	, b2(0)
	, b3(0)
	, b4(0)
	, b5(0)
	, b6(0)
	, g1(0)
	, g2(0)
	, g3(0)
	, g4(0)
	, g5(0)
	, g6(0)
	, r1(0)
	, r3(0)
	, r2(0)
	, r4(0)
	, r5(0)
	, r6(0)
	, angle(0)
	, cube_a(0)
	, length(0)
{

}

setcube::~setcube()
{
}

void setcube::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_b1, b1);
	DDX_Text(pDX, IDC_b2, b2);
	DDX_Text(pDX, IDC_b3, b3);
	DDX_Text(pDX, IDC_b4, b4);
	DDX_Text(pDX, IDC_b5, b5);
	DDX_Text(pDX, IDC_b6, b6);
	DDX_Text(pDX, IDC_g1, g1);
	DDX_Text(pDX, IDC_g2, g2);
	DDX_Text(pDX, IDC_g3, g3);
	DDX_Text(pDX, IDC_g4, g4);
	DDX_Text(pDX, IDC_g5, g5);
	DDX_Text(pDX, IDC_g6, g6);
	DDX_Text(pDX, IDC_r1, r1);
	DDX_Text(pDX, IDC_r3, r3);
	DDX_Text(pDX, IDC_r2, r2);
	DDX_Text(pDX, IDC_r4, r4);
	DDX_Text(pDX, IDC_r5, r5);
	DDX_Text(pDX, IDC_r6, r6);
	DDX_Text(pDX, IDC_angle, angle);
	DDX_Text(pDX, IDC_cube_a, cube_a);
	DDX_Text(pDX, IDC_length, length);
}


BEGIN_MESSAGE_MAP(setcube, CDialog)
END_MESSAGE_MAP()


// setcube 消息处理程序
