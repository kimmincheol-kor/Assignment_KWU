#include "AVLTree.h"

AVLTree::AVLTree(ofstream* fout){
	root=NULL;
	make_heap(vHeap.begin(), vHeap.end(), compare); // all element of vHeap insert to heap
	this->fout = fout;
}

AVLTree::~AVLTree(){
	//stack<AVLNode*> s;

	//AVLNode * pCur = root;
	//s.push(pCur);

	//AVLNode * pPrev = NULL;

	//// delete by postorder
	//while (s.empty() != true)
	//{
	//	pCur = s.top();

	//	if (pPrev == NULL || pPrev->getLeft() == pCur || pPrev->getRight() == pCur) { // // pCur is child of pPrev OR First time(pPrev==NULL)
	//		if (pCur->getLeft())
	//			s.push(pCur->getLeft());
	//		else if (pCur->getRight())
	//			s.push(pCur->getRight());
	//		else { // no child
	//			s.pop();

	//			delete pCur->getSD();
	//			delete pCur;
	//		}
	//	}
	//	if (pCur->getLeft() == pPrev&&pCur->getLeft() != NULL) { // pPrev is Leftchild of pCur
	//		if (pCur->getRight())
	//			s.push(pCur->getRight());
	//		else {
	//			s.pop();

	//			delete pCur->getSD();
	//			delete pCur;
	//		}
	//	}
	//	if (pCur->getRight() == pPrev && pCur->getRight() != NULL) { // pPrev is Rightchild of pCur
	//		s.pop();

	//		delete pCur->getSD();
	//		delete pCur;
	//	}
	//	pPrev = pCur;
	//}
}

bool AVLTree::Insert(StudentData* pStu){
	AVLNode* pNew = new AVLNode;
	pNew->setSD(pStu);	
	char	*pName = pStu->getName();
	int		d = 0;

	if(root == NULL){
		root = pNew;
		return true;
	}

	AVLNode *a = root; // recent node that have bf
	AVLNode *pa = NULL; // parent of a
	AVLNode *p = root; // pWork
	AVLNode *pp = NULL; // parent of p
	AVLNode *subroot = NULL;
	
	while (p != NULL)
	{
		if (p->getBF() != 0) //  recent unbalance node = a
		{
			a = p;
			pa = pp;
		}

		// find position of new node
		if (strcmp(pName, p->getSD()->getName()) < 0)
		{
			pp = p;
			p = p->getLeft();
		}
		else if (strcmp(pName, p->getSD()->getName()) > 0)
		{
			pp = p;
			p = p->getRight();
		}
		else // already in tree
			return false;
	} // end of while

	/* insert new node to tree */
	if (strcmp(pName, pp->getSD()->getName()) < 0)
		pp->setLeft(pNew);
	else
		pp->setRight(pNew);

	AVLNode *b; // child of a
	AVLNode *c; // child of b

	/* find direction of new node from 'a' node */
	if (strcmp(pName, a->getSD()->getName()) > 0) // right
	{
		b = a->getRight(); p = a->getRight();
		d = -1;
	}
	else // left
	{
		b = a->getLeft(); p = a->getLeft();
		d = 1;
	}

	while (p != pNew) // set Balance Factor
	{
		if (strcmp(pName, p->getSD()->getName()) > 0)
		{
			p->setBF(-1);
			p = p->getRight();
		}
		else
		{
			p->setBF(1);
			p = p->getLeft();
		}
	}

	/* check the balance  */
	if (a->getBF() == 0 || a->getBF() + d == 0)
	{
		a->setBF(a->getBF()+d);
		return true;
	}

	/* Rotation */
	if (d == 1) // left
	{
		if (b->getBF() == 1) // rotation LL
		{
			a->setLeft(b->getRight());
			b->setRight(a);
			a->setBF(0);
			b->setBF(0);
			subroot = b;
		} // end of LL
		else // rotation LR
		{
			c = b->getRight();
			b->setRight(c->getLeft());
			a->setLeft(c->getRight());
			c->setLeft(b);
			c->setRight(a);
			switch (c->getBF())
			{
			case 0:
				b->setBF(0);
				a->setBF(0);
				break;
			case 1:
				a->setBF(-1);
				b->setBF(0);
				break;
			case -1:
				a->setBF(0);
				b->setBF(1);
				break;
			} // end of switch
			c->setBF(0);
			subroot = c;
		} // end of LR
	}
	else
	{
		if (b->getBF() == -1) // rotation RR
		{
			a->setRight(b->getLeft());
			b->setLeft(a);
			a->setBF(0);
			b->setBF(0);
			subroot = b;
		} // end of RR
		else
		{
			c = b->getLeft();
			b->setLeft(c->getRight());
			a->setRight(c->getLeft());
			c->setRight(b);
			c->setLeft(a);
			switch (c->getBF())
			{
			case 0:
				b->setBF(0);
				a->setBF(0);
				break;
			case 1:
				a->setBF(0);
				b->setBF(-1);
				break;
			case -1:
				a->setBF(1);
				b->setBF(0);
				break;
			} // end of switch
			c->setBF(0);
			subroot = c;
		} // end of RL
	} // end of rotation

	if (pa == NULL)
		root = subroot;
	else if (a == pa->getLeft())
		pa->setLeft(subroot);
	else
		pa->setRight(subroot);

	return true;
} // end of insert

