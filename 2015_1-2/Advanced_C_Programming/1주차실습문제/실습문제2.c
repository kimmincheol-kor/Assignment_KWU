// C ���α׷��� 1���� �ǽ�����2

#include <stdio.h>

int main()
{
	int num;
	int i, j;

	printf("�Է�: ");
	scanf("%d", &num); // ���̸� num�� �Է� ����

	for(i=0; i<num; i++) // ��
	{
		if(num%2!=0){ // Ȧ��!
			if(i<num/2+1){ // ù��~�߰���
		for(j=0; j<i; j++) // ù��° ����
		{printf(" ");
			if(i==(num/2+1))
				break;}
		
		printf("*"); // ù��° �� �Է�
		
		if(num-2-(i*2)>0){ // ** �߰����� �� �Ѱ��� �Է�!!
		for(j=0; j<num-2-(i*2); j++)
		{printf(" ");} // �ι�° ����
		printf("*");} // �ι�° ��
		} // ����ž ��
			if(i>num/2){ // �Ʒ���ž
			for(j=num-i; j>1; j--) // ù��° ����.
			{printf(" ");}
			
			printf("*"); // ù��° ��.

			for(j=2*i-num ;j>0; j--) // �ι�° ����
			{printf(" ");}
		
			printf("*"); // �ι�° ��
			
			
			} // �Ʒ�ž ��

				} // Ȧ�� ��

		if(num%2==0){ // ¦�� !
			if(i<num/2){ //ù��~�߰�
			for(j=i; j>0; j--)
			{printf(" ");} // ù��° ����
			printf("*"); // ù��° ��
			for(j=(num-2)-(2*i); j>0; j--) // �ι�° ����
			{printf(" ");}
			printf("*"); // �ι�° ��

			if(i==num/2)
				continue;

			} // ù��~�߰� ��
			else if(num/2<i<num){ //�߰�~����
				for(j=num-i; j>1; j--) //ù��° ����
				{printf(" ");}
				printf("*"); //ù��° ��

				for(j=(i*2)-num; j>0; j--) // �ι�° ����
				{printf(" ");}
				printf("*"); // �ι�° ��

			} // �߰�~���� ��
		} // ¦�� ��

		

		printf("\n");
	}
}