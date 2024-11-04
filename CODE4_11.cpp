#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef Node* Tree;

Node* makeNode (int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void chen(Tree &T, int data) {
    if(T == NULL)
    {
    	Node* newNode = makeNode(data);
    	T = newNode;
    	return;
	}
	if(data > T->data)
	{
		chen(T->right,data);
	}
	else
	{
		chen(T->left,data);
	}
}

void duyetNLR(Tree T)
{
	if(T == NULL)
		return;
	cout << T->data << ' ';
	duyetNLR(T->left);
	duyetNLR(T->right);
}


void duyetLNR(Tree T)
{
	if(T == NULL)
		return;
	duyetLNR(T->left);
	cout << T->data << ' ';
	duyetLNR(T->right);
}

void duyetLRN(Tree T)
{
	if(T == NULL)
		return;
	duyetLRN(T->left);
	duyetLRN(T->right);
	cout << T->data << ' ';
}


void createTree(const char * file_name, Tree &T)
{
	FILE* f = fopen(file_name, "r");
	T = NULL;
	int x;
	while(fscanf(f,"%d",&x) != EOF)
		chen(T, x);
	cout << "NLR: ";
	duyetNLR(T);
	cout << endl;
	cout << "LNR: ";
	duyetLNR(T);
	cout << endl;
	cout << "LRN: ";
	duyetLRN(T);
}


void duyetTheoMuc(Tree T, int muc)
{
	if(T == NULL || muc < 0)
		return;
	if(muc == 0)
	{
		cout << T->data << ' ';
		return;
	}
	duyetTheoMuc(T->left, muc--);
	duyetTheoMuc(T->right,muc--);
}

void duyetTheoPrototype(Tree T)
{
	queue <Tree> q;
	q.push(T);
	while(!q.empty())
	{
		Node* curent = q.front();
		cout << curent->data << ' ';
		q.pop();
		if(curent->left != NULL)
			q.push(curent->left);
		if(curent->right != NULL)
			q.push(curent->right);
	}
}


Node* timNode(Tree T, int x)
{
	if(T == NULL)	return NULL;
	while(T != NULL)
	{
		if(T->data == x)
			return T;
		if(x > T->data)
			T = T->right;
		else
			T = T->left;
	}
	return NULL;
}


int timBac(Node* node)
{
	if(node == NULL)
		return -1;
	int bac = 0;
	if(node->left != NULL)	bac++;
	if(node->right != NULL) bac++;
	return bac;
}

int timHang(Tree T, Node* node, int hang) {
    if (T == NULL || node == NULL) 
        return -1; 
    if (T == node)
        return hang; 
    int leftHang = timHang(T->left, node, hang + 1);
    if (leftHang != -1) {
        return leftHang;
    }
    return timHang(T->right, node, hang + 1); 
}

void timChanLonNhat(Tree T)
{
	int max = -1;
	queue <Tree> q;
	q.push(T);
	while(!q.empty())
	{
		Node* curent = q.front();
		q.pop();
		if(curent->data % 2 == 0)
			if(curent->data > max)
				max = curent->data;
		if(curent->left != NULL)	q.push(curent->left);
		if(curent->right != NULL) q.push(curent->right);	
	}
	Node* temp = timNode(T, max);
	if(temp != NULL)
	{
		int bac = timBac(temp);
		int level = timHang(T, temp, 0);
		cout << temp->data << ' ' << bac << ' ' << level << endl;
	}
	else
	{
		cout << "-1";
	}
}


void xuatDuongDi(Tree T)
{
	if(T == NULL)
		return;
	int max = INT_MIN;
	queue <Tree> q;
	q.push(T);
	while(!q.empty())
	{
		Node* curent = q.front();
		q.pop();
		if(curent->data % 2 == 0)
			if(curent->data > max)
				max = curent->data;
		if(curent->left != NULL)	q.push(curent->left);
		if(curent->right != NULL) q.push(curent->right);	
	}
	if(max != INT_MIN)
	{
		while(T != NULL)
		{
			if(max > T->data)
			{
				cout << T->data << " -> ";
				T = T->right;
			}
			else
				if(max < T->data)
					{
						cout << T->data << " -> ";
						T = T->left;
					}	
				else
				{
					cout << max ;
					return;
				}
		}
	}
	else
	{
		return;
	}
}
int main()
{
	char filename[] = "test.txt";
	Tree T;
	createTree(filename, T);
	cout << endl;
	xuatDuongDi(T);
}