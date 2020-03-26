import java.util.Scanner;
import java.util.ArrayList;

public class p1_1_4 {
	
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		char cmd; // ��ɾ�. a, r, s, e
		int a; // �Է¹��� ����
		
		ArrayList<Integer> array = new ArrayList(); // ArrayList ��ü ����
		
		Oper op = new Oper(array); // �ʱ� �迭 ������ ���� ���� ����
		op.birth(); // �ʱ� �迭 ����
		
		while(true) // ���� ����
		{
			op.my_sort(); // �迭 ����

			// ���� ����Ʈ ����Ѵ�.
			System.out.print("List: ");
			for(int i=0; i<array.size(); i++)
				System.out.print(array.get(i)+" ");
			
			// ��� �Է�
			System.out.print("\nInput your command: ");
			cmd = scanner.next().charAt(0);
			
			// ��ɿ� ���� �۵�
			if(cmd == 'a') // �߰�
			{
				System.out.print("Input number to add: ");
				a = scanner.nextInt();
				
				if(array.indexOf(a) == -1) // �ߺ� ����.
					array.add(a);
			}
			else if(cmd == 'r') // ����
			{
				System.out.print("Input number to remove: ");
				a = scanner.nextInt();
				
				array.remove((Integer)a); // a��� ���� ã�Ƽ� ����
			}
			else if(cmd == 's') // �˻�
			{
				System.out.print("Input number to search: ");
				a = scanner.nextInt();
				
				if(array.indexOf(a) != -1) // ������ ���
					System.out.println("Index of " +a+ " is " +array.indexOf(a)); // a�� �ε��� ���
				else // �������� ���� ���
					System.out.println("Index of "+a+" is not exist.");
			}
			else if(cmd == 'e') // ����
			{
				break;
			}
			else // �߸��� ���
				System.out.println("Error : that command is non-exist");
		}
		
		scanner.close();
		return;
	}
}

class Oper
{
	ArrayList<Integer> ar;
	Oper(ArrayList<Integer> arr) {ar = arr;};
	
	void birth() // �ʱ� �迭 ����
	{
		int rand;
		
		for(int i=0; i<10; i++) // ���� �� 10�� �Է�
		{
			rand = (int)(Math.random()*20+1);
			for(int j=0; j<10; j++)
			{
				if(ar.size() == j) // �迭�� ���̸� ������ �Է�
				{
					ar.add(rand); // ������ �Է�
					break;
				}
				else if(rand == ar.get(j)) // �ߺ� �� Ȯ�� 0��°ĭ ~ ������
				{
					i--;
					break; // �ߺ��̸� ������ �����
				}
			}
		}
	}
	
	void my_sort() // �����ϴ� �޼ҵ�
	{
		int tmp1;
		int tmp2;
		
		// ���� ����
		for(int i=0; i<ar.size()-1; i++)
		{
			for(int j=0; j<ar.size()-1; j++)
			{
				if(ar.get(j) > ar.get(j+1)) // ������ �ʿ��Ѱ�?
				{
					// SWAP.
					tmp1=ar.get(j);
					tmp2=ar.get(j+1);
					
					ar.remove(j);
					ar.remove(j); // ������ j��° ĭ�� �������� ������ j+1 ��°�� j���Ǿ���.
					
					ar.add(j, tmp2);
					ar.add(j+1, tmp1);
				}
			}
		}
	}
}