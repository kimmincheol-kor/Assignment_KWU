/* C프로그래밍 10주차 실습 */

#include <stdio.h>

int encoding(int alpha1) //인코딩함수(암호화):아스키코드값으로 30을 더해줌
{
	int nalpha1;
    	
	nalpha1=alpha1+30;

	if(alpha1=='\n')
		return 0; //줄바꿈이면 0을 반환
	else	
	   return nalpha1;//아니면 nalpha값 반환
}

void decoding(int alpha2) // 디코딩은 30을 더한걸 다시 30 을 뺌
{
	int nalpha2;

    if(alpha2=='\n')
		return; // 줄바꿈이면 함수종료

	nalpha2=alpha2-30;

	printf("%c", nalpha2); // 30을 뺀값 (= 디코딩한값) 출력
}



int main()
{
     char   str[100]={0};
	 int   code[100]={0};
	 int     i=0,k=0,j=0,h=0;

	 printf("Enter message: ");
     while( (str[i++]=getchar()) != '\n' ); // str배열에 한 글자씩 입력, 개행문자(\n)가 들어올때까지
 

	 for(k=0; str[k]!=0; k++) // str배열의 값이 0이 아니면 반복
	 {
	    code[k]=str[k]; // code 배열은 str 배열의 문자를 숫자로 입력받음
	 }
	 
	 
	 printf("The encoded message: ");
	 for(j=0; code[j]!=0; j++) // code배열값이 0이 아니면 반복
	 {
	    printf("%c", encoding(code[j])); // 코드를 인코딩한값 출력
	 }
	 printf("\n");

	 printf("The decoded message: ");
	 for(h=0; code[h]!=0; h++) // code배열의 값이 0이 아니면 반복
	 {
		 decoding(encoding(code[h])); // 디코딩함수에 인코딩한 code배열값 입력
	 }
	 printf("\n");

     return 0;
}