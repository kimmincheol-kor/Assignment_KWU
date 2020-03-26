#ifndef __BOARD_H__
#define __BOARD_H__

#include <iomanip>
#include <time.h>

class MyBlock
{
private:
	int m_number;
	int m_x;
	int m_y;
	MyBlock * m_pUp;
	MyBlock * m_pDown;
	MyBlock * m_pLeft;
	MyBlock * m_pRight;

public:
	MyBlock()
	{
		m_number=0;
		m_pUp=NULL;
		m_pDown=NULL;
		m_pRight=NULL;
		m_pLeft=NULL;
	}
	~MyBlock(){}

	void Setnum(int n)
	{
		m_number=n;
	}

	void Set_x(int n)
	{
		m_x=n;
	}

	void Set_y(int n)
	{
		m_y=n;
	}

	void SetpUp(MyBlock * node)
	{
		m_pUp=node;
	}

	void SetpDown(MyBlock * node)
	{
		m_pDown=node;
	}

	void SetpRight(MyBlock * node)
	{
		m_pRight=node;
	}

	void SetpLeft(MyBlock * node)
	{
		m_pLeft=node;
	}

	int Getnum()
	{
		return m_number;
	}

	int Get_x()
	{
		return m_x;
	}

	int Get_y()
	{
		return m_y;
	}

	MyBlock * GetpUp()
	{
		return m_pUp;
	}

	MyBlock * GetpDown()
	{
		return m_pDown;
	}

	MyBlock * GetpRight()
	{
		return m_pRight;
	}

	MyBlock * GetpLeft()
	{
		return m_pLeft;
	}
};

