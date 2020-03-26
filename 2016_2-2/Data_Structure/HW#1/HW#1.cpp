#include <iostream>
using namespace std;

#include "class.h" // 헤더파일 선언

void main()
{
	int select; // 메뉴 선택
	Tree<char> tree; // 바이너리 트리 생성

	cout << "select(1:Inorder 2:Preorder 3:Postorder 4:NonrecInorder 5:Levelorder) : ";
	cin >> select; // select 값 입력

	if (select == 1)
		tree.Inorder();
	else if (select == 2)
		tree.Preorder(); 
	else if (select == 3)
		tree.Postorder();
	else if (select == 4)
		tree.NonrecInorder();
	else if (select == 5)
		tree.Levelorder();
	else
		cout << "Error !!";

	cout << endl;

	return;
}