// 고급C프 10주차 실습문제6

#include <stdio.h>

void main()
{
	FILE * fp;
	char file[32];
	char ch;
	int i=1;

	while(1) // fp 파일 입력
	{
	printf("파일1 이름: ");
	scanf("%s", file);
	fp=fopen(file, "rb");
	if(fp==0)
		printf("%s가 존재하지 않습니다.\n", file);
	else
		break;
	}

	while(feof(fp)==0)
	{
		fseek(fp, -i, SEEK_END); // 텍스트파일의 맨 끝부터 왼쪽으로 i 칸 
		ch=fgetc(fp);
		printf("%c", ch);

		i++;
	}
	
	fclose(fp);

	printf("\n");
}