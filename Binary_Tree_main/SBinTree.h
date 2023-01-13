#pragma once
#include "BinTree.h"

class SBinTree : public BinTree
{
public:
	SBinTree() : BinTree() {};
	SBinTree(int n);	//n - количество ключей, ключи случайны
	SBinTree(int* a, int n);	//a - массив ключей, n - количество ключей

	SBinTree(const SBinTree&);
/*не переопределяется?*///	SBinTree& operator= (const SBinTree&);
	virtual ~SBinTree() {};	

	virtual void Add(int k, Node* p) override;
	//добавление узла с ключом k в дерево с корнем p
	virtual void Del(Node* p) override; 		//удаление узла p
	virtual void Delroot() override; 			//удаление корня

	virtual Node* FindKey(int k, Node* p) override;
	virtual Node* FindMax(Node* p) override;
	virtual Node* FindMin(Node* p) override;

};


