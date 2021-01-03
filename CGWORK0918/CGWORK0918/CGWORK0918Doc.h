
// CGWORK0918Doc.h: CCGWORK0918Doc 类的接口
//


#pragma once
#include"CMapList.h"
class CCGWORK0918Doc : public CDocument
{
protected: // 仅从序列化创建
	CCGWORK0918Doc() noexcept;
	DECLARE_DYNCREATE(CCGWORK0918Doc)

// 特性
public:
	CMapList m_MapList;//当前绘制的图元的列表
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CCGWORK0918Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
