#include "BpTree.h"

BpTree::BpTree(ofstream* fout, int order){
	root = NULL;
	this->order = 3;
	this->fout = fout;
}

BpTree::~BpTree()
{
	//BpTreeNode* pCur = root;
	// PostOrder.

}

void BpTree::Insert(StudentData* pStu){
	double key = pStu->getAvgGrade();	// key = avgGrade
	map<int, StudentData*> value;			// value = map< id, student data* >
	value.insert(make_pair(pStu->getStudentID(), pStu));

	if(root == NULL){ // empty B+ tree
		BpTreeNode* pDataNode = new BpTreeDataNode;	// make new data node		
		pDataNode->insertDataMap(key, value);	// insert grade data
		root = pDataNode;
		return;
	}
	
	// key == AvgGrade
	BpTreeNode* pDataNode = searchDataNode(key);	// seach data node with key

	if (pDataNode->getDataMap()->find(key) != pDataNode->getDataMap()->end()) // exist same key
		pDataNode->getDataMap()->find(key)->second.insert(make_pair(pStu->getStudentID(), pStu)); // insert student information
	else // new key
	{
		pDataNode->insertDataMap(key, value); // insert
		if (exceedDataNode(pDataNode) == true) // if it need split?
			splitDataNode(pDataNode);
	}
	return;
}

BpTreeNode* BpTree::searchDataNode(double n) {
	BpTreeNode* pCur = root;
	map<double, BpTreeNode*>::iterator itIndex;

	/* Search DataNode that suitable to insert the node that have key n */
	while (pCur->getMostLeftChild() != NULL) { // pCur is not DataNode, repeat
		itIndex = pCur->getIndexMap()->begin(); // itIndex point begin element of pCur's Map

		if (n < itIndex->first) {
			pCur = pCur->getMostLeftChild();
		}
		else { // n >= itIndex->first
			while (true) {
				itIndex++; // itIndex = itIndex's next
				if (itIndex == pCur->getIndexMap()->end() || n < itIndex->first) { // end or find
					itIndex--; // final
					pCur = itIndex->second; // pCur = IndexNode's DataNode
					break;
				}
			}
		}
	}

	return pCur;
}

void BpTree::splitDataNode(BpTreeNode* pDataNode){
	int splitPosition_data = ceil((order-1)/2.0) + 1;

	/* Split */
	BpTreeNode* pNewDataNode = new BpTreeDataNode;	// make new data node
	map <double, map<int, StudentData*> >::iterator itData; // DataMap in DataNode

	while(1) // insert data to new node
	{
		itData = pDataNode->getDataMap()->begin();
		for (int i = 1; i < splitPosition_data; i++)
			itData++; // itData = SplitPoint

		if (itData == pDataNode->getDataMap()->end()) // end of split
			break;

		pNewDataNode->insertDataMap(itData->first, itData->second); // insert
		pDataNode->getDataMap()->erase(itData->first); // erase at pDataNode
	}
	
	/* set Next */
	pNewDataNode->setPrev(pDataNode);
	pNewDataNode->setNext(pDataNode->getNext());
	if(pDataNode->getNext()!=NULL) // if getNext is not NULL
		pDataNode->getNext()->setPrev(pNewDataNode); // set Next Node's Prev
	pDataNode->setNext(pNewDataNode);

	/* classify by case */
	if (pDataNode->getParent() == NULL) // First DataNode Split
	{
		BpTreeNode* pNewIndexNode = new BpTreeIndexNode;	// make new index node
		pNewIndexNode->insertIndexMap(pNewDataNode->getDataMap()->begin()->first, pNewDataNode); // insert index to new node
		pNewIndexNode->setMostLeftChild(pDataNode); // set MLC

		// set Parent
		pDataNode->setParent(pNewIndexNode);
		pNewDataNode->setParent(pNewIndexNode);

		root = pNewIndexNode; // set root
	}
	else
	{
		pDataNode->getParent()->insertIndexMap(pNewDataNode->getDataMap()->begin()->first, pNewDataNode); // insert new indexmap to ParentNode
		pNewDataNode->setParent(pDataNode->getParent());// set Parent

		if (exceedIndexNode(pDataNode->getParent()) == true) // check the parent need split or not
			splitIndexNode(pDataNode->getParent());
	}
}

void BpTree::splitIndexNode(BpTreeNode* pIndexNode){
	int splitPosition_index = ceil(order/2.0);

	/* Split */
	BpTreeNode* pNewIndex = new BpTreeIndexNode;	// make new index node
	map <double, BpTreeNode*>::iterator pSplit;
	map <double, BpTreeNode*>::iterator itWork;
	double newParent_key;

	pSplit = pIndexNode->getIndexMap()->begin();
	for (int i = 1; i < splitPosition_index; i++)
		pSplit++; // SplitPoint

	while (1) // set NewIndex Node
	{
		itWork = pIndexNode->getIndexMap()->end();
		itWork--;

		if (itWork == pSplit) // check the split
		{
			newParent_key=pSplit->first;
			pNewIndex->setMostLeftChild(pSplit->second); // set MLC of New index
			pSplit->second->setParent(pNewIndex);
			pIndexNode->getIndexMap()->erase(pSplit->first); // erase from pIndexNode map
			break;
		}

		pNewIndex->insertIndexMap(itWork->first, itWork->second); // insert to NewIndexNode
		itWork->second->setParent(pNewIndex); // set Parent
		pIndexNode->getIndexMap()->erase(itWork->first); // erase from pIndexNode map
	}

	

	if (pIndexNode->getParent() == NULL) // First IndexNode Split
	{
		BpTreeNode* pNewParent = new BpTreeIndexNode;	// make new parent index node
		pNewParent->setMostLeftChild(pIndexNode); // set MLC of NewParent
		pNewParent->insertIndexMap(newParent_key, pNewIndex); // set IndexMap of NewParent

		// set Parent
		pNewIndex->setParent(pNewParent);
		pIndexNode->setParent(pNewParent);

		root = pNewParent;
	}
	else
	{
		pIndexNode->getParent()->insertIndexMap(newParent_key, pNewIndex); // insert new indexmap to ParentNode
		pIndexNode->getParent()->setMostLeftChild(pIndexNode); // set MLC
		pNewIndex->setParent(pIndexNode->getParent()); // set Parent

		if (exceedIndexNode(pIndexNode->getParent()) == true) // check the parent need split or not
			splitIndexNode(pIndexNode->getParent());
	}

	
}

