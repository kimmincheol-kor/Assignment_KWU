/* C���α׷��� 10���� �ǽ� */

#include <stdio.h>

int encoding(int alpha1) //���ڵ��Լ�(��ȣȭ):�ƽ�Ű�ڵ尪���� 30�� ������
{
	int nalpha1;
    	
	nalpha1=alpha1+30;

	if(alpha1=='\n')
		return 0; //�ٹٲ��̸� 0�� ��ȯ
	else	
	   return nalpha1;//�ƴϸ� nalpha�� ��ȯ
}

void decoding(int alpha2) // ���ڵ��� 30�� ���Ѱ� �ٽ� 30 �� ��
{
	int nalpha2;

    if(alpha2=='\n')
		return; // �ٹٲ��̸� �Լ�����

	nalpha2=alpha2-30;

	printf("%c", nalpha2); // 30�� ���� (= ���ڵ��Ѱ�) ���
}



int main()
{
     char   str[100]={0};
	 int   code[100]={0};
	 int     i=0,k=0,j=0,h=0;

	 printf("Enter message: ");
     while( (str[i++]=getchar()) != '\n' ); // str�迭�� �� ���ھ� �Է�, ���๮��(\n)�� ���ö�����
 

	 for(k=0; str[k]!=0; k++) // str�迭�� ���� 0�� �ƴϸ� �ݺ�
	 {
	    code[k]=str[k]; // code �迭�� str �迭�� ���ڸ� ���ڷ� �Է¹���
	 }
	 
	 
	 printf("The encoded message: ");
	 for(j=0; code[j]!=0; j++) // code�迭���� 0�� �ƴϸ� �ݺ�
	 {
	    printf("%c", encoding(code[j])); // �ڵ带 ���ڵ��Ѱ� ���
	 }
	 printf("\n");

	 printf("The decoded message: ");
	 for(h=0; code[h]!=0; h++) // code�迭�� ���� 0�� �ƴϸ� �ݺ�
	 {
		 decoding(encoding(code[h])); // ���ڵ��Լ��� ���ڵ��� code�迭�� �Է�
	 }
	 printf("\n");

     return 0;
}