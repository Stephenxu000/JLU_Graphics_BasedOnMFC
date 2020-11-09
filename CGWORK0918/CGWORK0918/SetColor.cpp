// SetColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0918.h"
#include "SetColor.h"
#include "afxdialogex.h"


// SetColor 对话框

IMPLEMENT_DYNAMIC(SetColor, CDialog)

SetColor::SetColor(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETCOLOR, pParent)
	, m_b(0)
	, m_g(0)
	, m_r(0)
{

}

SetColor::~SetColor()
{
}

void SetColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_B, m_b);
	DDX_Text(pDX, IDC_G, m_g);
	DDX_Text(pDX, IDC_R, m_r);
}


BEGIN_MESSAGE_MAP(SetColor, CDialog)
END_MESSAGE_MAP()


// SetColor 消息处理程序
