// 고급C프 10주차 실습문제5

#include <stdio.h>

void main()
{
	FILE *fp1, *fp2;
	char str[128];
	
	while(1) // fp1 파일 입력
	{
	printf("파일1 이름: ");
	scanf("%s", str);
	fp1=fopen(str, "rt");
	if(fp1==0)
		printf("%s가 존재하지 않습니다.\n", str);
	else
		break;
	}
	
	while(1) // fp2 파일 입력
	{
	printf("파일2 이름: ");
	scanf("%s", str);
	fp2=fopen(str, "rt");
	if(fp2==0)
		printf("%s가 존재하지 않습니다.\n", str);
	else
		break;
	}

	while(feof(fp1)==0) // fp1이 끝이 아니라면 반복.
	{
		if( fgetc(fp1)!=fgetc(fp2) ) // 두 글자가 다르거나, fp2가 끝이라면.
		{
			printf("두 파일은 서로 다릅니다.\n");
			return;
		}
	} // 아무 문제 없이 while문 종료 = 두 파일은 서로 같다

	printf("두 파일은 서로 같습니다.\n");
}