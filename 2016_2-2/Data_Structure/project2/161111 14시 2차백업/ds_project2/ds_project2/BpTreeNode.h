#ifndef _BpTreeNode_H_
#define _BpTreeNode_H_

#include "Year.h"

class BpTreeNode{
private:
	BpTreeNode* pParent;
	BpTreeNode* pMostLeftChild;

public:
	BpTreeNode(){
		pParent = NULL;
		pMostLeftChild = NULL;
	}

	void setMostLeftChild(BpTreeNode* pN)	{ pMostLeftChild = pN; }
	void setParent(BpTreeNode* pN)				{ pParent = pN; }
	
	BpTreeNode* getParent()						{ return pParent;	}
	BpTreeNode* getMostLeftChild()				{ return pMostLeftChild; }

	virtual map <double, BpTreeNode*>* getIndexMap() { return NULL; }
	virtual void insertIndexMap(double n, BpTreeNode* pN) {}
	virtual map< double, map<int, StudentData*> > *getDataMap() { return NULL; }
	virtual void insertDataMap(double avgGrade, map<int, StudentData*> m) {}
	virtual void deleteMap(double n) {}
	
	virtual void setNext(BpTreeNode* pN) {}
	virtual void setPrev(BpTreeNode* pN) {}
	virtual BpTreeNode* getNext() { return NULL; }
	virtual BpTreeNode* getPrev() { return NULL; }
};

#endif