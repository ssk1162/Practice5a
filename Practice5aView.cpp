
// Practice5aView.cpp: CPractice5aView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice5a.h"
#endif

#include "Practice5aDoc.h"
#include "Practice5aView.h"
#include "CCardDlg.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice5aView

IMPLEMENT_DYNCREATE(CPractice5aView, CView)

BEGIN_MESSAGE_MAP(CPractice5aView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CPractice5aView 생성/소멸

CPractice5aView::CPractice5aView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice5aView::~CPractice5aView()
{
}

BOOL CPractice5aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice5aView 그리기

void CPractice5aView::OnDraw(CDC* pDC)
{
	CPractice5aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	pDC->TextOut(20, 20, m_strDept);
	pDC->TextOut(20, 50, m_strName);
	pDC->TextOut(20, 80, m_strSex);
	pDC->TextOut(20, 110, m_strHobby);

}


// CPractice5aView 인쇄

BOOL CPractice5aView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice5aView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice5aView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPractice5aView 진단

#ifdef _DEBUG
void CPractice5aView::AssertValid() const
{
	CView::AssertValid();
}

void CPractice5aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice5aDoc* CPractice5aView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice5aDoc)));
	return (CPractice5aDoc*)m_pDocument;
}
#endif //_DEBUG


// CPractice5aView 메시지 처리기


void CPractice5aView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CCardDlg* pCard = new CCardDlg();
	m_strHobby.Empty();
	if (pCard->DoModal() == IDOK)
	{
		m_strDept = pCard->m_strDept;
		m_strName = pCard->m_strName;

		if (pCard->m_bSex == true)
			m_strSex = _T("남자");
		else
			m_strSex = _T("여자");

		if (pCard->m_bHobby[0])
			m_strHobby += _T("독서");
		if (pCard->m_bHobby[1])
			m_strHobby += _T("운동");
		if (pCard->m_bHobby[2])
			m_strHobby += _T("낚시");

		Invalidate();

	}

	CView::OnRButtonDown(nFlags, point);
}