bool BpTree::exceedDataNode(BpTreeNode* pDataNode){
	map <double, map<int, StudentData*> > *m = pDataNode->getDataMap();

	if(m->size() > order-1)		return true; // need split
	else								return false;
}

bool BpTree::exceedIndexNode(BpTreeNode* pIndexNode){
	map <double, BpTreeNode*>* m = pIndexNode->getIndexMap();
	
	if(m->size() > order-1)		return true; // need split
	else								return false;
}

bool BpTree::Print(){
	if (root == NULL)
		return false;

	map<int, StudentData*>::iterator itStu; // Student information
	map <double, map<int, StudentData*> >::iterator itData; // DataMap in DataNode

	BpTreeNode* pCur = root;
	*fout << "======== PRINT =======" << endl;

	while (pCur->getMostLeftChild() != NULL)
		pCur = pCur->getMostLeftChild();
	// pCur = Smallest DataNode

	while (pCur->getNext() != NULL)
		pCur = pCur->getNext();
	// pCur = biggest DataNode

	while (pCur != NULL) // node
	{
		itData = pCur->getDataMap()->end();
		itData--;

		while (1) // datamap
		{
			itStu = itData->second.begin();
			
			while (1) // print all student information from DataMap in DataNode
			{
				if (itStu == itData->second.end())
					break;

				printStudentInfo(itStu->second);

				itStu++;
			}

			/* Check printed all inform or not */
			if (itData == pCur->getDataMap()->begin())
				break;
			else if (itData-- == pCur->getDataMap()->begin())
			{
				itStu = itData->second.begin();
				printStudentInfo(itStu->second);
				break;
			}
		} // end of datamap
		
		pCur = pCur->getPrev();
	} // end of node

	*fout << "=======================" << endl;
	return true;
}

bool BpTree::Search(double a, double b, int year){
	BpTreeNode* pSearchNode = searchDataNode(b);	// seach data node with b

	map<int, StudentData*>::iterator itStu; // Student information
	map <double, map<int, StudentData*> >::iterator itData; // DataMap in DataNode

	itData=pSearchNode->getDataMap()->end();
	itData--;
	while (1)
	{
		if (itData->first <= b)
			break;
		else
			itData--;
	} // itData is biggest DataMap.

	*fout << "======== SEARCH =======" << endl;
	*fout << "SEARCH_BP " << a << " " << b << " " << year << endl;
	/*print First Node*/
	while (1)
	{
		itStu = itData->second.begin();
		while (1)
		{
			if (itStu == itData->second.end())
				break;

			if (itStu->second->getYear() == year)
				*fout << itStu->second->getStudentID() << " " << itStu->second->getName() << " " << itStu->second->getYear() << " " << itStu->second->getAvgGrade() << endl;

			itStu++;
		}

		/* Check printed all inform or not */
		if (itData == pSearchNode->getDataMap()->begin())
			break;
		else if (itData-- == pSearchNode->getDataMap()->begin())
		{
			itStu = itData->second.begin();
			*fout << itStu->second->getStudentID() << " " << itStu->second->getName() << " " << itStu->second->getYear() << " " << itStu->second->getAvgGrade() << endl;
			break;
		}
	}
	pSearchNode = pSearchNode->getPrev();
	
	/*print*/
	while (pSearchNode != NULL) // Print from biggest to smallest
	{
		itData = pSearchNode->getDataMap()->end();
		itData--;

		while (1)
		{
			itStu = itData->second.begin();
			while (1)
			{
				if (itStu == itData->second.end())
					break;

				if(itStu->second->getYear() == year)
					*fout << itStu->second->getStudentID() << " " << itStu->second->getName() << " " << itStu->second->getYear() << " " << itStu->second->getAvgGrade() << endl;

				itStu++;
			}
			/* Check printed all inform or not */
			if (itData == pSearchNode->getDataMap()->begin())
			{
				if (itData->first < a)
				{
					*fout << "=======================" << endl;
					return true;
				}
				else
					break;
			}
			else if (itData-- == pSearchNode->getDataMap()->begin())
			{
				itStu = itData->second.begin();
				*fout << itStu->second->getStudentID() << " " << itStu->second->getName() << " " << itStu->second->getYear() << " " << itStu->second->getAvgGrade() << endl;

				if (itData->first < a)
				{
					*fout << "=======================" << endl;
					return true;
				}
				else
					break;
			}
		}
		pSearchNode = pSearchNode->getPrev();
	}
	*fout << "=======================" << endl;
	return true;
}

void BpTree::printStudentInfo(StudentData* pStu){
	*fout << pStu->getStudentID() << " " << pStu->getName() << " " << pStu->getYear() << " " << pStu->getAvgGrade() << endl;
	pStu->printGrade();
	*fout << endl;
}