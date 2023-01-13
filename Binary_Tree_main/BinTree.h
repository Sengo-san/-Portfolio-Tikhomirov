#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <iostream>

#include <fstream>

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include <queue>

class Node
{
	int key;//поле информации
	Node* left, *right, *parent;

public:
	Node(int k =0, Node*L=NULL, Node *R=NULL, Node*P=NULL) //key, L, R, P
	{
		key = k;
		left = L;
		right = R;
		parent = P;
	}
	int getkey() { if (this != NULL) return key; else return (-1); }
	
	friend class BinTree;
	friend class SBinTree;
	friend class OSBinTree;

};

class BinTree
{
	//friend class SBinTree;
protected:
	Node* root;
	Node* tree (int n, Node* p);	//строит идеально сбалансированное дерево с n вершинами, p-предок
	Node* TreeM (int n, Node* p, int* a, int &i); //строит идеально сбалансированное дерево по массиву, p-предок
	void copy (Node* q, Node* p, int f); //создает копию дерева с корнем q, p-корень нового дерева		
										//(f==0 если присоеденить копируемое дерево левым потомком для p, f==1 - правым)
public:
	Node* GetRoot() { return root; }
	BinTree() { root = NULL; }
	BinTree (int n);// построение по кол-ву ключей n, ключи генерируются случайно 
	BinTree(int* a, int n);//построение по массиву ключей a[], n - кол-во ключей
	BinTree (const BinTree&);
	
	BinTree& operator= (const BinTree&); 
	
	virtual ~BinTree();
	virtual void Add (int k, Node* p);//добавление узла с ключом k  в дерево с корнем p (НЕ к p!)
	virtual void Del(Node* p); //удалене узла p
	virtual void Delroot();

	void TreeTraversall_LCR (Node *p); //обход дерева с корнем p в глубину лево-корень-право
	void TreeTraversall_LRC (Node* p);
	void TreeTraversall_RLC(Node* p);
	void WidthTraversall(Node* p); //обход дерева с корнем p в ширину (понадобится очередь, есть в бсш: push, pop, front, back, empty), либо очередь на массиве

	virtual Node* FindKey(int k, Node* p);//поиск узла с ключом k среди потомков p
	virtual Node* FindMax (Node* p);
	virtual Node* FindMin (Node* p);

	int FindHigh (Node* p);//поиск высоты дерева с корнем p
	int Count(Node* p, int& i);//считает число узлов в дереве с корнем p

	void clear();//уничтожение дерева, кроме  корня

	void Print(Node* p, int k, int c);//k - отступ от левой границы консоли
};
