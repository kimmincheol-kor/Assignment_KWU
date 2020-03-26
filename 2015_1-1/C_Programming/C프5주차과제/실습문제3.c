/* C 프로그래밍
    5주차 실습 */

#include <stdio.h>

int main(void) //main 함수
{
	int mn; // 자료형 특이하게 할라고 mn 머니 fh 파이브헌드레드 이런식으로 했습니다
	int fh;
    int oh;
	int ft;
	int ot;
	int mg; // 자료형들 선언및 초기화

	printf("## 금액 입력 : ");
	scanf("%d", &mn); // 머니에 금액 입력

	fh=mn/500; // 500으로 나눈 몫
	oh=mn%500/100; // 500으로나눈 나머지를 100으로나눈몫
	ft=mn%500%100/50; 
	ot=mn%500%100%50/10;
	mg=mn%500%100%50%10; // %는 나머지를 출력 / 는 몫을 출력

	printf("500원짜리 ==> %d개\n", fh);
	printf("100원짜리 ==> %d개\n", oh);
	printf("50원짜리 ==> %d개\n", ft);
	printf("10원짜리 ==> %d개\n", ot); // %d 써서 정수 출력
	printf("바꾸지 못한 잔돈 ==> %d원\n", mg);

	return 0; // 이것도 제가 혼자했습니다 scanf할때 & 안쓴거 까먹고 조교님께 질문한것밖에없습니다
}