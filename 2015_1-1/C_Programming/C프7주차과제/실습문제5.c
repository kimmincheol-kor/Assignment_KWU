/* C 프로그래밍
   7주차 실습 */

#include <stdio.h>

int main(void)
{
	int what;
	int one, two;

	printf("더하기<1>, 빼기<2>, 곱하기<3>, 나누기<4>, 종료<5>\n");
	
	while(1) // 연산자입력 반복. 5를입력할때까지 무한
	{
	printf("연산자 번호 입력 : ");
	scanf("%d", &what);

	switch(what) // what의 값에 따라 실행 하는게 다름
	{
	
	case 1: // 더하기
		printf("정수 두 개 입력 : ");
		scanf("%d %d", &one, &two);
		printf(">> %d + %d = %d", one, two, one+two);
		break;
	
	case 2: // 빼기
		printf("정수 두 개 입력 : ");
		scanf("%d %d", &one, &two);
		printf(">> %d - %d = %d", one, two, one-two);
		break;
	
	case 3: // 곱하기
		printf("정수 두 개 입력 : ");
		scanf("%d %d", &one, &two);
		printf(">> %d * %d = %d", one, two, one*two);
		break;
	
	case 4: // 나누기
		printf("정수 두 개 입력 : ");
		scanf("%d %d", &one, &two);
		printf(">> %d / %d = %d", one, two, one/two);
		break;
	
	case 5: // 프로그램종료
		printf("프로그램 종료");
		break;
	
	default: // 12345번이 아닌 입력
	    printf("알맞은 번호를 입력하세요");
	  }
	
	printf("\n");
	
	if(what==5) // what에 5를 입력하면 프로그램 종료이므로 브레이크로 탈출
	{break;}
	}
return 0;	
}