
// 2048Doc.h : CMy2048Doc 클래스의 인터페이스
//


#pragma once

// 2048 헤더 보드, 블럭
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;

class Block
{
private:
	int m_number;
	Block * m_pUp;
	Block * m_pDown;
	Block * m_pLeft;
	Block * m_pRight;

public:
	Block()
	{
		m_number = 0;
		m_pUp = NULL;
		m_pDown = NULL;
		m_pRight = NULL;
		m_pLeft = NULL;
	}
	~Block() {}

	void Setnum(int n)
	{
		m_number = n;
	}

	void SetpUp(Block * node)
	{
		m_pUp = node;
	}

	void SetpDown(Block * node)
	{
		m_pDown = node;
	}

	void SetpRight(Block * node)
	{
		m_pRight = node;
	}

	void SetpLeft(Block * node)
	{
		m_pLeft = node;
	}

	int Getnum()
	{
		return m_number;
	}

	Block * GetpUp()
	{
		return m_pUp;
	}

	Block * GetpDown()
	{
		return m_pDown;
	}

	Block * GetpRight()
	{
		return m_pRight;
	}

	Block * GetpLeft()
	{
		return m_pLeft;
	}
};

class Board
{
private:
	Block * m_pHead;

public:
	Block * GetHead()
	{
		return m_pHead;
	}

	Board()
	{
		m_pHead = NULL;
		Block * pWork;

		for (int y = 0; y<4; y++) // y좌표
		{
			for (int x = 0; x<4; x++) // x좌표
			{
				pWork = m_pHead;

				Block * pNew = new Block;
				pNew->Setnum(0); // 시작시 0으로 초기화

				if (m_pHead == NULL)
					m_pHead = pNew;
				else
				{
					if (y == 0) // 맨위 줄
					{
						for (int i = 0; i<x - 1; i++) // 입력될 위치의 왼쪽을 가리킴
							pWork = pWork->GetpRight();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);
					}
					else if (x == 0) // 맨 왼쪽 라인
					{
						for (int i = 0; i<y - 1; i++) // 입력될 위치의 위쪽을 가리킴
							pWork = pWork->GetpDown();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
					else // 나머지
					{
						// 입력될 위치의 왼쪽을 가리킴
						for (int i = 0; i<x - 1; i++)
							pWork = pWork->GetpRight();
						for (int i = 0; i<y; i++)
							pWork = pWork->GetpDown();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);

						pWork = m_pHead; // 헤드를 가리킴

										 // 입력될 위치의 위쪽을 가리킴
						for (int i = 0; i<y - 1; i++)
							pWork = pWork->GetpDown();
						for (int i = 0; i<x; i++)
							pWork = pWork->GetpRight();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
				}
			}
		}

		// 선언시 랜덤 2 입력
		srand((unsigned int)time(NULL));
		int rand_x;
		int rand_y;

		// 첫번째 2
		while (1)
		{
			pWork = m_pHead;

			rand_x = rand() % 4;
			rand_y = rand() % 4;

			for (int i = 0; i<rand_y; i++)
				pWork = pWork->GetpDown();
			for (int i = 0; i<rand_x; i++)
				pWork = pWork->GetpRight();

			if (pWork->Getnum() == 0) // 빈칸이면,
			{
				pWork->Setnum(2);
				break;
			}
			else
				continue;
		}
		// 2번째 2
		while (1)
		{
			pWork = m_pHead;

			rand_x = rand() % 4;
			rand_y = rand() % 4;

			for (int i = 0; i<rand_y; i++)
				pWork = pWork->GetpDown();
			for (int i = 0; i<rand_x; i++)
				pWork = pWork->GetpRight();

			if (pWork->Getnum() == 0) // 빈칸이면,
			{
				pWork->Setnum(2);
				break;
			}
			else
				continue;
		}

		ofstream f;
		f.open("log.txt");
		f.close();
	}

	~Board() // 메모리 할당 해제
	{
		ofstream exit;
		exit.open("exit.txt");

		Block * pTemp1;
		Block * pTemp2;
		Block * pTemp3;
		Block * pTemp4;

		Block * pWork1;
		Block * pWork2;
		Block * pWork3;
		Block * pWork4;

		pTemp1 = m_pHead;
		pTemp2 = m_pHead->GetpDown();
		pTemp3 = m_pHead->GetpDown()->GetpDown();
		pTemp4 = m_pHead->GetpDown()->GetpDown()->GetpDown();

		while (1)
		{
			pWork1 = pTemp1;
			pWork2 = pTemp2;
			pWork3 = pTemp3;
			pWork4 = pTemp4;

			if (pWork1 == NULL)
				break;

			pTemp1 = pTemp1->GetpRight();
			pTemp2 = pTemp2->GetpRight();
			pTemp3 = pTemp3->GetpRight();
			pTemp4 = pTemp4->GetpRight();

			delete pWork1;
			delete pWork2;
			delete pWork3;
			delete pWork4;

			exit << "메모리 할당 해제 성공\n";
		}
		exit.close();
	}

