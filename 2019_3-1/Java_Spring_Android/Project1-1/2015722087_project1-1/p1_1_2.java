import java.util.Scanner;
//i have2&* n()*o ide%&57a.

public class p1_1_2 {

	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		
		String tmp; // �ܾ �Է¹��� ��Ʈ��.
		
		System.out.println("USER INPUT : ");
		tmp=scanner.next(); // ���ڿ� �Է¹ޱ�
		System.out.println("OUTPUT :");
		
		while(true) // ���ڿ��� �ܾ� ����� �𸣱⶧���� ���ѷ����� �ݺ�
		{
			for(int i=0; i<tmp.length(); i++)
			{
				// tmp �迭�� ����ִ� �ܾ��� �� ���� �ϳ��ϳ��� ���ĺ��϶��� ���
				if( ( (int)tmp.charAt(i)>=65 && (int)tmp.charAt(i)<=90 ) || ( (int)tmp.charAt(i)>=97 && (int)tmp.charAt(i)<=122))
					System.out.print(tmp.charAt(i));
			}
			// ���� �ܾ tmp �迭�� �ҷ�����.
			System.out.println("");
			tmp=scanner.next();
			
			if(tmp == null) // ���ڿ��� ����Ǿ����� �ݺ��� Ż��
				break;
		}
		
		scanner.close(); // ��ĳ�� ����
	}
}
