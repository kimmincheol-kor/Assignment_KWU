
public class p1_1_3 {

	public static void main(String[] args) 
	{
		// Math.random() �޼ҵ�� 0~1 ������ ���� �������� ���´� 1~6�� ������ �ϱ����� *6+1
		int dice1 = (int)(Math.random() * 6 + 1); // ù��° �ֻ���
		int dice2 = (int)(Math.random() * 6 + 1); // �ι�° �ֻ���
	
		// ����� ���
		System.out.println("The first die comes up " + dice1);
		System.out.println("The second die comes up " + dice2);
		System.out.println("Your total roll is  " + (dice1 + dice2));
	}
}