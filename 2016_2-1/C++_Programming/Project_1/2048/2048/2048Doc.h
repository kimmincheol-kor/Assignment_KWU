
// 2048Doc.h : CMy2048Doc Ŭ������ �������̽�
//


#pragma once

// 2048 ��� ����, ��
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

		for (int y = 0; y<4; y++) // y��ǥ
		{
			for (int x = 0; x<4; x++) // x��ǥ
			{
				pWork = m_pHead;

				Block * pNew = new Block;
				pNew->Setnum(0); // ���۽� 0���� �ʱ�ȭ

				if (m_pHead == NULL)
					m_pHead = pNew;
				else
				{
					if (y == 0) // ���� ��
					{
						for (int i = 0; i<x - 1; i++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork = pWork->GetpRight();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);
					}
					else if (x == 0) // �� ���� ����
					{
						for (int i = 0; i<y - 1; i++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork = pWork->GetpDown();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
					else // ������
					{
						// �Էµ� ��ġ�� ������ ����Ŵ
						for (int i = 0; i<x - 1; i++)
							pWork = pWork->GetpRight();
						for (int i = 0; i<y; i++)
							pWork = pWork->GetpDown();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);

						pWork = m_pHead; // ��带 ����Ŵ

										 // �Էµ� ��ġ�� ������ ����Ŵ
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

		// ����� ���� 2 �Է�
		srand((unsigned int)time(NULL));
		int rand_x;
		int rand_y;

		// ù��° 2
		while (1)
		{
			pWork = m_pHead;

			rand_x = rand() % 4;
			rand_y = rand() % 4;

			for (int i = 0; i<rand_y; i++)
				pWork = pWork->GetpDown();
			for (int i = 0; i<rand_x; i++)
				pWork = pWork->GetpRight();

			if (pWork->Getnum() == 0) // ��ĭ�̸�,
			{
				pWork->Setnum(2);
				break;
			}
			else
				continue;
		}
		// 2��° 2
		while (1)
		{
			pWork = m_pHead;

			rand_x = rand() % 4;
			rand_y = rand() % 4;

			for (int i = 0; i<rand_y; i++)
				pWork = pWork->GetpDown();
			for (int i = 0; i<rand_x; i++)
				pWork = pWork->GetpRight();

			if (pWork->Getnum() == 0) // ��ĭ�̸�,
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

	~Board() // �޸� �Ҵ� ����
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

			exit << "�޸� �Ҵ� ���� ����\n";
		}
		exit.close();
	}

	bool Up()
	{
		int previous[16]; // �񱳿� �迭
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead; // ���� ����

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpRight();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum(); // �񱳿� �迭
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

		// ó������� �ٲﺸ�� ��
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

		if (check == 16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	bool Down()
	{
		int previous[16]; // �񱳿� �迭
		int n = 0;
		int check = 0;

		Block * pWork;
		Block * pDown;
		Block * pEnd;
		pDown = m_pHead->GetpDown()->GetpDown()->GetpDown(); // ���� �Ʒ���

		int Box = 0;

		for (int y = 0; y<4; y++)
		{
			pWork = pDown;
			pEnd = pWork;
			pDown = pDown->GetpRight();
			Box = 0;

			for (int x = 0; x<4; x++)
			{
				previous[n++] = pWork->Getnum(); // �񱳿� �迭
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

		// ó������� �ٲﺸ�� ��
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

		if (check == 16) // �̵� ����
			return false;
		else // �̵� ����
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
		pDown = m_pHead; // ���� ����

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

		// ó������� �ٲﺸ�� ��
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

		if (check == 16) // �̵� ����
			return false;
		else // �̵� ����
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
		pDown = m_pHead->GetpRight()->GetpRight()->GetpRight(); // ���� ������

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

		// ó������� �ٲﺸ�� ��
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

		if (check == 16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	int CheckEnd() // 2048�� ������ win=1��ȯ ������ �� ������ lose=-1��ȯ �ƴϸ� 0��ȯ
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
				if (pWork->Getnum() == 2048) // 2048�� �����Ѵٸ� win
					return 1;

				if (x == 0) // ���� �׵θ�
				{
					if (y == 0) // ���� �� �𼭸�
					{
						if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // �Ʒ�, �������� ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else if (y == 3) // ���ʾƷ� �𼭸�
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // ��, �������� ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else // ���� ��� 
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
						{ // ��, �Ʒ�, �������� ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
				}
				else if (x == 3) // ������ �׵θ�
				{
					if (y == 0) // ������ �� �𼭸�
					{
						if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // �Ʒ�, ������ ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else if (y == 3) // ������ �Ʒ� �𼭸�
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // ��, ������ ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else // ������ ���
					{
						if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
						{ // ��, �Ʒ�, ������ ���ڵ�� ��� �ٸ��鼭
							if (pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
				}
				else if (y == 0 && x != 0 && x != 3) // ��� �׵θ� ���
				{
					if (pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
					{ // �Ʒ�, ����, �������� ���ڵ�� ��� �ٸ��鼭
						if (pWork != 0) // 0 �� �ƴ϶��,
						{
							check += 1;
						}
					}
				}
				else if (y == 3 && x != 0 && x != 3) // �ϴ� �׵θ� ���
				{
					if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum())
					{ // ��, ����, �������� ���ڵ�� ��� �ٸ��鼭
						if (pWork != 0) // 0 �� �ƴ϶��,
						{
							check += 1;
						}
					}
				}
				else // �߽ɺ�
				{
					if (pWork->Getnum() != pWork->GetpUp()->Getnum() && pWork->Getnum() != pWork->GetpDown()->Getnum() && pWork->Getnum() != pWork->GetpRight()->Getnum() && pWork->Getnum() != pWork->GetpLeft()->Getnum())
					{ // �� �Ʒ� ������ ������ ���ڵ�� ��� �ٸ��鼭
						if (pWork != 0) // 0 �� �ƴ϶��,
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

	void Random() // ��ĭ�� �������� 2 �ֱ�
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

			if (pWork->Getnum() == 0) // ��ĭ�̸�,
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
		// ��� �����
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
		} // ��ϳ���� ��

		fout.close();
	}

	void SpinRight()
	{
		int num[16];
		int cnt = 0;

		Block * pWork;
		pWork = m_pHead;
		// �迭�� �����ϱ�
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
		} // �迭�� �����ϱ� ��

		// ȸ���ϱ�
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
		} // ȸ���ϱ� ��
	}

	void SpinLeft()
	{
		int num[16];
		int cnt = 0;

		Block * pWork;
		pWork = m_pHead;
		// �迭�� �����ϱ�
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
		} // �迭�� �����ϱ� ��

		  // ȸ���ϱ�
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
		} // ȸ���ϱ� ��
	}
};


class CMy2048Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy2048Doc();
	DECLARE_DYNCREATE(CMy2048Doc)

public:
	Board MyBoard;

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMy2048Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