bool AVLTree::Print(){
	if (root == NULL)
		return false;

	stack<AVLNode*> s;	 // use at inorder Print

	AVLNode * pCur = root;
	*fout << "======== PRINT =======" << endl;

	// inorder
	while (1) {
		while (pCur) { // if pCur is not NULL
			s.push(pCur); // pCur into stack s.
			pCur = pCur->getLeft(); // pCur move to pCur's left child.
		}
		if (s.empty() == true)
			break; // if stack is empty, break

		pCur = s.top(); // pCur is Top of stack s
		s.pop(); // Pop node that in stack s

		printStudentInfo(pCur->getSD());

		pCur = pCur->getRight(); // pCur move to pCur's right child.
	}
	*fout << "=======================" << endl;
	return true;
}

bool AVLTree::Search(char* name){
	if (root == NULL)
		return false;

	AVLNode * pCur = root;

	while (strcmp(pCur->getSD()->getName(), name) != 0) // if not same,
	{
		if (strcmp(pCur->getSD()->getName(), name) < 0) // if pCur's name < find name
			pCur = pCur->getRight();
		else // if pCur's name > find name
			pCur = pCur->getLeft();

		if (pCur == NULL) // fail to find
			return false;
	}

	// pCur is Seaching node
	StudentData* pSD = pCur->getSD();
	vHeap.push_back( make_pair( make_pair(pSD->getAvgGrade(), pSD->getStudentID()), pSD)); // insert new element to vHeap's last position
	push_heap(vHeap.begin(), vHeap.end(), compare); // insert last element of vHeap to heap

	*fout << "======== SEARCH =======" << endl;
	*fout << "SEARCH_AVL " << name << endl;
	*fout << pSD->getStudentID() << " " << pSD->getName() << " " << pSD->getYear() << " " << pSD->getAvgGrade() << endl;
	*fout << "=======================" << endl;
	return true;
}

bool AVLTree::Rank(){
	if(vHeap.empty())		return false; // nothing in heap

	StudentData* pStu;
	*fout << "======== RANK =======" << endl;
	
	while(!vHeap.empty()){ // if heap isn't empty,
		pStu = vHeap.front().second; // pStu point front student inform of heap
		pop_heap(vHeap.begin(), vHeap.end(), compare); // top element of heap move to vHeap's last
		vHeap.pop_back(); // delete vHeap's last element
		printStudentInfo(pStu); // print
	}
	*fout << "=======================" << endl;
	return true;
}

void AVLTree::printStudentInfo(StudentData* pStu){
	*fout << pStu->getStudentID() << " " << pStu->getName() << " " << pStu->getYear() << " " << pStu->getAvgGrade() << endl;
	pStu->printGrade();
	*fout << endl;
}