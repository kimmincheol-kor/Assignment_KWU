double power(int a, int b)
{
	int i;
	int result=1;

	for(i=0; i<b; i++)
	{
		result=result*a; // bȽ�� ��ŭ ����
	}

	return result; // result ��ȯ
}