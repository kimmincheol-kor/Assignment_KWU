
// 2048View.cpp : CMy2048View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2048.h"
#endif

#include "2048Doc.h"
#include "2048View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
#include <iostream>
#include <fstream>

// CMy2048View

IMPLEMENT_DYNCREATE(CMy2048View, CView)

BEGIN_MESSAGE_MAP(CMy2048View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &CMy2048View::Colorful)
	ON_COMMAND(ID_32772, &CMy2048View::BlacknWhite)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32774, &CMy2048View::TurnLog)
	//	ON_WM_CONTEXTMENU()
	ON_UPDATE_COMMAND_UI(ID_32771, &CMy2048View::OnUpdate32771)
	ON_UPDATE_COMMAND_UI(ID_32772, &CMy2048View::OnUpdate32772)
	ON_UPDATE_COMMAND_UI(ID_32774, &CMy2048View::OnUpdate32774)
END_MESSAGE_MAP()

// CMy2048View 생성/소멸

CMy2048View::CMy2048View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CMy2048View::~CMy2048View()
{
}

BOOL CMy2048View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2048View 그리기

void CMy2048View::OnDraw(CDC* pDC)
{
	CMy2048Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	bool IsMoved = 0; // 움직였는지 체크
	int IsEnded = 0; // 끝났는지 체크

	if (log == false) // 로그안남기고 게임 진행
	{
		/* 회전 */
		if (start_point.x != end_point.x) // 마우스가 드래그 되었다면,
		{
			if (start_point.x <= 250 && start_point.x >= 50 && start_point.y >= 50 && start_point.y <= 250)
			{
				if (end_point.x - start_point.x > 0) // 오른쪽 회전
				{
					pDoc->MyBoard.SpinRight();
				}
				else // 왼쪽 회전
				{
					pDoc->MyBoard.SpinLeft();
				}
			}
		}

		 /* 이동 */
		 // 오른쪽 이동
		if (key == 1)
		{
			IsMoved = pDoc->MyBoard.Right();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 왼쪽 이동
		else if (key == 2)
		{
			IsMoved = pDoc->MyBoard.Left();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 위쪽 이동
		else if (key == 3)
		{
			IsMoved = pDoc->MyBoard.Up();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 아래쪽 이동
		else if (key == 4)
		{
			IsMoved = pDoc->MyBoard.Down();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
	}
	else // 로그 남기기
	{
		ofstream fout;
		fout.open("log.txt", ios::app); // 이어쓰기

		/* 회전 */
		if (start_point.x != end_point.x) // 마우스가 드래그 되었다면,
		{
			if (start_point.x <= 250 && start_point.x >= 50 && start_point.y >= 50 && start_point.y <= 250)
			{
				if (end_point.x - start_point.x > 0) // 오른쪽 회전
				{
					pDoc->MyBoard.SpinRight();
					fout << GameTurn++ << ". Mouse_Left_to_Right\n";
					fout.close();
				}
				else // 왼쪽 회전
				{
					pDoc->MyBoard.SpinLeft();
					fout << GameTurn++ << ". Mouse_Right_to_Left\n";
					fout.close();
				}
				pDoc->MyBoard.Logging();
			}
		}

		/* 이동 */
		// 오른쪽 이동
		if (key == 1)
		{
			IsMoved = pDoc->MyBoard.Right();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				fout << GameTurn++ << ". Key_Right\n";
				fout.close();
				pDoc->MyBoard.Logging();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 왼쪽 이동
		else if (key == 2)
		{
			IsMoved = pDoc->MyBoard.Left();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				fout << GameTurn++ << ". Key_Left\n";
				fout.close();
				pDoc->MyBoard.Logging();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 위쪽 이동
		else if (key == 3)
		{
			IsMoved = pDoc->MyBoard.Up();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				fout << GameTurn++ << ". Key_Up\n";
				fout.close();
				pDoc->MyBoard.Logging();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// 아래쪽 이동
		else if (key == 4)
		{
			IsMoved = pDoc->MyBoard.Down();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				fout << GameTurn++ << ". Key_Down\n";
				fout.close();
				pDoc->MyBoard.Logging();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
	}

	// 보드 만들기
	CRect rect;
	Block * pWork;
	CString cstr;
	pWork = pDoc->MyBoard.GetHead();
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			CRect rect(50 + (x * 50), 50 + (y * 50), 50 + (x * 50) + 50, 50 + (y * 50) + 50);
			pDC->Rectangle(&rect);
			// 컬러 출력
			if (color == true)
			{
				if (pWork->Getnum() == 2)
				{
					pDC->FillSolidRect(rect, RGB(255, 255, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("2"));
				}
				else if (pWork->Getnum() == 4)
				{
					pDC->FillSolidRect(rect, RGB(255, 127, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("4"));
				}
				else if (pWork->Getnum() == 8)
				{
					pDC->FillSolidRect(rect, RGB(0, 255, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("8"));
				}
				else if (pWork->Getnum() == 16)
				{
					pDC->FillSolidRect(rect, RGB(0, 0, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("16"));
				}
				else if (pWork->Getnum() == 32)
				{
					pDC->FillSolidRect(rect, RGB(166, 166, 166));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("32"));
				}
				else if (pWork->Getnum() == 64)
				{
					pDC->FillSolidRect(rect, RGB(255, 0, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("64"));
				}
				else if (pWork->Getnum() == 128)
				{
					pDC->FillSolidRect(rect, RGB(0, 255, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("128"));
				}
				else if (pWork->Getnum() == 256)
				{
					pDC->FillSolidRect(rect, RGB(128, 0, 128));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("256"));
				}
				else if (pWork->Getnum() == 512)
				{
					pDC->FillSolidRect(rect, RGB(112, 48, 160));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("512"));
				}
				else if (pWork->Getnum() == 1024)
				{
					pDC->FillSolidRect(rect, RGB(207, 107, 54));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("1024"));
				}
				else if (pWork->Getnum() == 2048)
				{
					pDC->FillSolidRect(rect, RGB(255, 0, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("2048"));
				}

				if (pWork->GetpRight() == NULL)
					break;
				else
					pWork = pWork->GetpRight();
			} // 컬러 보드 출력 끝
			  // 흑백 출력
			else if (color == false)
			{
				if (pWork->Getnum() == 2)
				{
					//pDC->FillSolidRect(rect, RGB(255, 255, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("2"));
				}
				else if (pWork->Getnum() == 4)
				{
					//pDC->FillSolidRect(rect, RGB(255, 127, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("4"));
				}
				else if (pWork->Getnum() == 8)
				{
					//pDC->FillSolidRect(rect, RGB(0, 255, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("8"));
				}
				else if (pWork->Getnum() == 16)
				{
					//pDC->FillSolidRect(rect, RGB(0, 0, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("16"));
				}
				else if (pWork->Getnum() == 32)
				{
					//pDC->FillSolidRect(rect, RGB(166, 166, 166));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("32"));
				}
				else if (pWork->Getnum() == 64)
				{
					//pDC->FillSolidRect(rect, RGB(255, 0, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("64"));
				}
				else if (pWork->Getnum() == 128)
				{
					//pDC->FillSolidRect(rect, RGB(0, 255, 255));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("128"));
				}
				else if (pWork->Getnum() == 256)
				{
					//pDC->FillSolidRect(rect, RGB(128, 0, 128));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("256"));
				}
				else if (pWork->Getnum() == 512)
				{
					//pDC->FillSolidRect(rect, RGB(112, 48, 160));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("512"));
				}
				else if (pWork->Getnum() == 1024)
				{
					//pDC->FillSolidRect(rect, RGB(207, 107, 54));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("1024"));
				}
				else if (pWork->Getnum() == 2048)
				{
					//pDC->FillSolidRect(rect, RGB(255, 0, 0));
					pDC->TextOutW(66 + (x * 50), 66 + (y * 50), _T("2048"));
				}

				if (pWork->GetpRight() == NULL)
					break;
				else
					pWork = pWork->GetpRight();
			} // 흑백 보드 출력 끝
		} // x 좌표 끝
		pWork = pWork->GetpLeft()->GetpLeft()->GetpLeft();
		pWork = pWork->GetpDown();
	} // y 좌표 끝

	if (IsEnded == -1) // 프로그램 종료
	{
		AfxGetMainWnd()->PostMessage(WM_COMMAND, ID_APP_EXIT, 0);
	}

	key = 0;
	start_point = NULL;
	end_point = NULL;
}


// CMy2048View 인쇄

BOOL CMy2048View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2048View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2048View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy2048View 진단

#ifdef _DEBUG
void CMy2048View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2048View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2048Doc* CMy2048View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2048Doc)));
	return (CMy2048Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2048View 메시지 처리기

// 마우스 클릭
void CMy2048View::OnLButtonDown(UINT nFlags, CPoint point)
{
	start_point = point; // 클릭한 지점
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}

// 클릭을 뗌
void CMy2048View::OnLButtonUp(UINT nFlags, CPoint point)
{
	end_point = point; // 뗀 위치
	RedrawWindow(); // OnDraw 함수 호출
	ReleaseCapture(); // 추적 중단
	CView::OnLButtonUp(nFlags, point);
}


void CMy2048View::Colorful() // 색상 및 숫자 메뉴
{
	color = true;
	RedrawWindow(); // OnDraw 함수 호출
}


void CMy2048View::BlacknWhite() // 숫자만 메뉴
{
	color = false;
	RedrawWindow(); // OnDraw 함수 호출
}


void CMy2048View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
	{
		key = 1;
		RedrawWindow(); // OnDraw 함수 호출
		break;
	}

	case VK_LEFT:
	{
		key = 2;
		RedrawWindow(); // OnDraw 함수 호출
		break;
	}

	case VK_UP:
	{
		key = 3;
		RedrawWindow(); // OnDraw 함수 호출
		break;
	}

	case VK_DOWN:
	{
		key = 4;
		RedrawWindow(); // OnDraw 함수 호출
		break;
	}
	default:
		key = 0;
		break;

	} // end of switch

	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy2048View::TurnLog() // 턴 기록
{
	if (log == true)
		log = false;
	else
		log = true;

	RedrawWindow(); // OnDraw 함수 호출
}



void CMy2048View::OnUpdate32771(CCmdUI *pCmdUI) // 컬러체크
{
	pCmdUI->SetCheck(color == true);
}


void CMy2048View::OnUpdate32772(CCmdUI *pCmdUI) // 흑백체크
{
	pCmdUI->SetCheck(color == false);
}


void CMy2048View::OnUpdate32774(CCmdUI *pCmdUI) // 턴기록 체크
{
	pCmdUI->SetCheck(log == true);
}
