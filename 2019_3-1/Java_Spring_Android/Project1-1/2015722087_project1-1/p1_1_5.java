import java.util.Scanner;

public class p1_1_5 {

	public static void main(String[] args) 
	{
		Boggle game = new Boggle(); // ������ ����� Ŭ���� ��ü ����
		game.play_game(); // ���� ����
		
		
		Scanner scanner = new Scanner(System.in);
		String word;
		
		
		while(true)
		{
			System.out.print("Input word: ");
			word = scanner.next(); // ã�� �ܾ� �Է�
			
			if(game.input(word) == false) // ���� ���� -> ���� ���� �Ǵ�
			{
				System.out.println("Program END");
				break;
			}
		}
	}
}

class Boggle
{
	char[][] boggle = new char[3][3]; // ������ �� �迭
	
	void play_game()
	{
		// 3x3 ũ���� ���� ���ĺ� �迭 ����
		for(int j=0; j<3; j++)
		{
			for(int i=0; i<3; i++)
				boggle[j][i]=(char)(Math.random()*26+65);
		}
		
		System.out.println("-------------");
		System.out.println("| "+boggle[0][0]+" | "+boggle[0][1]+" | "+boggle[0][2]+" |");
		System.out.println("-------------");
		System.out.println("| "+boggle[1][0]+" | "+boggle[1][1]+" | "+boggle[1][2]+" |");
		System.out.println("-------------");
		System.out.println("| "+boggle[2][0]+" | "+boggle[2][1]+" | "+boggle[2][2]+" |");
		System.out.println("-------------");
	}
	
	boolean input(String word)
	{
		if(word.equals("$EXIT")) // ���α׷� ��������
			return false;
		
		if(word.length() < 3) // ���ڼ��� 3������ ������ ����.
		{
			System.out.println("ERROR : The input word size is less than 3");
			return true;
		}
		
		int cnt=0; // ���° ���ĺ��� ���������� ǥ��. ù���ĺ� = 0
		int[][] pos = new int [word.length()][2]; // [���ĺ� ����(ù��° ���ĺ� = 0)][���񿡼��� ��ġ x,y]
		
		for(int i=0; i<word.length(); i++) // �ʱⰪ -10�� �ʱ�ȭ
		{
			pos[i][0] = -10;
			pos[i][1] = -10;
		}
		
		for(int len=0; len<9; len++) // �ܾ�ã��
		{
			for(int a=0; a<3; a++) // ���ĺ� ã�� �� ����.
			{
				for(int b=0; b<3; b++) // ���ĺ� ã�� �� ����.
				{
					if(word.charAt(cnt) == boggle[a][b]) // ���ĺ��� ã�Ҵٸ�,
					{ 
						for(int i=0; i<word.length(); i++) // ã�� ���ĺ��� �������� Ȯ��
						{
							if(pos[i][0] == a && pos[i][1] == b) // �ߺ��� ��ġ��.
								break;
							else if(cnt == 0 || ( Math.abs(a-pos[cnt-1][0]) <= 1 && Math.abs(b-pos[cnt-1][1]) <= 1 )) // ù ���ĺ��̰ų�, ���� ���ĺ��� ������ ��ġ�ΰ� ?
							{
								pos[cnt][0]=a;
								pos[cnt++][1]=b;
								break;
							}	
						}
					}
					if(cnt==word.length()) // ��ã�Ҵٸ�,
						break;
				}
				if(cnt==word.length()) // ��ã�Ҵٸ�,
					break;
			}
			
			if(cnt == word.length()) // �ܾ ã�Ҵٸ�,
			{
				System.out.println(word);
				break;
			}
			else if(len == 8) // �ܾ ��ã�Ҵٸ�,
				System.out.println("Non-exist");
		}
		return true;
	}
}

