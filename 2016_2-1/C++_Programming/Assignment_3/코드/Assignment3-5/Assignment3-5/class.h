#ifndef __CLASS_H__
#define __CLASS_H__

#include <iomanip>

class MyBlock
{
private:
	int m_number;
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
	int length_x;
	int length_y;

public:
	MyBoard(int y, int x)
	{
		length_x=x;
		length_y=y;

		int num=0;
		m_pHead=NULL;
		MyBlock * pWork;

		for(int i=0; i<y; i++)
		{
			for(int j=0; j<x; j++)
			{
				pWork = m_pHead;

				MyBlock * pNew = new MyBlock;
				pNew->Setnum(num); // ���۽� 0���� �ʱ�ȭ
				num += 1;

				if(m_pHead==NULL)
					m_pHead=pNew;
				else
				{
					if(i==0) // ���� ��
					{
						for(int b=0; b<j-1; b++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork=pWork->GetpRight();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);
					}
					else if(j==0) // �� ���� ����
					{
						for(int a=0; a<i-1; a++) // �Էµ� ��ġ�� ������ ����Ŵ
							pWork=pWork->GetpDown();

						pWork->SetpDown(pNew);
						pNew->SetpUp(pWork);
					}
					else // ������
					{
						// �Էµ� ��ġ�� ������ ����Ŵ
						for(int a=0; a<j-1; a++) 
							pWork=pWork->GetpRight();
						for(int a=0; a<i; a++)
							pWork=pWork->GetpDown();

						pWork->SetpRight(pNew);
						pNew->SetpLeft(pWork);

						pWork=m_pHead; // ��带 ����Ŵ

						// �Էµ� ��ġ�� ������ ����Ŵ
						for(int a=0; a<i-1; a++)
							pWork=pWork->GetpDown();
						for(int a=0; a<j; a++) 
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
		MyBlock * pDown;
		MyBlock * pWork;
		MyBlock * pFirst;

		pDown=m_pHead;

		for(int i=0; i<length_y; i++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();
			
			if(pWork==NULL)
				break;

			pFirst=pWork;

			for(int j=0; j<length_x; j++)
			{
				pWork=pFirst;

				pFirst=pFirst->GetpRight();

				delete pWork;
			}
		}
	}

	void ShowBoard() // ���� ���
	{
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;

		cout << "[ PUZZLE ]" << endl;
		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();
			cout << "[";

			for(int x=0; x<length_x; x++)
			{
				cout << setw(4) << pWork->Getnum();

				pWork=pWork->GetpRight();
			}

			cout << setw(4) << "]" << endl;
		}
		cout << endl;
	}

	void Up()
	{
		MyBlock * pZero;
		pZero=NULL;
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;

		int temp;

		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<length_x; x++)
			{
				if(pWork->Getnum()==0)
				{
					pZero=pWork;
					break;
				}

				pWork=pWork->GetpRight();
			}
			if(pZero != NULL)
				break;
		} // pZero �� 0�� ����Ŵ.

		if(pZero->GetpUp()==NULL) // ���� ����� ������ ����.
			return;
		else // ��ȯ
		{
			temp=pZero->GetpUp()->Getnum();
			pZero->GetpUp()->Setnum(0);
			pZero->Setnum(temp);
			return;
		}
	}

	void Down()
	{
		MyBlock * pZero;
		pZero=NULL;
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;

		int temp;

		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<length_x; x++)
			{
				if(pWork->Getnum()==0)
				{
					pZero=pWork;
					break;
				}

				pWork=pWork->GetpRight();
			}
			if(pZero != NULL)
				break;
		} // pZero �� 0�� ����Ŵ.

		if(pZero->GetpDown()==NULL)
			return;
		else
		{
			temp=pZero->GetpDown()->Getnum();
			pZero->GetpDown()->Setnum(0);
			pZero->Setnum(temp);
			return;
		}
	}

	void Left()
	{
		MyBlock * pZero;
		pZero=NULL;
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;

		int temp;

		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<length_x; x++)
			{
				if(pWork->Getnum()==0)
				{
					pZero=pWork;
					break;
				}

				pWork=pWork->GetpRight();
			}
			if(pZero != NULL)
				break;
		} // pZero �� 0�� ����Ŵ.

		if(pZero->GetpLeft()==NULL)
			return;
		else
		{
			temp=pZero->GetpLeft()->Getnum();
			pZero->GetpLeft()->Setnum(0);
			pZero->Setnum(temp);
			return;
		}
	}

	void Right()
	{
		MyBlock * pZero;
		pZero=NULL;
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;

		int temp;

		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<length_x; x++)
			{
				if(pWork->Getnum()==0)
				{
					pZero=pWork;
					break;
				}

				pWork=pWork->GetpRight();
			}
			if(pZero != NULL)
				break;
		} // pZero �� 0�� ����Ŵ.

		if(pZero->GetpRight()==NULL)
			return;
		else
		{
			temp=pZero->GetpRight()->Getnum();
			pZero->GetpRight()->Setnum(0);
			pZero->Setnum(temp);
			return;
		}
	}

	int CheckEnd() // ������ �� ���������� üũ.
	{
		MyBlock * pWork;
		MyBlock * pDown;
		pDown=m_pHead;
		int num=0;
		int check=0;

		for(int y=0; y<length_y; y++)
		{
			pWork=pDown;
			pDown=pWork->GetpDown();

			for(int x=0; x<length_x; x++)
			{
				if(pWork->Getnum()==num++) // ������ΰ� �´ٸ� check + 1
				{
					check += 1;
				}

				pWork=pWork->GetpRight();
			}
		}

		if(check==length_y*length_x) // ��� ������ ������ζ�� 0 ��ȯ
			return 0;
		else
			return -1;
	}
};

#endif