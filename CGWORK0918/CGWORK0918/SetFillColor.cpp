// SetFillColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0918.h"
#include "SetFillColor.h"
#include "afxdialogex.h"


// SetFillColor 对话框

IMPLEMENT_DYNAMIC(SetFillColor, CDialog)

SetFillColor::SetFillColor(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETFILLCOLOR, pParent)
	, b_b(0)
	, b_g(0)
	, b_r(0)
	, f_b(0)
	, f_g(0)
	, f_r(0)
{

}

SetFillColor::~SetFillColor()
{
}

void SetFillColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_bb, b_b);
	DDX_Text(pDX, IDC_bg, b_g);
	DDX_Text(pDX, IDC_br, b_r);
	DDX_Text(pDX, IDC_fb, f_b);
	DDX_Text(pDX, IDC_fg, f_g);
	DDX_Text(pDX, IDC_fr, f_r);
}


BEGIN_MESSAGE_MAP(SetFillColor, CDialog)
END_MESSAGE_MAP()


// SetFillColor 消息处理程序
