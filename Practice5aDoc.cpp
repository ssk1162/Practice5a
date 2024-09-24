
// Practice5aDoc.cpp: CPractice5aDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice5a.h"
#endif

#include "Practice5aDoc.h"
#include "MainFrm.h";
#include "Practice5aView.h";

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPractice5aDoc

IMPLEMENT_DYNCREATE(CPractice5aDoc, CDocument)

BEGIN_MESSAGE_MAP(CPractice5aDoc, CDocument)
END_MESSAGE_MAP()


// CPractice5aDoc 생성/소멸

CPractice5aDoc::CPractice5aDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPractice5aDoc::~CPractice5aDoc()
{
}

BOOL CPractice5aDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	// 문서에 연결된 첫번째 뷰에 대한 포지션값을 반환
	// 처음 뷰의 위치를 얻고 이를 통해 뷰들을 순차적으로 접근할 수 있다
	POSITION pos = GetFirstViewPosition();
	// 여러개의 뷰를 가져올 수 있지만 CPractice5aView를 캐스팅해서 하나의 뷰를 처리
	CPractice5aView* pView = (CPractice5aView*)GetNextView(pos);

	// 뷰 클레스의 멤버 변수 초기화
	pView->m_strDept.Empty();
	pView->m_strName.Empty();
	pView->m_strSex.Empty();
	pView->m_strHobby.Empty();

	return TRUE;
}




// CPractice5aDoc serialization

void CPractice5aDoc::Serialize(CArchive& ar)
{
	// AfxGetMainWnd 메뉴, 툴바, 상태바가 포함하는 창
	// AfxGetMainWnd을 메인 프레임창으로 형변환
	// 메인 창을 가져와 pFrame 포인트 변수에 저장
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	// 메인 프레임창에 현재 활성화된 뷰를 반환
	// 사용자가 정의한 뷰로 캐스팅
	CPractice5aView* pView = (CPractice5aView*)pFrame->GetActiveView();

	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << pView->m_strDept;
		ar << pView->m_strName;
		ar << pView->m_strSex;
		ar << pView->m_strHobby;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> pView->m_strDept;
		ar >> pView->m_strName;
		ar >> pView->m_strSex;
		ar >> pView->m_strHobby;
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CPractice5aDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CPractice5aDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPractice5aDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPractice5aDoc 진단

#ifdef _DEBUG
void CPractice5aDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPractice5aDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPractice5aDoc 명령
