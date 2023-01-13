
#include "BinTree.h";
using namespace std;

//KONSTRUCTORS

Node* BinTree::tree(int n, Node* p)//построение идеально сбалансированного дерева случайных ключей
		//с n вершинами, p - предок вершины дерева
{

	if (n == 0) { p->left = NULL, p->right = NULL; return NULL; }

	Node* q = new Node ((rand() % 30)+10);
	//cout << n<< " ";
	int nl = (n - 1) / 2;
	int	nr= n - 1 - nl;			//количество вершин слева и справа
	
	q->left = tree(nl, q);
	q->right = tree(nr, q);
	q->parent = p;
	return q;
}

BinTree::BinTree(int n)//конструктор бинарного дерева (n случ. ключей)
{
	root = tree(n, NULL);
}


Node* BinTree::TreeM(int n, Node* p, int* a, int& i)
{
	
	if (n == 0) { p->left = NULL, p->right = NULL; return NULL; }

	Node* q = new Node(a[i]);
	int nl = (n - 1) / 2;
	int	nr = n - 1 - nl;			//количество вершин слева и справа
	i = i + 1;
	q->left = TreeM(nl, q, a, i);
	q->right = TreeM(nr, q, a, i);
	q->parent = p;

	return q;
}


BinTree::BinTree(int* a, int n)//построение по массиву ключей a[], n - кол-во ключей
	//потребуется еще одна всп. ф-я, сам напишешь (конструкторы не реализуют рекурсию)
{
	int nul = 0;
	root = TreeM(n, NULL, a, nul);
}

void BinTree::copy(Node* q,  Node*p, int f)
//копирование дерева с корнем q, p - узел, к которому присоединяется копия
//f=0 - копируемое дерево будет левым потомком для p;
//f=1 - копируемое дерево будет правым потомком для p.

{
	if (q == NULL) return;
	
	Node* t = new Node(q->key);

	t->parent = p;
	if (f == 0) p->left = t;
	else p->right = t;

	copy(q->left, t, 0);
	copy(q->right, t, 1 );
}

BinTree::BinTree (const BinTree &t)
{
	if (t.root == NULL) root = NULL;
	else 
	{
		root = new Node(t.root->key);
		copy(t.root->left, root, 0);
		copy(t.root->right, root, 1);
	}
}

BinTree& BinTree::operator= (const BinTree& T)
{
	if (this != &T)
	{
		clear();
		delete(root);
		if (T.root == NULL) root = NULL;
		else
		{
			root = new Node(T.root->key);
			copy(T.root->left, root, 0);
			copy(T.root->right, root, 1);
		}
	}

	return *this;
}



//STUFF

void BinTree::Print(Node* p, int k, int c)
{
	if (p == NULL) return;

	Print(p->right, k + c, c);

	for (int i = 0; i < k; i++)
		cout << ' ';
	cout << p->key << endl;
	Print(p->left, k + c, c);
}

void BinTree::Add(int k, Node* p)
{
	if (p->left == NULL)
	{
		Node* q = new Node(k);//q->left = NULL; q->right = NULL;
		p->left = q;
		q->parent = p;
		
		return;
	}
	if (p->right == NULL)
	{
		Node* q = new Node(k);//	q->left = NULL; q->right = NULL;
		p->right = q;
		q->parent = p;
	
		return;
	}

	if (rand() % 2) Add(k, p->left);
	else Add(k, p->right);
	
}
//TRAVERSALS

void BinTree::TreeTraversall_LCR(Node* p)
//обход дерева с корнем p, в глубину по принципу
//лево-корень-право, ключи выводятся на консоль

{
	if (p == NULL) return;
	TreeTraversall_LCR(p->left);
	cout << p->key << ' ';
	TreeTraversall_LCR(p->right);
}

void BinTree::TreeTraversall_LRC(Node* p)
{
	if (p == NULL) return;
	TreeTraversall_LRC(p->left);
	TreeTraversall_LRC(p->right);
	cout << p->key << ' ';

}

