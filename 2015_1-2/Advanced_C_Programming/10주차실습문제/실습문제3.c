// 고급C프로그래밍 10주차 실습문제3

#include <stdio.h>

int main()
{
	char str[30];
	int i;

	FILE * fp=fopen("data.txt", "rt"); // data.txt 파일오픈
	if(fp==NULL)
	{
		printf("파일오픈 실패!");
		return -1;
	}

	fgets(str, sizeof(str), fp); // str 배열에 fp파일의 내용을 입력
	printf("%s \n", str);
	
	fclose(fp);
	return 0;
}