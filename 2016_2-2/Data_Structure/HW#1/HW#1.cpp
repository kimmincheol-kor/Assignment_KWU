#include <iostream>
using namespace std;

#include "class.h" // ������� ����

void main()
{
	int select; // �޴� ����
	Tree<char> tree; // ���̳ʸ� Ʈ�� ����

	cout << "select(1:Inorder 2:Preorder 3:Postorder 4:NonrecInorder 5:Levelorder) : ";
	cin >> select; // select �� �Է�

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