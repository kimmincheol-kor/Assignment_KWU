#include <iostream>
using namespace std;

int main()
{
	int input;
	char even[5]={"even"};
	int result;
	int a,b,c,d,e;
	int sum, prime=2;

	cout << "The number is ";
	cin >> input;

	result=input/7;
	if((input%7)==0)
		cout << "It can be divided by 7, the result is " << result << endl;
	else
		cout << "It cannot be divided by 7" << endl;

	result=input/11;
	if((input%11)==0)
		cout << "It can be divided by 11, the result is " << result << endl;
	else
		cout << "It cannot be divided by 11" << endl;

	result=input/13;
	if((input%13)==0)
		cout << "It can be divided by 13, the result is " << result << endl;
	else
		cout << "It cannot be divided by 13" << endl;

	a=input/10000;
	b=input%10000/1000;
	c=input%1000/100;
	d=input%100/10;
	e=input%10;
	
	sum=a+b+c+d+e;
	
	cout << "The sum of every digit is " << sum << ", it is ";
	
	if(sum%2==0)
		cout << "even number" << endl;
	else
		cout << "odd number" << endl;

	// check that input is prime number or not.
	while(prime<=input)
	{
		if(input%prime==0)
			break;

		prime++;
	}

	if(prime!=input)
		cout << "It is not a prime number" << endl;
	else
		cout << "It is a prime number" << endl;

	return 0;
}