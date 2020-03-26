// 고급C프로그래밍 9주차 실습문제2

#include <stdio.h>

typedef struct coffee
{
	char name[32];
	int price;
} Coffee; // 구조체 coffee의 이름은 Coffee

Coffee GetCoffee(void)
{
	Coffee cof;

	printf("커피 이름: ");
	scanf("%s", cof.name);
	printf("커피 가격: ");
	scanf("%d", &cof.price);

	return cof; // GetCoffee에서 받은 cof를 반환
}

void ShowCoffee(Coffee cof) // 구조체 출력
{
	printf("커피 이름: %s\n", cof.name);
	printf("커피 가격: %d\n", cof.price);
}

void main()
{
	Coffee coffee[2];
	int i;

	for(i=0; i<2; i++)
		coffee[i]=GetCoffee();

	puts("\n결과");
	for(i=0; i<2; i++)
		ShowCoffee(coffee[i]);
}