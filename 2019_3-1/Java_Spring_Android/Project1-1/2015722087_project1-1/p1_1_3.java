
public class p1_1_3 {

	public static void main(String[] args) 
	{
		// Math.random() 메소드는 0~1 사이의 값이 랜덤으로 나온다 1~6이 나오게 하기위해 *6+1
		int dice1 = (int)(Math.random() * 6 + 1); // 첫번째 주사위
		int dice2 = (int)(Math.random() * 6 + 1); // 두번째 주사위
	
		// 결과값 출력
		System.out.println("The first die comes up " + dice1);
		System.out.println("The second die comes up " + dice2);
		System.out.println("Your total roll is  " + (dice1 + dice2));
	}
}