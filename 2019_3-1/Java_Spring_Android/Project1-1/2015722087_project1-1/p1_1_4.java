import java.util.Scanner;
import java.util.ArrayList;

public class p1_1_4 {
	
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		char cmd; // 명령어. a, r, s, e
		int a; // 입력받을 정수
		
		ArrayList<Integer> array = new ArrayList(); // ArrayList 객체 생성
		
		Oper op = new Oper(array); // 초기 배열 생성과 정렬 역할 수행
		op.birth(); // 초기 배열 생성
		
		while(true) // 게임 시작
		{
			op.my_sort(); // 배열 정렬

			// 현재 리스트 출력한다.
			System.out.print("List: ");
			for(int i=0; i<array.size(); i++)
				System.out.print(array.get(i)+" ");
			
			// 명령 입력
			System.out.print("\nInput your command: ");
			cmd = scanner.next().charAt(0);
			
			// 명령에 따른 작동
			if(cmd == 'a') // 추가
			{
				System.out.print("Input number to add: ");
				a = scanner.nextInt();
				
				if(array.indexOf(a) == -1) // 중복 방지.
					array.add(a);
			}
			else if(cmd == 'r') // 삭제
			{
				System.out.print("Input number to remove: ");
				a = scanner.nextInt();
				
				array.remove((Integer)a); // a라는 값을 찾아서 제거
			}
			else if(cmd == 's') // 검색
			{
				System.out.print("Input number to search: ");
				a = scanner.nextInt();
				
				if(array.indexOf(a) != -1) // 존재할 경우
					System.out.println("Index of " +a+ " is " +array.indexOf(a)); // a의 인덱스 출력
				else // 존재하지 않을 경우
					System.out.println("Index of "+a+" is not exist.");
			}
			else if(cmd == 'e') // 종료
			{
				break;
			}
			else // 잘못된 명령
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
	
	void birth() // 초기 배열 생성
	{
		int rand;
		
		for(int i=0; i<10; i++) // 랜덤 값 10개 입력
		{
			rand = (int)(Math.random()*20+1);
			for(int j=0; j<10; j++)
			{
				if(ar.size() == j) // 배열의 끝이면 랜덤값 입력
				{
					ar.add(rand); // 랜덤값 입력
					break;
				}
				else if(rand == ar.get(j)) // 중복 값 확인 0번째칸 ~ 끝까지
				{
					i--;
					break; // 중복이면 랜덤값 재생성
				}
			}
		}
	}
	
	void my_sort() // 정렬하는 메소드
	{
		int tmp1;
		int tmp2;
		
		// 버블 정렬
		for(int i=0; i<ar.size()-1; i++)
		{
			for(int j=0; j<ar.size()-1; j++)
			{
				if(ar.get(j) > ar.get(j+1)) // 정렬이 필요한가?
				{
					// SWAP.
					tmp1=ar.get(j);
					tmp2=ar.get(j+1);
					
					ar.remove(j);
					ar.remove(j); // 위에서 j번째 칸이 지워졌기 때문에 j+1 번째가 j가되었다.
					
					ar.add(j, tmp2);
					ar.add(j+1, tmp1);
				}
			}
		}
	}
}