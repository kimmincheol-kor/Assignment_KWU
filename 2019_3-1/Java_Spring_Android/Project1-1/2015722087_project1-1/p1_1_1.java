public class p1_1_1 {

	public static void main(String[] args) 
	{
		int array[] = {5, 90, 35, 45, 150, 3}; // ������ �迭
		int tmp; // swap �Ҷ� ����� ����
		
		System.out.println("Array Before Bubble Sort");
		for(int i=0; i<array.length; i++) // ȭ�鿡 �迭 ���.
		{
			System.out.print(array[i] + " ");
		}
		System.out.print("\n");
		
		for(int i=0; i<array.length-1; i++) // �迭�� ���� ��ŭ cycle.
		{
			for(int j=0; j<array.length-1; j++) // 1 cycle. �ݺ�
			{
				if(array[j] < array[j+1]) // ������ �ʿ��Ѱ�?
				{
					// SWAP.
					tmp=array[j]; 
					array[j]=array[j+1];
					array[j+1]=tmp;
				}
			}
		}
		
		
		System.out.println("Array After Bubble Sort");
		for(int i=0; i<array.length; i++) // ȭ�鿡 �迭 ���.
		{
			System.out.print(array[i] + " ");
		}

	}
}
