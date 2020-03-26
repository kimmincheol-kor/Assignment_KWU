import java.util.Scanner;
//i have2&* n()*o ide%&57a.

public class p1_1_2 {

	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		
		String tmp; // 단어를 입력받을 스트링.
		
		System.out.println("USER INPUT : ");
		tmp=scanner.next(); // 문자열 입력받기
		System.out.println("OUTPUT :");
		
		while(true) // 문자열이 단어 몇개인지 모르기때문에 무한루프로 반복
		{
			for(int i=0; i<tmp.length(); i++)
			{
				// tmp 배열에 들어있는 단어의 각 문자 하나하나가 알파벳일때만 출력
				if( ( (int)tmp.charAt(i)>=65 && (int)tmp.charAt(i)<=90 ) || ( (int)tmp.charAt(i)>=97 && (int)tmp.charAt(i)<=122))
					System.out.print(tmp.charAt(i));
			}
			// 다음 단어를 tmp 배열에 불러오기.
			System.out.println("");
			tmp=scanner.next();
			
			if(tmp == null) // 문자열이 종료되었으면 반복문 탈출
				break;
		}
		
		scanner.close(); // 스캐너 종료
	}
}
