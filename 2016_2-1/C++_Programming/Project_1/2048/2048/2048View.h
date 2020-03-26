
// 2048View.h : CMy2048View Ŭ������ �������̽�
//

#pragma once


class CMy2048View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2048View();
	DECLARE_DYNCREATE(CMy2048View)

// Ư���Դϴ�.
public:
	CMy2048Doc* GetDocument() const;

public:
	CPoint start_point; // Ŭ�� ����
	CPoint end_point; // ���콺�� �� ����

	int key=0; // � ����Ű�� �Է��ߴ��� ������ ���� ����
	bool color=true; // 2048 ���带 �÷��� ����� ������ ������� ����� ������ ������ ���� ����
	bool log=false; // �ϱ���� �������� �ƴ��� �����ϱ� ���� ����
	int GameTurn=1; // �� ��Ͽ� ���° ���������� ����ϱ� ���� ����

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy2048View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // 2048View.cpp�� ����� ����
inline CMy2048Doc* CMy2048View::GetDocument() const
   { return reinterpret_cast<CMy2048Doc*>(m_pDocument); }
#endif

