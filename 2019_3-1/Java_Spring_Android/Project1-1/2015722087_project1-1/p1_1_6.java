import java.util.Scanner;
public class p1_1_6 {

	public static void main(String[] args) 
	{
		String select; // 입력받은 데이터를 임시로 저장할 변수
 		Scanner scan = new Scanner(System.in);
		
		Car car = new Car(); // Car 객체 생성
		
		System.out.println("What you want to Brand ?");
		select = scan.next();
		car.brand = select; // Car 객체의 brand 변수에 select 입력
		
		System.out.println("What you want to Type ?");
		select = scan.next();
		car.model = select; // Car 객체의 model 변수에 select 입력
		
		System.out.println("What you want to Color ?");
		select = scan.next();
		car.color = select; // Car 객체의 color 변수에 select 입력
		
		System.out.println("What you want to Option ?");
		select = scan.next();
		car.option = select; // Car 객체의 option 변수에 select 입력
		
		System.out.println("What you want to Performance ?");
		select = scan.next();
		car.perform = select; // Car 객체의 perform 변수에 select 입력
		
		System.out.println("What you want to Insurance ?");
		select = scan.next();
		car.ins = select; // Car 객체의 ins 변수에 select 입력
		
		car.show(); // car 객체의 정보 출력
		
		scan.close();
		return;
	}
}
class Car extends Insurance // 6개의 클래스의 정보를 모두 상속받음
{
	void show() {
		// Car 클래스 내에 선언되지 않았지만 상속받은 멤버 변수를 출력
		System.out.println("\nThis is My Car !!");
		System.out.println("Brand : "+this.brand);
		System.out.println("Type : "+this.model);
		System.out.println("Color : "+this.color);
		System.out.println("Option : "+this.option);
		System.out.println("Performance : "+this.perform);
		System.out.println("Insurance : "+this.ins);
	}
}

class Brand
{
	String brand; // default : 같은 패키지라면 접근 가능
}

class Model extends Brand
{
	String model; // default : 같은 패키지라면 접근 가능
}

class Color extends Model
{
	String color; // default : 같은 패키지라면 접근 가능
}

class Option extends Color
{
	String option; // default : 같은 패키지라면 접근 가능
}

class Perform extends Option
{
	String perform; // default : 같은 패키지라면 접근 가능
}

class Insurance extends Perform
{
	String ins; // default : 같은 패키지라면 접근 가능
}