void BinTree::TreeTraversall_RLC(Node* p)
{
	if (p == NULL) return;
	TreeTraversall_LRC(p->right);
	TreeTraversall_LRC(p->left);
	cout << p->key << ' ';

}

Node* BinTree::FindKey(int k, Node* p)

{
	if (p == NULL) return NULL;
	
		if (p->key == k) return p;
		if (FindKey(k, p->left) != NULL) return FindKey(k, p->left);
		return FindKey(k, p->right);

}

Node* BinTree::FindMax(Node* p)
{
	if (p == NULL) return NULL;
//	if (p->right == NULL && p->left == NULL) return p;

	Node* lmax = NULL; Node* rmax = NULL; Node* max=p;

	/*if (p->right != NULL)*/ rmax = FindMax(p->right);
/*	if (p->left != NULL) */ lmax = FindMax(p->left);

	if (lmax != NULL &&  lmax->key > max->key)
		 max = lmax;

	if (rmax != NULL && rmax->key > max->key)
		 max = rmax;

	return max;	
}

Node* BinTree::FindMin(Node* p)
{

	if (p == NULL) return NULL;
	//	if (p->right == NULL && p->left == NULL) return p;

	Node* lmin = NULL; Node* rmin = NULL; Node* max = p;

	/*if (p->right != NULL)*/ rmin = FindMin(p->right);
	/*	if (p->left != NULL) */ lmin = FindMin(p->left);

	if (lmin != NULL && lmin->key < max->key)
		max = lmin;

	if (rmin != NULL && rmin->key < max->key)
		max = rmin;

	return max;
}

int BinTree::FindHigh(Node* p)
{
	if (p == NULL) return 0;
	
	return max(FindHigh(p->left), FindHigh(p->right)) + 1;

}

void BinTree::WidthTraversall(Node* p)
{
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* h = q.front(); q.pop();
		cout << h->key << " ";
		if (h->left != NULL) q.push(h->left);
		if (h->right != NULL) q.push(h->right);
	}

}

int BinTree::Count(Node* p, int &i)
{
	if (p == NULL) return i;
	i = i + 1;
	Count(p->left, i);
	Count(p->right, i);

}
//DESTRUCTOR AND HIS FRIENDS

void BinTree::Del(Node* p) 		//удаление узла p
{
	if (p == root)
	{
		Delroot();
		return;
	}

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
	Node* t = p;
	while (t->left != NULL) t = t->left;

	//вырезаем t из дерева
	if (t->right == NULL)	t->parent->left = NULL;
	else
	{
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	//заменяем p узлом t
	t->left = p->left;
	t->right = p->right;
	t->parent = q;

	if (q->left == p) q->left = t;
	else q->right = t;

	if (p->left != NULL)
		p->left->parent = t;

	p->right->parent = t;
	delete p;
	return;
}


void BinTree::Delroot()
{
	//удаление листа
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		root = NULL;
		return;
	}
	//у p нет левой ветви
	if (root->left == NULL && root->right != NULL)
	{
		Node* t = root;
		root->right = root;
		root->parent = NULL;

		delete t;
		return;
	}
	//у p нет правой ветви
	if (root->left != NULL && root->right == NULL)
	{
		Node* t = root;
		root->left = root;
		root->parent = NULL;

		delete t;
		return;
	}

	//у p есть оба поддерева
	Node* t = root;


	while (t->left != NULL) t = t->left;

	//вырезаем t из дерева
	if (t->right == NULL)	t->parent->left = NULL;
	else
	{
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	//заменяем p узлом t


	t->left = root->left;
	t->right = root->right;
	t->parent = NULL;


	if (t->left != NULL) 
		t->left->parent = t;
	t->right->parent = t;

	delete root;
	root = t;

	return;
}

void BinTree::clear()
{
	if (root != NULL)
	{
		while (root->left != NULL)
			Del(root->left);
		while (root->right != NULL)
			Del(root->right);
	}
	
}

BinTree::~BinTree()
{
	clear();
	Delroot();
}
