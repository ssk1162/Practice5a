
// Practice5aView.h: CPractice5aView 클래스의 인터페이스
//

#pragma once


class CPractice5aView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPractice5aView() noexcept;
	DECLARE_DYNCREATE(CPractice5aView)

// 특성입니다.
public:
	CPractice5aDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPractice5aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CString m_strDept;
	CString m_strName;
	CString m_strSex;
	CString m_strHobby;
};

#ifndef _DEBUG  // Practice5aView.cpp의 디버그 버전
inline CPractice5aDoc* CPractice5aView::GetDocument() const
   { return reinterpret_cast<CPractice5aDoc*>(m_pDocument); }
#endif

