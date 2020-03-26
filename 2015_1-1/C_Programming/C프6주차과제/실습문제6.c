/* C 프로그래밍
    6주차 실습 */

#include <stdio.h>

int main(void)
{
	int gold=1;
	int silver;
	
	for(silver=-1; gold<=27; gold+=2) // 실버는 부호의 역할, 골드는 숫자의 절대값역할을한다, 숫자는 2씩커지고 부호는 계속바뀐다. 숫자의크기가 27이될때까지 반복.
	{
		printf("%d ", gold*silver);
		silver*=-1; // 부호를 계속 바꾸는 역할
	}
	
	printf("\n");
	
	return 0;
}