import java.util.Scanner;
public class p1_1_6 {

	public static void main(String[] args) 
	{
		String select; // �Է¹��� �����͸� �ӽ÷� ������ ����
 		Scanner scan = new Scanner(System.in);
		
		Car car = new Car(); // Car ��ü ����
		
		System.out.println("What you want to Brand ?");
		select = scan.next();
		car.brand = select; // Car ��ü�� brand ������ select �Է�
		
		System.out.println("What you want to Type ?");
		select = scan.next();
		car.model = select; // Car ��ü�� model ������ select �Է�
		
		System.out.println("What you want to Color ?");
		select = scan.next();
		car.color = select; // Car ��ü�� color ������ select �Է�
		
		System.out.println("What you want to Option ?");
		select = scan.next();
		car.option = select; // Car ��ü�� option ������ select �Է�
		
		System.out.println("What you want to Performance ?");
		select = scan.next();
		car.perform = select; // Car ��ü�� perform ������ select �Է�
		
		System.out.println("What you want to Insurance ?");
		select = scan.next();
		car.ins = select; // Car ��ü�� ins ������ select �Է�
		
		car.show(); // car ��ü�� ���� ���
		
		scan.close();
		return;
	}
}
class Car extends Insurance // 6���� Ŭ������ ������ ��� ��ӹ���
{
	void show() {
		// Car Ŭ���� ���� ������� �ʾ����� ��ӹ��� ��� ������ ���
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
	String brand; // default : ���� ��Ű����� ���� ����
}

class Model extends Brand
{
	String model; // default : ���� ��Ű����� ���� ����
}

class Color extends Model
{
	String color; // default : ���� ��Ű����� ���� ����
}

class Option extends Color
{
	String option; // default : ���� ��Ű����� ���� ����
}

class Perform extends Option
{
	String perform; // default : ���� ��Ű����� ���� ����
}

class Insurance extends Perform
{
	String ins; // default : ���� ��Ű����� ���� ����
}