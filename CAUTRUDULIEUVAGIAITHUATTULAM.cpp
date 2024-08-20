#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
int a[1000], n;

void nhap()
{
	cout << "Nhap n:"; cin >> n;
	for (int i  = 0; i < n;i++)
	{
		cin >> a[i];
	}
}
void xuat()
{
	cout << "Phan tu cua mang la:";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << el;
}

// Tim kiem nhi phan
bool binary_search(int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == x)	return true;
		else
			if (a[m] > x)
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
	}
	return false;
} 
// Tim kiem tuan tu
bool timkiemtuantu(int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return true;
	}
	return false;
}
// Tim kiem tuan tu co linh canh
bool timkiemtuantu2(int x)
{
	a[n] = x;
	int i = 0;
	while(a[i] != x)
	{
		++i;
	}
	if (i < n)	return true;
	return false;
}
// Nhap ngau nhien man N phan tu
void nhapRan()
{
	srand(time(NULL));
	cout << "Nhap n:"; cin >> n;
	for (int i =0; i < n; i++)
	{
		a[i] = -99 + rand() % (99 + 1 + 99);
 	}
 	cout << "Da nhap xong!!!\n";
}
// Selection_Sort
void Selection_Sort()
{
	for (int i = 0; i < n - 1; i ++)
	{
		int minPos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minPos])
				minPos = j;
		}
		swap(a[i], a[minPos]);
		cout << "Buoc " << i + 1 << ":";
		xuat();
	}
}
// Interchange_Sort
void Interchange_Sort()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i],a[j]);
			}
		}
		cout << "Buoc " << i + 1 << ':';
		xuat();
	}
}
// Bubble_Sort
void Bubble_Sort()
{
	for (int i = 0; i < n - 1;i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
		cout << "Buoc " << i + 1 << ':';
		xuat();
	}
}
// Insertion_Sort
void Insertion_Sort()
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i], pos = i - 1;
		while(pos >= 0 && x < a[pos])
		{
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = x;
		cout << "Buoc " << i + 1 << ':';
		xuat();
	}
}
// quicksort phan hoach LOMUTO
int partition1(int a[], int l, int r)
{
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			++i;
			swap(a[i],a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}
void quicksort1(int a[], int l, int r)
{
	if (l >= r)	return;
	int p = partition1(a, l, r);
	quicksort1(a, l, p - 1);
	quicksort1(a, p + 1, r);
}
// quicksort hoare
int partition2(int a[], int l, int r)
{
	int i = l - 1, j = r + 1;
	while(1)
	{
		do{
			++i;
		}while(a[i] < a[l]);
		do{
			--j;
		}while(a[j] > a[l]);
		if (i < j)
		{
			swap(a[i], a[j]);
		}
		else
		{
			return j;
		}
	}
}
void quicksort2(int a[], int l, int r)
{
	if (l >= r) return;
	int p = partition2(a, l, r);
	quicksort2(a,l,p);
	quicksort2(a,p + 1, r);
}
// Sap xep tron ( merge sort )
void merge(int a[], int l, int m, int r)
{
	vector<int> u(a + l, a + m + 1);
	vector<int> v(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < u.size() && j < v.size())
	{
		if (u[i] < v[j])
		{
			a[l] = u[i];
			++i;++l;
		}
		else
		{
			a[l] = v[j];
			++j;++l;
		}
	}
	while(i < u.size())
	{
		a[l] = u[i];
		++i;++l;
	}
	while(j < v.size())
	{
		a[l] = v[j];
		++j;++l;
	}
}
void mergesort(int a[], int l, int r)
{
	if (l >= r)	return;
	int m = (l + r) / 2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);
}

