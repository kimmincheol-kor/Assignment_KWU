
// 2048View.cpp : CMy2048View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CMy2048View ����/�Ҹ�

CMy2048View::CMy2048View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

CMy2048View::~CMy2048View()
{
}

BOOL CMy2048View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2048View �׸���

void CMy2048View::OnDraw(CDC* pDC)
{
	CMy2048Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	bool IsMoved = 0; // ���������� üũ
	int IsEnded = 0; // �������� üũ

	if (log == false) // �α׾ȳ���� ���� ����
	{
		/* ȸ�� */
		if (start_point.x != end_point.x) // ���콺�� �巡�� �Ǿ��ٸ�,
		{
			if (start_point.x <= 250 && start_point.x >= 50 && start_point.y >= 50 && start_point.y <= 250)
			{
				if (end_point.x - start_point.x > 0) // ������ ȸ��
				{
					pDoc->MyBoard.SpinRight();
				}
				else // ���� ȸ��
				{
					pDoc->MyBoard.SpinLeft();
				}
			}
		}

		 /* �̵� */
		 // ������ �̵�
		if (key == 1)
		{
			IsMoved = pDoc->MyBoard.Right();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// ���� �̵�
		else if (key == 2)
		{
			IsMoved = pDoc->MyBoard.Left();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// ���� �̵�
		else if (key == 3)
		{
			IsMoved = pDoc->MyBoard.Up();
			if (IsMoved == true)
			{
				pDoc->MyBoard.Random();
				IsEnded = pDoc->MyBoard.CheckEnd();
			}
		}
		// �Ʒ��� �̵�
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
	else // �α� �����
	{
		ofstream fout;
		fout.open("log.txt", ios::app); // �̾��

		/* ȸ�� */
		if (start_point.x != end_point.x) // ���콺�� �巡�� �Ǿ��ٸ�,
		{
			if (start_point.x <= 250 && start_point.x >= 50 && start_point.y >= 50 && start_point.y <= 250)
			{
				if (end_point.x - start_point.x > 0) // ������ ȸ��
				{
					pDoc->MyBoard.SpinRight();
					fout << GameTurn++ << ". Mouse_Left_to_Right\n";
					fout.close();
				}
				else // ���� ȸ��
				{
					pDoc->MyBoard.SpinLeft();
					fout << GameTurn++ << ". Mouse_Right_to_Left\n";
					fout.close();
				}
				pDoc->MyBoard.Logging();
			}
		}

		/* �̵� */
		// ������ �̵�
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
		// ���� �̵�
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
		// ���� �̵�
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
		// �Ʒ��� �̵�
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

	// ���� �����
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
			// �÷� ���
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
			} // �÷� ���� ��� ��
			  // ��� ���
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
			} // ��� ���� ��� ��
		} // x ��ǥ ��
		pWork = pWork->GetpLeft()->GetpLeft()->GetpLeft();
		pWork = pWork->GetpDown();
	} // y ��ǥ ��

	if (IsEnded == -1) // ���α׷� ����
	{
		AfxGetMainWnd()->PostMessage(WM_COMMAND, ID_APP_EXIT, 0);
	}

	key = 0;
	start_point = NULL;
	end_point = NULL;
}


// CMy2048View �μ�

BOOL CMy2048View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2048View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2048View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy2048View ����

#ifdef _DEBUG
void CMy2048View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2048View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2048Doc* CMy2048View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2048Doc)));
	return (CMy2048Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2048View �޽��� ó����

// ���콺 Ŭ��
void CMy2048View::OnLButtonDown(UINT nFlags, CPoint point)
{
	start_point = point; // Ŭ���� ����
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}

// Ŭ���� ��
void CMy2048View::OnLButtonUp(UINT nFlags, CPoint point)
{
	end_point = point; // �� ��ġ
	RedrawWindow(); // OnDraw �Լ� ȣ��
	ReleaseCapture(); // ���� �ߴ�
	CView::OnLButtonUp(nFlags, point);
}


void CMy2048View::Colorful() // ���� �� ���� �޴�
{
	color = true;
	RedrawWindow(); // OnDraw �Լ� ȣ��
}


void CMy2048View::BlacknWhite() // ���ڸ� �޴�
{
	color = false;
	RedrawWindow(); // OnDraw �Լ� ȣ��
}


void CMy2048View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
	{
		key = 1;
		RedrawWindow(); // OnDraw �Լ� ȣ��
		break;
	}

	case VK_LEFT:
	{
		key = 2;
		RedrawWindow(); // OnDraw �Լ� ȣ��
		break;
	}

	case VK_UP:
	{
		key = 3;
		RedrawWindow(); // OnDraw �Լ� ȣ��
		break;
	}

	case VK_DOWN:
	{
		key = 4;
		RedrawWindow(); // OnDraw �Լ� ȣ��
		break;
	}
	default:
		key = 0;
		break;

	} // end of switch

	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy2048View::TurnLog() // �� ���
{
	if (log == true)
		log = false;
	else
		log = true;

	RedrawWindow(); // OnDraw �Լ� ȣ��
}



void CMy2048View::OnUpdate32771(CCmdUI *pCmdUI) // �÷�üũ
{
	pCmdUI->SetCheck(color == true);
}


void CMy2048View::OnUpdate32772(CCmdUI *pCmdUI) // ���üũ
{
	pCmdUI->SetCheck(color == false);
}


void CMy2048View::OnUpdate32774(CCmdUI *pCmdUI) // �ϱ�� üũ
{
	pCmdUI->SetCheck(log == true);
}
