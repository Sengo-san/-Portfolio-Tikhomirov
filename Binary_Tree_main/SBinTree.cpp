#include "SBinTree.h"



SBinTree::SBinTree(int n)		//n - количество ключей, ключи случайны
{
	if (n == 0) root = NULL;
	else 
	{
		root = new Node(rand() % 50);
		for (int i = 1; i < n; i++)	Add(rand() % 50, root);
	}
}

SBinTree::SBinTree(int* a, int n)
{
	if (n == 0) root = NULL;
	else
	{
		root = new Node(a[0]);
		for (int i = 1; i < n; i++)	Add(a[i], root);
	}
}

SBinTree::SBinTree(const SBinTree& T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
			copy(T.root->left, root, 0);
		copy(T.root->right, root, 1);
	}
}

void SBinTree::Add(int k, Node* p)
//добавление узла с ключом k в дерево с корнем p
{
	Node* q;
	if (k < p->key)
		if (p->left == NULL)
		{
			q = new Node(k);
			p->left = q;
			q->parent = p;
		}
		else Add(k, p->left);
	else if (p->right == NULL)
	{
		q = new Node(k);
		p->right = q;
		q->parent = p;
	}
	else Add(k, p->right);
}

void SBinTree::Del(Node* p)  		//удаление узла p
{
	if (p == NULL) return;

	if (p == root)
	{
		SBinTree::Delroot();
		return;
	}
	else
	{

		Node* q = p->parent;

		//удаление листа
		if (p->left == NULL && p->right == NULL)
		{
			if (q->left == p) q->left = NULL;
			else q->right = NULL;
			delete p;
			return;
		}

		//у p нет левой ветви
		if (p->left == NULL && p->right != NULL)
		{
			if (q->left == p) q->left = p->right;
			else q->right = p->right;
			p->right->parent = q;
			delete p;
			return;
		}

		//у p нет правой ветви
		if (p->left != NULL && p->right == NULL)
		{
			if (q->left == p) q->left = p->left;
			else q->right = p->left;
			p->left->parent = q;
			delete p;
			return;
		}

		//у p есть оба поддерева
		Node* t = p->left;
		if (t->right == NULL)
		{
			t->parent = q;
			if (q->left == p) q->left = t;
			else q->right = t;
			t->right = p->right;
			p->right->parent = t;
		}
		else {
			while (t->right != NULL) t = t->right;
			t->parent->right = t->left;
			if (t->left != NULL)
				t->left->parent = t->parent;

			t->left = p->left;
			t->right = p->right;
			p->left->parent = t;
			p->right->parent = t;

			t->parent = q;
			if (q->left == p) q->left = t;
			else q->right = t;
		
		}

		delete p;
		//root = t;
		return;
	}
}

void SBinTree::Delroot()
{
	Node* q = root;
	if (q->left == NULL && q->right == NULL)
		//у корня нет потомков, просто удаляем корень
	{
		delete q;
		root = NULL;
		return;
	}
	if (q->left != NULL && q->right == NULL)
		//нет правой ветки
	{
		root = q->left;
		q->parent = NULL;
		delete q;
		return;
	}
	if (q->left == NULL && q->right != NULL)
		//нет левой ветки
	{
		root = q->right;
		q->parent = NULL;
		delete q;
		return;

	}
	Node* t = q->left;
	if (q->left != NULL && q->right != NULL)
	{
		if (t->right == NULL)
		{
			t->right = q->right;
			q->right->parent = t;
			t->parent = NULL;
		}

		else 
		{
			
			while (t->right != NULL) t = t->right;
			t->parent->right = t->left; 

			if (t->left != NULL)
				t->left->parent = t->parent;
			
			t->left = q->left;
			t->right = q->right;
			q->left->parent = t;
			q->right->parent = t;

			t->parent = NULL;

		}

	}

	delete root;
	root = t;
	return;
}

Node* SBinTree::FindKey(int k, Node* p)
{
	

	while (p != NULL && p->key != k)
	{
		if (p->key < k) p = p->right;
		else p = p->left;
	}
	return p;
}

Node* SBinTree::FindMax(Node* p)

{
	while (p->right != NULL) p = p->right;

	return p;
}

Node* SBinTree::FindMin (Node* p)

{
	while (p->left != NULL) p = p->left;

	return p;
}