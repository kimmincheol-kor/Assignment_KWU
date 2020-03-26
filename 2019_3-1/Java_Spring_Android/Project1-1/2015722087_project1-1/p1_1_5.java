import java.util.Scanner;

public class p1_1_5 {

	public static void main(String[] args) 
	{
		Boggle game = new Boggle(); // 퍼즐이 진행될 클래스 객체 생성
		game.play_game(); // 게임 시작
		
		
		Scanner scanner = new Scanner(System.in);
		String word;
		
		
		while(true)
		{
			System.out.print("Input word: ");
			word = scanner.next(); // 찾을 단어 입력
			
			if(game.input(word) == false) // 게임 실행 -> 종료 여부 판단
			{
				System.out.println("Program END");
				break;
			}
		}
	}
}

class Boggle
{
	char[][] boggle = new char[3][3]; // 퍼즐이 될 배열
	
	void play_game()
	{
		// 3x3 크기의 랜덤 알파벳 배열 생성
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
		if(word.equals("$EXIT")) // 프로그램 강제종료
			return false;
		
		if(word.length() < 3) // 글자수가 3개보다 작으면 오류.
		{
			System.out.println("ERROR : The input word size is less than 3");
			return true;
		}
		
		int cnt=0; // 몇번째 알파벳이 진행중인지 표시. 첫알파벳 = 0
		int[][] pos = new int [word.length()][2]; // [알파벳 구분(첫번째 알파벳 = 0)][퍼즐에서의 위치 x,y]
		
		for(int i=0; i<word.length(); i++) // 초기값 -10로 초기화
		{
			pos[i][0] = -10;
			pos[i][1] = -10;
		}
		
		for(int len=0; len<9; len++) // 단어찾기
		{
			for(int a=0; a<3; a++) // 알파벳 찾기 행 구분.
			{
				for(int b=0; b<3; b++) // 알파벳 찾기 열 구분.
				{
					if(word.charAt(cnt) == boggle[a][b]) // 알파벳을 찾았다면,
					{ 
						for(int i=0; i<word.length(); i++) // 찾은 알파벳이 적절한지 확인
						{
							if(pos[i][0] == a && pos[i][1] == b) // 중복된 위치다.
								break;
							else if(cnt == 0 || ( Math.abs(a-pos[cnt-1][0]) <= 1 && Math.abs(b-pos[cnt-1][1]) <= 1 )) // 첫 알파벳이거나, 이전 알파벳과 인접한 위치인가 ?
							{
								pos[cnt][0]=a;
								pos[cnt++][1]=b;
								break;
							}	
						}
					}
					if(cnt==word.length()) // 다찾았다면,
						break;
				}
				if(cnt==word.length()) // 다찾았다면,
					break;
			}
			
			if(cnt == word.length()) // 단어를 찾았다면,
			{
				System.out.println(word);
				break;
			}
			else if(len == 8) // 단어를 못찾았다면,
				System.out.println("Non-exist");
		}
		return true;
	}
}

