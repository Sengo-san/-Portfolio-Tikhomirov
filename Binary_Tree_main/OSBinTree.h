#pragma once
#include "SBinTree.h"

class OSBinTree : public SBinTree
{
private:
	void CreateMatrix(int* p, int* q, int n, int** W, int** C, int** R);
	Node* OTree(int* d, int i, int j, int** R, Node * q);

public:
	OSBinTree() : SBinTree() {};
	
	OSBinTree(int* d, int* p, int* q, int n);//ключи, их частоты, частоты ловушек, размер 
	OSBinTree(const OSBinTree&);//Не переопределяется??
	OSBinTree& operator= (const OSBinTree&);//Не переопределяется??
	virtual ~OSBinTree() {};
	
};
