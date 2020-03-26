#include <iostream>
using namespace std;

int main()
{
	int size1, size2;

	cout << "Input Size: ";
	cin >> size1 >> size2;

	// 2차원배열 동적할당
	int **arr = new int*[size1];
	for(int i=0; i<size1; i++)
		arr[i]=new int[size2];

	cout << "Input array: " << endl;

	// 행렬 입력
	for(int i=0 ; i < size1; i++)
	{
		for(int j=0; j<size2; j++)
		{
			cin >> arr[i][j];

			if(arr[i][j] > 99 || arr[i][j] < 0)
			{
				cout << "범위를 초과(0~99)" << endl;
				return -1;
			}
		}
	}

	// 정렬
	for(int i=0; i<size1*size2; i++)
	{
		for(int k=0; k<size1; k++)
		{
			for(int j=0; j<size2-1; j++) //각줄정렬
			{
				if(arr[k][j]>arr[k][j+1])
				{
					int temp=arr[k][j];
					arr[k][j]=arr[k][j+1];
					arr[k][j+1]=temp;
				}
			}
		}

		for(int z=0; z<size1-1; z++) //맨앞맨뒤정렬
		{
			if(arr[z][size2-1]>arr[z+1][0])
			{
				int temp=arr[z][size2-1];
				arr[z][size2-1]=arr[z+1][0];
				arr[z+1][0]=temp;
			}
		}
	} // 정렬 끝

	cout << endl << "Output: " << endl;
	// 행렬 출력
	for(int i=0; i<size1; i++)
	{
		for(int j=0; j<size2; j++)
		{
			cout << arr[i][j] << " " ;
		}
		cout << endl;
	}


	cout << endl;

	// 동적할당 해제
	for(int i=0; i<size1; i++)
		delete [] arr[i];
	delete []arr;

	return 0;
}