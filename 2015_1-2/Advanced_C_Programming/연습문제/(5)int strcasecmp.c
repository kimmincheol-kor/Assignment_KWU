// 대소문자 무시하고 문자열 비교 함수

#include <stdio.h>
#include <string.h>
int stricmp(const char *lhs, const char *rhs);

void main()
{
	char str1[32]={"apple"};
	char str2[32]={"APPLE"};
	char str3[32]={"APple"};
	char str4[32]={"appLE"};
	char str5[32]={"applell"};
	char str6[32]={"Applell"};

	printf("%d \n", stricmp(str1, str2));
	printf("%d \n", stricmp(str1, str3));
	printf("%d \n", stricmp(str1, str4));
	printf("%d \n", stricmp(str1, str5));
	printf("%d \n", stricmp(str1, str6));
	printf("%d \n", stricmp(str5, str6));
}