
// CGWORK0918.h: CGWORK0918 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CCGWORK0918App:
// 有关此类的实现，请参阅 CGWORK0918.cpp
//

class CCGWORK0918App : public CWinApp
{
public:
	CCGWORK0918App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnCubeRotX();
};

extern CCGWORK0918App theApp;
