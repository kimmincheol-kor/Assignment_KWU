/* C프로그래밍 11주차 실습 */

#include <stdio.h>

void main()
{
	char ch='A';
	int n1=10;
	double n2=2.6;

	char *pCh=&ch;
	int *pN1=&n1;
	double *pN2=&n2; // 포인터 변수의 선언과 동시에 피연산자 n2의 주소값을 반환

	printf("ch의 값 : %c\t주소 : %p\n", ch, &ch);
	printf("n1의 값 : %d\t주소 : %p\n", n1, &n1);
	printf("n2의 값 : %.1f\t주소 : %p\n\n", n2, &n2); //소수점 1자리까지 n2 출력, n2의 주소값 출력 (%p는 포인터의 주소값을 출력하는 서식문자이다.)

	printf("pCh의 값 : %c\t가리키는 곳의 값 : %c\n", pCh, *pCh); //*pCh=&ch 에서 *pCh는 주소값이고 pCh는 변수값이다.
	printf("pN1의 값 : %p\t가리키는 곳의 값 : %d\n", pN1, *pN1);
	printf("pN2의 값 : %p\t가리키는 곳의 값 : %.1f\n\n", pN2, *pN2);

	ch='B'; //*pCh는 주소값인데 그곳에 변수를 입력, ch의 주소값과 변수값이 변경.	
	*pN1=27;
	*pN2=1.5;

	printf("ch의 값 : %c\t주소 : %p\n", *pCh, pCh); // ch가 있는 주소에 새로운 변수가 입력되어 B 출력, 새로운 주소 출력
	printf("n1의 값 : %d\t주소 : %d\n", n1, &n1);
	printf("n2의 값 : %.1f\t주소 : %d\n\n", n2, &n2);

	return;
}