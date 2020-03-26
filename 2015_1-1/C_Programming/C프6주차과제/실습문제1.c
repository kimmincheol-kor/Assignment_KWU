/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int power;
	int super;

	printf("Input : ");
	scanf("%d", &power); //power 에 숫자입력

	for(super=1; power>=super; super++) // 슈퍼의값을1로 초기화; 파워가 슈퍼보다 크거나 같으면 명령문실행; 명령문이끝난후 슈퍼에 1을 더해줌
	{
		printf("%d\n", super);
	}

	// 처음에 슈퍼가 1, 그리고 ++ 연산해서 2, 3, 4 이렇게 올라가다가 슈퍼가 파워보다 같다면 반복문이 끝난다.

    return 0;
}