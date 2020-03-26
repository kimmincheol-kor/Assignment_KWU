
// 2048View.h : CMy2048View 클래스의 인터페이스
//

#pragma once


class CMy2048View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy2048View();
	DECLARE_DYNCREATE(CMy2048View)

// 특성입니다.
public:
	CMy2048Doc* GetDocument() const;

public:
	CPoint start_point; // 클릭 지점
	CPoint end_point; // 마우스를 뗀 지점

	int key=0; // 어떤 방향키를 입력했는지 구별을 위한 변수
	bool color=true; // 2048 보드를 컬러로 출력할 것인지 흑백으로 출력할 것인지 구별을 위한 변수
	bool log=false; // 턴기록을 볼것인지 아닌지 구별하기 위한 변수
	int GameTurn=1; // 턴 기록에 몇번째 게임턴인지 기록하기 위한 변수

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
	virtual ~CMy2048View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void Colorful();
	afx_msg void BlacknWhite();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void TurnLog();
//	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnUpdate32771(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32772(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32774(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // 2048View.cpp의 디버그 버전
inline CMy2048Doc* CMy2048View::GetDocument() const
   { return reinterpret_cast<CMy2048Doc*>(m_pDocument); }
#endif

