public class p1_1_1 {

	public static void main(String[] args) 
	{
		int array[] = {5, 90, 35, 45, 150, 3}; // 정렬할 배열
		int tmp; // swap 할때 사용할 변수
		
		System.out.println("Array Before Bubble Sort");
		for(int i=0; i<array.length; i++) // 화면에 배열 출력.
		{
			System.out.print(array[i] + " ");
		}
		System.out.print("\n");
		
		for(int i=0; i<array.length-1; i++) // 배열의 길이 만큼 cycle.
		{
			for(int j=0; j<array.length-1; j++) // 1 cycle. 반복
			{
				if(array[j] < array[j+1]) // 정렬이 필요한가?
				{
					// SWAP.
					tmp=array[j]; 
					array[j]=array[j+1];
					array[j+1]=tmp;
				}
			}
		}
		
		
		System.out.println("Array After Bubble Sort");
		for(int i=0; i<array.length; i++) // 화면에 배열 출력.
		{
			System.out.print(array[i] + " ");
		}

	}
}