	bool Up()
	{
		int previous[16]; // 비교용 배열
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead; // 가장 위쪽

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpRight();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum(); // 비교용 배열
				if (pWork->Getnum() != 0)
				{
					if (Box == 0)
					{
						Box = pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if (pWork->Getnum() == Box)
						{
							Box += pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box = 0;
							pEnd = pEnd->GetpDown();

							Box = pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if (pWork->GetpDown() == NULL)
					pEnd->Setnum(Box);
				else
					pWork = pWork->GetpDown();
			}
		}

		// 처음보드와 바뀐보드 비교
		int current[16];
		n = 0;

		pDown = m_pHead;
		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pDown = pDown->GetpRight();

			for (int x = 0; x<4; x++)
			{
				current[n++] = pWork->Getnum();
				pWork = pWork->GetpDown();
			}
		}

		check = 0;
		for (int i = 0; i<16; i++)
		{
			if (current[i] == previous[i])
				check += 1;
		}

		if (check == 16) // 이동 실패
			return false;
		else // 이동 성공
			return true;
	}

	bool Down()
	{
		int previous[16]; // 비교용 배열
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead->GetpDown()->GetpDown()->GetpDown(); // 가장 아래쪽

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpRight();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum(); // 비교용 배열
				if (pWork->Getnum() != 0)
				{
					if (Box == 0)
					{
						Box = pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if (pWork->Getnum() == Box)
						{
							Box += pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box = 0;
							pEnd = pEnd->GetpUp();

							Box = pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if (pWork->GetpUp() == NULL)
					pEnd->Setnum(Box);
				else
					pWork = pWork->GetpUp();
			}
		}

		// 처음보드와 바뀐보드 비교
		int current[16];
		n = 0;

		pDown = m_pHead->GetpDown()->GetpDown()->GetpDown();
		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pDown = pDown->GetpRight();

			for (int x = 0; x<4; x++)
			{
				current[n++] = pWork->Getnum();
				pWork = pWork->GetpUp();
			}
		}

		check = 0;
		for (int i = 0; i<16; i++)
		{
			if (current[i] == previous[i])
				check += 1;
		}

		if (check == 16) // 이동 실패
			return false;
		else // 이동 성공
			return true;
	}

	bool Left()
	{
		int previous[16];
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead; // 가장 왼쪽

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpDown();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum();
				if (pWork->Getnum() != 0)
				{
					if (Box == 0)
					{
						Box = pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if (pWork->Getnum() == Box)
						{
							Box += pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box = 0;
							pEnd = pEnd->GetpRight();

							Box = pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if (pWork->GetpRight() == NULL)
					pEnd->Setnum(Box);
				else
					pWork = pWork->GetpRight();
			}
		}

		// 처음보드와 바뀐보드 비교
		int current[16];
		n = 0;

		pDown = m_pHead;
		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pDown = pDown->GetpDown();

			for (int x = 0; x<4; x++)
			{
				current[n++] = pWork->Getnum();
				pWork = pWork->GetpRight();
			}
		}

		check = 0;
		for (int i = 0; i<16; i++)
		{
			if (current[i] == previous[i])
				check += 1;
		}

		if (check == 16) // 이동 실패
			return false;
		else // 이동 성공
			return true;
	}

	bool Right()
	{
		int previous[16];
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead->GetpRight()->GetpRight()->GetpRight(); // 가장 오른쪽

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpDown();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum();
				if (pWork->Getnum() != 0)
				{
					if (Box == 0)
					{
						Box = pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if (pWork->Getnum() == Box)
						{
							Box += pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box = 0;
							pEnd = pEnd->GetpLeft();

							Box = pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if (pWork->GetpLeft() == NULL)
					pEnd->Setnum(Box);
				else
					pWork = pWork->GetpLeft();
			}
		}

		// 처음보드와 바뀐보드 비교
		int current[16];
		n = 0;

		pDown = m_pHead->GetpRight()->GetpRight()->GetpRight();
		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pDown = pDown->GetpDown();

			for (int x = 0; x<4; x++)
			{
				current[n++] = pWork->Getnum();
				pWork = pWork->GetpLeft();
			}
		}

		check = 0;
		for (int i = 0; i<16; i++)
		{
			if (current[i] == previous[i])
				check += 1;
		}

		if (check == 16) // 이동 실패
			return false;
		else // 이동 성공
			return true;
	}