class MyBoard
{
private:
	MyBlock * m_pHead;

public:
	MyBoard()
	{
		m_pHead=NULL;
		MyBlock * pWork;

		for(int y=0; y<4; y++) // y��ǥ
		{
			for(int x=0; x<4; x++) // x��ǥ
			{
				pWork = m_pHead;

				MyBlock * pNew = new MyBlock;
				pNew->Setnum(0); // ���۽� 0���� �ʱ�ȭ
				pNew->Set_x(x);
				pNew->Set_y(y);

				if(m_pHead==NULL)
					m_pHead=pNew;
				else
				{
					if(y==0) // ���� ��
					{
						for(int i=0; i<x-1; i++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork=pWork->GetpRight();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);
					}
					else if(x==0) // �� ���� ����
					{
						for(int i=0; i<y-1; i++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork=pWork->GetpDown();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
					else // ������
					{
						// �Էµ� ��ġ�� ������ ����Ŵ
						for(int i=0; i<x-1; i++) 
							pWork=pWork->GetpRight();
						for(int i=0; i<y; i++)
							pWork=pWork->GetpDown();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);

						pWork=m_pHead; // ��带 ����Ŵ

						// �Էµ� ��ġ�� ������ ����Ŵ
						for(int i=0; i<y-1; i++)
							pWork=pWork->GetpDown();
						for(int i=0; i<x; i++) 
							pWork=pWork->GetpRight();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
				}
			}
		}
	}

	~MyBoard() // �޸� �Ҵ� ����
	{
		MyBlock * pTemp1;
		MyBlock * pTemp2;
		MyBlock * pTemp3;
		MyBlock * pTemp4;

		MyBlock * pWork1;
		MyBlock * pWork2;
		MyBlock * pWork3;
		MyBlock * pWork4;

		pTemp1=m_pHead;
		pTemp2=m_pHead->GetpDown();
		pTemp3=m_pHead->GetpDown()->GetpDown();
		pTemp4=m_pHead->GetpDown()->GetpDown()->GetpDown();

		while(1)
		{
			pWork1=pTemp1;
			pWork2=pTemp2;
			pWork3=pTemp3;
			pWork4=pTemp4;

			if(pWork1==NULL)
				break;

			pTemp1=pTemp1->GetpRight();
			pTemp2=pTemp2->GetpRight();
			pTemp3=pTemp3->GetpRight();
			pTemp4=pTemp4->GetpRight();

			delete pWork1;
			delete pWork2;
			delete pWork3;
			delete pWork4;
		}
	}

	bool Up()
	{
		int previous[16]; // �񱳿� �迭
		int n=0;
		int check=0;

		MyBlock * pWork;
		MyBlock * pDown;
		MyBlock * pEnd;
		pDown=m_pHead; // ���� ����

		int Box=0;

		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pEnd=pWork;
			pDown=pDown->GetpRight();
			Box=0;

			for(int x=0; x<4; x++)
			{
				previous[n++]=pWork->Getnum(); // �񱳿� �迭
				if(pWork->Getnum() != 0)
				{
					if(Box==0)
					{
						Box=pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if(pWork->Getnum() == Box)
						{
							Box+=pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box=0;
							pEnd=pEnd->GetpDown();

							Box=pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if(pWork->GetpDown() == NULL)
					pEnd->Setnum(Box);
				else
					pWork=pWork->GetpDown();
			}
		}

		// ó������� �ٲﺸ�� ��
		int current[16];
		n=0;

		pDown=m_pHead;
		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pDown->GetpRight();

			for(int x=0; x<4; x++)
			{
				current[n++]=pWork->Getnum();
				pWork=pWork->GetpDown();
			}
		}
		
		check=0;
		for(int i=0; i<16; i++)
		{
			if(current[i]==previous[i])
				check+=1;
		}

		if(check==16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	bool Down()
	{
		int previous[16]; // �񱳿� �迭
		int n=0;
		int check=0;

		MyBlock * pWork;
		MyBlock * pDown;
		MyBlock * pEnd;
		pDown=m_pHead->GetpDown()->GetpDown()->GetpDown(); // ���� �Ʒ���

		int Box=0;

		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pEnd=pWork;
			pDown=pDown->GetpRight();
			Box=0;

			for(int x=0; x<4; x++)
			{
				previous[n++]=pWork->Getnum(); // �񱳿� �迭
				if(pWork->Getnum() != 0)
				{
					if(Box==0)
					{
						Box=pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if(pWork->Getnum() == Box)
						{
							Box+=pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box=0;
							pEnd=pEnd->GetpUp();

							Box=pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if(pWork->GetpUp() == NULL)
					pEnd->Setnum(Box);
				else
					pWork=pWork->GetpUp();
			}
		}

		// ó������� �ٲﺸ�� ��
		int current[16];
		n=0;

		pDown=m_pHead->GetpDown()->GetpDown()->GetpDown();
		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pDown->GetpRight();

			for(int x=0; x<4; x++)
			{
				current[n++]=pWork->Getnum();
				pWork=pWork->GetpUp();
			}
		}
		
		check=0;
		for(int i=0; i<16; i++)
		{
			if(current[i]==previous[i])
				check+=1;
		}

		if(check==16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	bool Left()
	{
		int previous[16];
		int n=0;
		int check=0;

		MyBlock * pWork;
		MyBlock * pDown;
		MyBlock * pEnd;
		pDown=m_pHead; // ���� ����

		int Box=0;

		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pEnd=pWork;
			pDown=pDown->GetpDown();
			Box=0;

			for(int x=0; x<4; x++)
			{
				previous[n++]=pWork->Getnum();
				if(pWork->Getnum() != 0)
				{
					if(Box==0)
					{
						Box=pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if(pWork->Getnum() == Box)
						{
							Box+=pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box=0;
							pEnd=pEnd->GetpRight();

							Box=pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if(pWork->GetpRight() == NULL)
					pEnd->Setnum(Box);
				else
					pWork=pWork->GetpRight();
			}
		}

		// ó������� �ٲﺸ�� ��
		int current[16];
		n=0;

		pDown=m_pHead;
		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pDown->GetpDown();

			for(int x=0; x<4; x++)
			{
				current[n++]=pWork->Getnum();
				pWork=pWork->GetpRight();
			}
		}
		
		check=0;
		for(int i=0; i<16; i++)
		{
			if(current[i]==previous[i])
				check+=1;
		}

		if(check==16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	bool Right()
	{
		int previous[16];
		int n=0;
		int check=0;

		MyBlock * pWork;
		MyBlock * pDown;
		MyBlock * pEnd;
		pDown=m_pHead->GetpRight()->GetpRight()->GetpRight(); // ���� ������

		int Box=0;

		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pEnd=pWork;
			pDown=pDown->GetpDown();
			Box=0;

			for(int x=0; x<4; x++)
			{
				previous[n++]=pWork->Getnum();
				if(pWork->Getnum() != 0)
				{
					if(Box==0)
					{
						Box=pWork->Getnum();
						pWork->Setnum(0);
					}
					else
					{
						if(pWork->Getnum() == Box)
						{
							Box+=pWork->Getnum();
							pWork->Setnum(0);
						}
						else
						{
							pEnd->Setnum(Box);
							Box=0;
							pEnd=pEnd->GetpLeft();

							Box=pWork->Getnum();
							pWork->Setnum(0);
						}
					}
				}

				if(pWork->GetpLeft() == NULL)
					pEnd->Setnum(Box);
				else
					pWork=pWork->GetpLeft();
			}
		}

		// ó������� �ٲﺸ�� ��
		int current[16];
		n=0;

		pDown=m_pHead->GetpRight()->GetpRight()->GetpRight();
		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pDown->GetpDown();

			for(int x=0; x<4; x++)
			{
				current[n++]=pWork->Getnum();
				pWork=pWork->GetpLeft();
			}
		}
		
		check=0;
		for(int i=0; i<16; i++)
		{
			if(current[i]==previous[i])
				check+=1;
		}

		if(check==16) // �̵� ����
			return false;
		else // �̵� ����
			return true;
	}

	int CheckEnd() // 2048�� ������ win=1��ȯ ������ �� ������ lose=-1��ȯ �ƴϸ� 0��ȯ
	{
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;
		int check=0;

		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<4; x++)
			{
				if(pWork->Getnum()==2048) // 2048�� �����Ѵٸ� win
					return 1;

				if(x==0) // ���� �׵θ�
				{
					if(y==0) // ���� �� �𼭸�
					{
						if(pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum())
						{ // �Ʒ�, �������� ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else if(y==3) // ���ʾƷ� �𼭸�
					{
						if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum())
						{ // ��, �������� ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else // ���� ��� 
					{
						if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum())
						{ // ��, �Ʒ�, �������� ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
				}
				else if(x==3) // ������ �׵θ�
				{
					if(y==0) // ������ �� �𼭸�
					{
						if(pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum())
						{ // �Ʒ�, ������ ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else if(y==3) // ������ �Ʒ� �𼭸�
					{
						if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum())
						{ // ��, ������ ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
					else // ������ ���
					{
						if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum())
						{ // ��, �Ʒ�, ������ ���ڵ�� ��� �ٸ��鼭
							if(pWork != 0) // 0 �� �ƴ϶��,
							{
								check += 1;
							}
						}
					}
				}
				else if(y==0 && x!=0 && x!=3) // ��� �׵θ� ���
				{
					if(pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum())
					{ // �Ʒ�, ����, �������� ���ڵ�� ��� �ٸ��鼭
						if(pWork != 0) // 0 �� �ƴ϶��,
						{
							check += 1;
						}
					}
				}
				else if(y==3 && x!=0 && x!=3) // �ϴ� �׵θ� ���
				{
					if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum())
					{ // ��, ����, �������� ���ڵ�� ��� �ٸ��鼭
						if(pWork != 0) // 0 �� �ƴ϶��,
						{
							check += 1;
						}
					}
				}
				else // �߽ɺ�
				{
					if(pWork->Getnum()!=pWork->GetpUp()->Getnum() && pWork->Getnum()!=pWork->GetpDown()->Getnum() && pWork->Getnum()!=pWork->GetpRight()->Getnum() && pWork->Getnum()!=pWork->GetpLeft()->Getnum())
					{ // �� �Ʒ� ������ ������ ���ڵ�� ��� �ٸ��鼭
						if(pWork != 0) // 0 �� �ƴ϶��,
						{
							check += 1;
						}
					}
				}

				pWork=pWork->GetpRight();
			}
		}
		
		if(check == 16)
			return -1;
		else
			return 0;
	}

	void ShowBoard() // ���� ���
	{
		MyBlock * pWork;
		MyBlock * pDown;
		int value;
		pDown=m_pHead;

		cout << "[ BOARD ]" << endl;
		for(int y=0; y<4; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();
			cout << "[";

			for(int x=0; x<4; x++)
			{
				value=pWork->Getnum();

				if(value == 0)
					cout << setw(6) << "-";
				else
					cout << setw(6) << value;

				pWork=pWork->GetpRight();
			}

			cout << setw(6) << "]" << endl;
		}
		cout << endl;
	}

	void Random() // ��ĭ�� �������� 2 �ֱ�
	{
		srand((unsigned int)time(NULL));
		int rand_x;
		int rand_y;

		MyBlock * pWork;

		while(1)
		{
			pWork=m_pHead;

			rand_x=rand()%4;
			rand_y=rand()%4;

			for(int i=0; i<rand_y; i++)
				pWork=pWork->GetpDown();
			for(int i=0; i<rand_x; i++) 
				pWork=pWork->GetpRight();

			if( pWork->Getnum() == 0 ) // ��ĭ�̸�,
			{
				pWork->Setnum(2);
				break;
			}
			else
				continue;
		}
	}
};

#endif