/* C 프로그래밍
   9주차 실습문제 */

#include <stdio.h>

void reverse(int num) // asd 대입
{
	if(num==0){
		return; // 함수 종료, 반환x
	}
	else
	printf("%d", num%10); // 일의자리수 출력
	reverse(num/10); // 일의자리수 제거
}
	
int main()
{
	int asd, result;
	
	printf("Input : ");
	scanf("%d", &asd); // asd 숫자 입력

	printf("Output : ");
    reverse(asd); // 함수 출력 리버스함수에서 출력될내용을 불러옴

	printf("\n");

	return 0;
}