/*------------------------------------------------------------------
Ma SV : 20105231
Ho va ten: Tran Thi Minh Huyen
Lop: DHKTPM16A
Bai thi thuc hanh mon CTDL&GT
------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
using namespace std;
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};
typedef node *tree;
// khoi tao cay
void khoiTaoCay(tree &root)
{
	root = NULL;
}
// ham them phan tu x vao cay nhi phan
void themNodeVaoCay(tree &root, int x)
{
	// neu cay rong
	if (root == NULL)
	{
		node *p = new node;
		p->data = x; // them dl x vao  data
		p->pLeft = NULL;
		p->pRight = NULL;
		root = p; // node p chinh la node goc
	}
	// cay ton tai phan tu
	else
	{
		// neu phan  tu them vao nho hon node goc -->them vao ben trai
		if (x < root->data)
		{
			themNodeVaoCay(root->pLeft, x); // duyet qua trai de them x
		}
		// neu phan  tu them vao lon hon node goc -->them vao ben phai
		else if (x > root->data)
		{
			themNodeVaoCay(root->pRight, x);
		}
	}
}
// nhap gia tri vao  cay
void themVaoCay(tree &t)
{
	int a[] = {46, 12, 26, 37, 68, 48, 64, 65, 82, 98};
	// srand(time(NULL));
	// for (int i = 0; i < 10; i++)
	// {

	// 	x = rand()%100;
	// 	themNodeVaoCay(t,x);
	// }
	for (int x:a)
		themNodeVaoCay(t,x);
}
void duyet_NLR(tree root)
{
	if (root != NULL)
	{
		printf("%d\t", root->data);
		duyet_NLR(root->pLeft);
		duyet_NLR(root->pRight);
	}
}
void duyet_LNR(tree root)
{
	if (root != NULL)
	{
		duyet_LNR(root->pLeft);
		printf("%d\t", root->data);
		duyet_LNR(root->pRight);
	}
}
void duyet_LRN(tree root)
{
	if (root != NULL)
	{
		duyet_LRN(root->pLeft);
		duyet_LRN(root->pRight);
		printf("%d\t", root->data);
	}
}
void duyet3(tree t)
{
	duyet_NLR(t);
	cout << '\n';
	duyet_LNR(t);
	cout << '\n';
	duyet_LRN(t);
}

void in_muc_k(tree t, int k, int m)
{
	if (t)
	{
		if (m == k)
			printf("\nnode thu %d la %d", k, t->data);
		else
		{
			m++;
			in_muc_k(t->pLeft, k, m);
			in_muc_k(t->pRight, k, m);
		}
	}
}
void in_ben_trai(tree t, int m)
{
	if (t)
	{
		in_ben_trai(t->pLeft, m);
		if (t->data < m)
		{
			printf("%d", t->data);
		}
		else
			return;
		in_ben_trai(t->pRight, m);
	}
}

void in_node_co_2_bac(tree t)
{
	if (t)
	{
		if (t->pLeft && t->pRight)
			printf("%d ", t->data);
		in_node_co_2_bac(t->pLeft);
		in_node_co_2_bac(t->pRight);
	}
}

int chieu_dai(tree t)
{
	if (t)
	{
		return 1 + chieu_dai(t->pLeft) + chieu_dai(t->pRight);
	}
}
node *timMax(tree t)
{
	if (t)
	{
		if (t->pRight)
			return timMax(t->pRight);
		else
			return t;
	}
}
int timMucMax(tree t)
{
	if (t)
	{
		if (t->pRight)
			return 1 + timMucMax(t->pRight);
		else
			return 0;
	}
	return -1;
}
int bac_min_tree(tree t)
{
	if (t)
	{
		if (t->pLeft==NULL)
			return t->pRight? 1:0;
		return bac_min_tree(t->pLeft);
	}
	else return -1;
}
int bac_max_tree(tree t)
{
	if (t)
	{
		if (t->pRight==NULL)
			return (t->pLeft)? 1:0;
		return bac_max_tree(t->pRight);
	}
	else return -1;
}
int main()
{
	tree t = NULL;
	themVaoCay(t);
	duyet3(t);
	cout << "\nMax: " << timMax(t)->data;
	cout << "\nMuc max: " << timMucMax(t);
	cout<<"\nBac node max: "<<bac_max_tree(t);
	cout<<"\nBac node min: "<<bac_min_tree(t);

	//	in_muc_k(t,3,0);
	//	in_ben_trai(t,t->data);
	//	in_node_co_2_bac(t);
	// 	printf("%d",chieu_dai(t));
}
