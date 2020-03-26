#include <iostream>
using namespace std;

int main()
{
	int arr1_h, arr1_l, arr2_h, arr2_l;

	// ��� ũ���Է�
	cout << "Matrix A size: ";
	cin >> arr1_h >> arr1_l;

	cout << "Matrix B size: ";
	cin >> arr2_h >> arr2_l;

	// �����Ұ���
	if(arr1_l != arr2_h)
	{
		cout << "Incomputable" << endl << arr1_l << " != " << arr2_h << endl;
		return -1;	
	}

	// ��� �����Ҵ�
	int **arr1=new int*[arr1_h];
	for(int i=0; i<arr1_h; ++i)
		arr1[i]=new int[arr1_l];

	int **arr2=new int*[arr2_h];
	for(int j=0; j<arr2_h; ++j)
		arr2[j]=new int[arr2_l];

	// ��� �Է�
	cout << "A:" << endl;
	for(int i=0; i<arr1_h; i++)
	{
		for(int j=0; j<arr1_l; j++)
			cin >> arr1[i][j];
	}

	cout << "B:" << endl;
	for(int i=0; i<arr2_h; i++)
	{
		for(int j=0; j<arr2_l; j++)
			cin >> arr2[i][j];
	}

	// ��� ����
	cout << endl << "Multiplication Result" << endl;
	for(int i=0; i<arr1_h; i++)
	{
		for(int j=0; j<arr2_l; j++)
		{
			int sum=0;
			for(int k=0; k<arr1_l; k++)
			{
				sum+=arr1[i][k]*arr2[k][j];
			}
			cout << sum << " ";
		}
		cout << endl;
	}

	//�����Ҵ� ����
	for(int i=0; i<arr1_h; i++)
		delete [] arr1[i];
	delete [] arr1;

	for(int i=0; i<arr2_h; i++)
		delete [] arr2[i];
	delete [] arr2;

	return 0;
}