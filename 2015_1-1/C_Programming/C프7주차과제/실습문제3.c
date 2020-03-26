/* C 프로그래밍
   7주차 실습 */

#include <stdio.h>

int main(void)
{
	int king;
	printf("점수 입력<0~10> : ");
	scanf("%d", &king);

	switch(king) // king에 값에 따라서 실행 영역이 달라짐
	{
	case 10: // king이 10이라면 이걸 실행
		printf("학점 : A\n");
		break; // 스위치문 탈출
	case 9:
		printf("학점 : B\n");
		break;
	case 8:
		printf("학점 : C\n");
		break;
	case 7:
		printf("학점 : D\n");
		break;
	default:
		printf("학점 : F\n");
	}
	return 0;
}