void heapify(int a[], int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[l] > a[largest])
	{
		largest = l;
	}
	if (r < n && a[r] > a[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n)
{
	// Set max heap
	for (int i = n / 2 + 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	// Thuc hien sort
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
// Radix sort
//
struct node 
{
	int key;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node* makeNode(int x)
{
	node* newNode = new node();
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void addNode(node **root, int x)
{
	if (*root == NULL)
	{
		node *newNode = makeNode(x);
		*root = newNode;
		return;
	}
	if (x > (*root)->key)
	{
		addNode(&(*root)->right, x);
	}
	else
	{
		addNode(&(*root)->left, x);
	}
}
// Duyet NLR
void DuyetNLR(node *root)
{
	if (root == NULL)	return;
	cout << root->key << ' ';
	DuyetNLR(root->left);
	DuyetNLR(root->right);
}
// Duyet NLR khong de quy
void DuyetNLR2(node *root)
{
	if (root == NULL)
	{
		cout << "Cay rong !!" << endl;
		return;
	}
	
	stack <node*> st;
	st.push(root);
	while(!st.empty())
	{
		node *hientai = st.top();
		cout << hientai->key << ' ';
		st.pop();
		if (hientai->right != NULL)
		{
			st.push(hientai->right);
		}
		if (hientai->left != NULL)
		{
			st.push(hientai->left);
		}
	}
}
// Duyet sau
void DuyetLRN(node *root)
{
	if (root == NULL)	return;
	DuyetLRN(root->left);
	DuyetLRN(root->right);
	cout << root->key << ' ';
}
// Duyet sau khong de quy
void DuyetLRN2(node *root)
{
	if (root == NULL)
	{
		cout << "Cay rong !!" << endl;
		return;
	}
	
	stack <node*> st;
	stack <node*> st2;
	top:
	while(root != NULL)
	{
		st.push(root);
		root = root->left;
	}
	while(!st.empty())
	{
		if (st.top() == st2.top() && !st2.empty())
		{
			cout << st.top()->key << ' ';
			st.pop();
			st2.pop();
		}
		else
		{
			if (st.top()->right != NULL)
			{
				st2.push(st.top());
				root = st.top()->right;
				goto top;
			}
			else
			{
				cout << st.top()->key << ' ';
				st.pop();
			}
		}
	}
}
// DuyetTangDan
void DuyetLNR(node *root)
{
	if (root == NULL)	return;
	DuyetLNR(root->left);
	cout << root->key << ' ';
	DuyetLNR(root->right);
}
// Duyet giua khong de quy
void DuyetLNR2(node *root)
{
	if (root == NULL)
	{
		cout << "Cay rong !!" << endl;
		return;
	}
	
	stack <node*> st;
	top:
	while(root != NULL)
	{
		st.push(root);
		root = root->left;
	}
	while(!st.empty())
	{
		if (st.top()->right != NULL)
		{
			root = st.top()->right;
			//st.push(root);
			cout<< st.top()->key << ' ';
			st.pop();
			goto top;
		}
		else
		{
			cout << st.top()->key << ' ';
			st.pop();
		}
	}
}

// DuyetGiamDan
void DuyetRNL(node *root)
{
	if (root == NULL)	return;
	DuyetRNL(root->left);
	cout << root->key << ' ';
	DuyetRNL(root->right);
}
// Tim 1 node trong cay nhi phan tim kiem
bool FindNode(node *root, int x)
{
	if (root == NULL)	return false;
	while(root != NULL)
	{
		if (x > root->key)
			root = root->right;
		else
			if (x < root->key)
				root = root->left;
			else
			{
				break;
			}
	}
	if (root == NULL)	return 0;
	return 1;
}
// Dem so node trong cay
int Size(node *root)
{
	if (root == NULL)	return 0;
	return 1 + Size(root->left) + Size(root->right);
}
// Ham tim node the mang
void FindMinLeft(node **temp, node **dbtemp)
{
	if ((*dbtemp)->left != NULL)
	{
		FindMinLeft(temp, &(*dbtemp)->left);
	}
	else
	{
		(*temp)->key = (*dbtemp)->key;
		*temp = *dbtemp;
		*dbtemp = (*dbtemp)->right;
	}
}
// Ham xoa 1 node trong cay nhi phan tim kiem
void DelNode(node** root, int x)
{
	if (*root == NULL)
	{
		return;
	}
	node **temp = root;
	while(1)
	{
		if ((*temp)->key < x)
		{
			temp = &(*temp)->right;
		}
		else
			if((*temp)->key > x)
			{
				temp = &(*temp)->left;
			}
			else
			{
				break;
			}
	}
	node *cmp = *temp;
	if ((*temp)->left == NULL)
	{
		*temp = (*temp)->right;
	}
	else
		if ((*temp)->right == NULL)
		{
			*temp = (*temp)->left;
		}
		else
		{
			FindMinLeft(&cmp, &(*temp)->right);
		}
	delete cmp;
}
void TurnRight(node **root)
{
	node *temp = *root;
	*root = (*root)->left;
	if ((*root)->right == NULL)
	{
		(*root)->right = temp;
		temp->left = NULL;
	}
	else
	{
		temp->left = (*root)->right;
		(*root)->right = temp;
	}
}
void TurnLeft(node **root)
{
	node *temp = *root;
	(*root) = (*root)->right;
	if ((*root)->left == NULL)
	{
		(*root)->left = temp;
		temp->right = NULL;
	}
	else
	{
		temp->right = (*root)->left;
		(*root)->left = temp;
	}
}
// Ngan xep
void push1(int x)
{
	a[n]=x;
	++n;
}
void pop1()
{
	if (n == 0)	return;
	--n;
}
int size1()
{
	return n;
}
int top1()
{
	if (n == 0)	return 0;
	return a[n-1];
}
bool empty1()
{
	return n == 0;
}
// Hang doi
void push2(int x)
{
	a[n] = x;
	++n;
}
void pop2()
{
	if (n == 0)	return;
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	--n;
}
int size2()
{
	return n;
}
bool empty2()
{
	return n == 0;
}
int front()
{
	if (n != 0)
		return a[0];
}
// Danh sach lien ket
typedef struct node2
{
	int data;
	node2 *next;
} node2;
node2* makeNode2(int x)
{
	node2* newNode = new node2();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void DuyetDSLK(node2 *head)
{
	while(head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << el;
}

int CountDSLK(node2 *head)
{
	int cnt = 0;
	while(head != NULL)
	{
		++cnt;
		head = head->next;
	}
	return cnt;
}

void pushFront(node2 **head, int x)
{
	node2 *newNode = makeNode2(x);
	newNode->next = *head;
	*head = newNode;
}

void pushBack(node2 **head, int x)
{
	node2 *newNode = makeNode2(x);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	node2 *temp = *head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

void insert(node2 **head, int x, int k)
{
	int n = CountDSLK(*head);
	if (k < 1 || k > n + 1)	return;
	if (k == 1)
	{
		pushFront(head, x);
		return;
	}
	node2 *newNode = makeNode2(x);
	node2 *temp = *head;
	for(int i = 1; i <= k - 2; i++)
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void popFornt(node2 ** head)
{
	if (*head == NULL)
	{
		return;
	}
	node2 *temp = *head;
	*head = (*head)->next;
	delete temp;
}

void popBack(node2 **head)
{
	if (*head == NULL)
	{
		return;
	}
	node2 *temp = *head;
	if (temp->next == NULL)
	{
		*head = NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node2 *last = temp->next;
	temp->next = NULL;
	delete last;
}

void delMid(node2 **head, int k)
{
	int n = CountDSLK(*head);
	if (k < 1 || k > n )
		return;
	if (k == 1)
	{
		popFornt(head);
		return;
	}
	node2 *temp = *head;
	for (int i = 1; i <= k - 2; i++)
	{
		temp = temp->next;
	}
	node2 *ht = temp->next;
	temp->next = ht->next;
	delete ht;
}

void SortDSLK(node2 **head)
{
	for(node2 *i = *head; i != NULL; i = i->next)
	{
		node2 *min = i;
		for (node2 *j = i->next; j != NULL; j = j->next)
		{
			if (min->data > j->data)
			{
				min = j;
			}
		}
		swap(min->data,i->data);
	}
}

bool FindXDSLK(node2 *head,int x)
{
	if (head == NULL)
		return 0;
	while(head != NULL)
	{
		if (head->data == x)
			return 1;
		head = head->next;
	}
	return 0;
}

node2 *FindPreXDSLK(node2 *head, int x)
{
	if (head == NULL)	return NULL;
	while(head->next != NULL)
	{
		if (head->next->data == x)	return head;
		head = head->next;
	}
	if (head->data == x)	return head;
	return NULL;
}

void XoaGiaTriX(node2 **head, int x)
{
	if (*head == NULL)	return;
	if ((*head)->data == x)
	{
		node2 *temp = *head;
		*head = NULL;
		delete temp;
	}
	node2 *temp = FindPreXDSLK(*head, x);
	if (temp == NULL)	return;
	node2 *hientai = temp->next;
	temp->next = hientai->next;
	delete hientai;
}


int main()
{
	
}