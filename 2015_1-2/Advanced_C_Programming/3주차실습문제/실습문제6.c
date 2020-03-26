// C 프로그래밍 3주차 실습문제6

#include <stdio.h>
#include <string.h>

void reverse();

void main()
{
	char str[32];

	printf("입력: ");
	gets(str);

	reverse(str);
	printf("reverse: %s\n", str);
}

void reverse(char arr[]) // 리버스 함수
{
	int i, temp;
	int last;
	
	for(i=0; i<32; i++) // 글자가 몇글자 인지 찾기.
	{
		if(arr[i]==0){
			last=i; // 총 글자수 = last
			break;}
	}

	if(last%2==0) // 글자수가 짝수이면
		for(i=0; i<last/2; i++)
		{
			temp=arr[last-1-i];
			arr[last-1-i]=arr[i];
			arr[i]=temp;
		}
	if(last%2!=0) // 글자수가 홀수이면 가운데 글자는 그대로!
		for(i=0; i<last/2; i++)
		{
			if(i!=last/2+1)
			   {temp=arr[last-1-i];
				arr[last-1-i]=arr[i];
				arr[i]=temp;}
		}


}