	int CheckEnd() // 2048이 있으면 win=1반환 움직일 수 없으면 lose=-1반환 아니면 0반환
	{
		Block * pWork;
		Block * pDown;
		pDown = m_pHead;
		int check = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pDown = pWork->GetpDown();

			for (int x = 0; x<4; x++)
			{
				if (pWork->Getnum() == 2048) // 2048이 존재한다면 win
					return 1;

				if (x == 0) // 왼쪽 테두리
				{
					if (y == 0) // 왼쪽 위 모서리
					{
						if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // 아래, 오른쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
					else if (y == 3) // 왼쪽아래 모서리
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // 위, 오른쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
					else // 왼쪽 가운데 
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // 위, 아래, 오른쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
				}
				else if (x == 3) // 오른쪽 테두리
				{
					if (y == 0) // 오른쪽 위 모서리
					{
						if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // 아래, 왼쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
					else if (y == 3) // 오른쪽 아래 모서리
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // 위, 왼쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
					else // 오른쪽 가운데
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // 위, 아래, 왼쪽의 숫자들과 모두 다르면서
							if (pWork != 0) // 0 이 아니라면,
							{
								check += 1;
							}
						}
					}
				}
				else if (y == 0 && x != 0 && x != 3) // 상단 테두리 가운데
				{
					if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
					{ // 아래, 왼쪽, 오른쪽의 숫자들과 모두 다르면서
						if (pWork != 0) // 0 이 아니라면,
						{
							check += 1;
						}
					}
				}
				else if (y == 3 && x != 0 && x != 3) // 하단 테두리 가운데
				{
					if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
					{ // 위, 왼쪽, 오른쪽의 숫자들과 모두 다르면서
						if (pWork != 0) // 0 이 아니라면,
						{
							check += 1;
						}
					}
				}
				else // 중심부
				{
					if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
					{ // 위 아래 오른쪽 왼쪽의 숫자들과 모두 다르면서
						if (pWork != 0) // 0 이 아니라면,
						{
							check += 1;
						}
					}
				}

				pWork = pWork->GetpRight();
			}
		}

		if (check == 16)
			return -1;
		else
			return 0;
	}

	void Random() // 빈칸에 랜덤으로 2 넣기
	{
		srand((unsigned int)time(NULL));
		int rand_x;
		int rand_y;

		Block * pWork;

		while (1)
		{
			pWork = m_pHead;

			rand_x = rand() % 4;
			rand_y = rand() % 4;

			for (int i = 0; i<rand_y; i++)
				pWork = pWork->GetpDown();
			for (int i = 0; i<rand_x; i++)
				pWork = pWork->GetpRight();

			if (pWork->Getnum() == 0) // 빈칸이면,
			{
				pWork->Setnum(2);
				break;
			}
			else
				continue;
		}
	}

	void Logging()
	{
		// 기록 남기기
		ofstream fout;
		fout.open("log.txt", ios::app);
		fout << "[result]" << endl;

		Block * pWork;
		pWork = m_pHead;
		while (1)
		{
			while (1)
			{
				fout << pWork->Getnum() << "  ";
				if (pWork->GetpRight() == NULL)
				{
					pWork = pWork->GetpLeft()->GetpLeft()->GetpLeft();
					break;
				}
				else
					pWork = pWork->GetpRight();
			}
			fout << "\n";

			if (pWork->GetpDown() == NULL)
			{
				fout << "\n";
				break;
			}
			else
				pWork = pWork->GetpDown();
		} // 기록남기기 끝

		fout.close();
	}

	void SpinRight()
	{
		int num[16];
		int cnt = 0;

		Block * pWork;
		pWork = m_pHead;
		// 배열에 저장하기
		while (1)
		{
			while (1)
			{
				num[cnt++] = pWork->Getnum();
				if (pWork->GetpRight() == NULL)
				{
					pWork = pWork->GetpLeft()->GetpLeft()->GetpLeft();
					break;
				}
				else
					pWork = pWork->GetpRight();
			}
			if (pWork->GetpDown() == NULL)
				break;
			else
				pWork = pWork->GetpDown();
		} // 배열에 저장하기 끝

		// 회전하기
		pWork = m_pHead->GetpRight()->GetpRight()->GetpRight();
		cnt = 0;
		while (1)
		{
			while (1)
			{
				pWork->Setnum(num[cnt++]);
				if (pWork->GetpDown() == NULL)
				{
					pWork = pWork->GetpUp()->GetpUp()->GetpUp();
					break;
				}
				else
					pWork = pWork->GetpDown();
			}
			if (pWork->GetpLeft() == NULL)
				break;
			else
				pWork = pWork->GetpLeft();
		} // 회전하기 끝
	}

	void SpinLeft()
	{
		int num[16];
		int cnt = 0;

		Block * pWork;
		pWork = m_pHead;
		// 배열에 저장하기
		while (1)
		{
			while (1)
			{
				num[cnt++] = pWork->Getnum();
				if (pWork->GetpRight() == NULL)
				{
					pWork = pWork->GetpLeft()->GetpLeft()->GetpLeft();
					break;
				}
				else
					pWork = pWork->GetpRight();
			}
			if (pWork->GetpDown() == NULL)
				break;
			else
				pWork = pWork->GetpDown();
		} // 배열에 저장하기 끝

		  // 회전하기
		pWork = m_pHead->GetpDown()->GetpDown()->GetpDown();
		cnt = 0;
		while (1)
		{
			while (1)
			{
				pWork->Setnum(num[cnt++]);
				if (pWork->GetpUp() == NULL)
				{
					pWork = pWork->GetpDown()->GetpDown()->GetpDown();
					break;
				}
				else
					pWork = pWork->GetpUp();
			}
			if (pWork->GetpRight() == NULL)
				break;
			else
				pWork = pWork->GetpRight();
		} // 회전하기 끝
	}
};


class CMy2048Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMy2048Doc();
	DECLARE_DYNCREATE(CMy2048Doc)

public:
	Board MyBoard;

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMy2048Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
