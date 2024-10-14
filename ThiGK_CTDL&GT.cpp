#include <bits/stdc++.h>
using namespace std;

void NhapMang(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
}
void PhatSinhMang(int a[], int n)
{
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		a[i] = -99 + rand() % (99 + 1 + 99);
	}
}
void XuatMang(int a[], int n)
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		printf("%10d", a[i]);
	}
}
// Ghi, Doc File 
// Doc file vao mang
void DocFile(const char *file_Name, int a[], int &n)
{
	FILE *f = fopen(file_Name, "r");
	if(!f)
	{
		printf("Khong the mo file !!!");
		return;
	}
	int idex = 0;
	while(fscanf(f, "%d",&a[idex]) != EOF)
	{
		idex++;
	}
	n = idex;
}

/////////////////////////////////////////////////////////////////////
void InMang(int a[], int n)
{
	for(int i = 0; i < n;i++)
	{
		printf("%2d",a[i]);
	}
	printf("\n");
}
////////////////////////////////////////////////////////////////////
// Doc Ghi File Struct
typedef struct SinhVien
{
	char mssv[30];
	char ten[30];
	float diem;
	char lop[20];
	
} SinhVien;

void DocFileStruct(const char *file_Name, SinhVien a[], int &n)
{
	FILE *f = fopen(file_Name, "r");
	if(!f)
	{
		printf("Khong the mo file !!!");
		return;
	}
	int idex = 0;
	while(fscanf(f, "%[^,],%[^,],%f,%[^\n]\n", a[idex].mssv, a[idex].ten, &a[idex].diem, a[idex].lop) != EOF)
	{
		idex++;
	}
	n = idex;
}

void InMangStruct(SinhVien a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("MSSV:%s TEN:%s DIEM:%.2f LOP:%s\n",a[i].mssv,a[i].ten,a[i].diem,a[i].lop);
	}
}
////////////////////////////////////////////////////////
int LinearSearch(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i]!=x) 
		i++;
	if (i<n) return i; //a[i] là phần tử có khoá x
	return -1; // tìm hết mảng nhưng không có x
}

int BinarySearch(int a[],int left,int right,int x)
{
	if(left > right)
		return -1;
	int mid = (left+right)/2;
	if(x == a[mid])
		return mid;
	if(x < a[mid])
		return BinarySearch(a,left,mid-1,x);
	if(x > a[mid])
		return BinarySearch(a,mid+1,right,x);
}


struct 	Node
{ 
	int data; 
	Node *link; 
};
struct List
{ 
	Node *first, *last; 
};

void Init(List &l)
{
	l.first = NULL;
	l.last = NULL;
}


Node *GetNode(int x)
{
	Node *p;
	// Node *p = (Node*)malloc(sizeof(Node))
	p = new Node;
	if(p == NULL)
		return NULL;
	p->data = x; 
	p->link = NULL;
	return p;
}

void AddFirst(List &L, Node* new_ele)
{
	if(L.first == NULL) //Danh sách rỗng
	{
		L.first = new_ele;
		L.last = L.first;
	}
	else {
		new_ele->link = L.first; 
		L.first = new_ele; 
	}
}



void InsertFirst(List &L, int x)
{
	Node* new_ele = GetNode(x);
	if (new_ele == NULL)
		return;
	AddFirst(L, new_ele);
}
void InsertLast (List&L, int x);
void CreateListFirst(List &L)
{
	int  x;
	do
	{ 
		printf("\nBat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: \n"); 
		scanf("%d", &x); 
		if (x == -1) 
			break; 
		InsertFirst(L, x); 
	} 
	while (x != -1); 
	printf("\nDa nhap du lieu xong: \n"); 
}

void CreateListLast(List &L)
{
	int x;
	do
	{ 
		printf("\nBat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: \n"); 
		scanf("%d", &x); 
		if (x == -1) 
			break; 
		InsertLast(L, x); 
	} 
	while (x != -1); 
	printf("\nDa nhap du lieu xong: \n"); 
}
void PrintList(List L)
{
	Node *p;
	p = L.first;
	while (p!= NULL)
	{ 
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}


void AddLast (List&L, Node *new_ele)
{
	if(L.first == NULL) //danh sách rỗng
	{
		L.first = new_ele;
		L.last = new_ele;
	}
	else
	{
		L.last->link = new_ele;
		L.last = new_ele;
	}
}

void InsertLast (List&L, int x)
{
	Node* new_ele = GetNode(x);
	if (new_ele == NULL)
		return;
	AddLast(L, new_ele);
}

void InsertAfterQ(List &L, int x, int q)
{
	if(L.first == NULL)
	{
		InsertFirst(L, x);
		return;
	}
	Node *temp = L.first;
	Node *newNode = GetNode(x);
	while(temp->link != NULL)
	{
		if(temp->data == q)
		{
			newNode->link = temp->link;
			temp->link = newNode;
			return;
		}
		temp = temp->link;
	}
	InsertLast(L,x);
}


void TimKiemX(List L, int x)
{
	Node* temp = L.first;
	while(temp != NULL)
	{
		if(temp->data == x)
		{
			printf("TIM THAY\n");
			return;
		}
		temp = temp->link;
	}
	printf("KHONG TIM THAY\n");
}

void XoaNodeDau(List &L)
{
	if(L.first == NULL)
	{
		return;
	}
	Node* temp = L.first;
	L.first = temp->link;
	if(L.first == NULL)	
		L.last = NULL;
	delete temp;	
}


void XoaNodeCuoi(List &L)
{
	if(L.first == NULL)
	{
		return;
	}
	if(L.first == L.last)
	{
		XoaNodeDau(L);
		return;
	}
	Node* temp = L.first;
	while(temp->link->link != NULL)
	{
		temp = temp->link;
	}
	L.last = temp;
	temp = temp->link;
	delete temp;
	L.last->link = NULL;
}

void XoaNodeK(List &L, int k)
{
	if(L.first == NULL)
		return;
	if(L.first->data == k)
	{
		XoaNodeDau(L);
		return;
	}
	if(L.last->data == k)
	{
		XoaNodeCuoi(L);
		return;
	}
	Node *temp = L.first;
	while(temp->link != NULL)
	{
		Node *temp2 = temp->link;
		if(temp2->data == k)
		{
			temp->link = temp2->link;
			delete temp2;
			return;
		}
		temp = temp->link;
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


int QuickSort(int a[], int left, int right)
{ 
	int i, j, x;
	if (left >= right) 
		return -1;
	x = a[(left+right)/2]; // chọn phần tử giữa làm giá trị mốc
	i = left; j = right;
	do{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j) 
		{ 
			Swap(a[i], a[j]);
			i++ ; j--;
		}
	} while(i < j);
	if(left < j) QuickSort(a, left, j);
	if(i < right) QuickSort(a, i, right);
}

void SelectionSort(int a[], int n )
{
	int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
	for (int i=0; i<n-1; i++)
	{ 
		min = i; 
		for(int j = i+1; j<n; j++)
		if (a[j] < a[min])
			min = j; // ghi nhận vị trí phần tử nhỏ nhất
		if (min != i) 
			Swap(a[min], a[i]);
	}
}

void InsertionSort(int a[], int n)
{
	int pos, x;
	for(int i=1; i<n; i++) //đoạn a[0] dã sắp
	{
		x = a[i]; 
		pos = i-1;
		while(pos>=0 && a[pos]>x)
		{ 
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}

void BubbleSort(int a[], int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if(a[j] < a[j-1])
				Swap(a[j], a[j-1]);
}

void InterchangeSort(int a[], int n)
{
	for (int i=0 ; i<n-1 ; i++)
		for (int j=i+1; j < n ; j++)
			if(a[i]>a[j]) //nếu có nghịch thế thì đổi chỗ
				Swap(a[i], a[j]);
}

int main()
{
	const char *fileName = "test.txt";
//	int a[100], n = 0;
//	DocFile(fileName, a, n);
//	InMang(a, n);
	//QuickSort(a, 0, n-1);
	//SelectionSort(a,n);
	//InsertionSort(a, n);
	//BubbleSort(a, n);
//	InterchangeSort(a, n);
//	InMang(a, n);
	
	SinhVien a[100];
	int n = 0;
	DocFileStruct(fileName, a, n);
	InMangStruct(a, n);

////////////

//	List L;
//	Init(L);
//	CreateListLast(L);
//	//CreateListFirst(L);
//	PrintList(L);
//	int x,q;
	//printf("\nNhap gia tri x va q:");
	//scanf("%d%d",&x,&q);
	//InsertAfterQ(L, x, q);
	//PrintList(L);
//	XoaNodeDau(L);
//	PrintList(L);
//	XoaNodeCuoi(L);
//	PrintList(L);

//	int k;
//	printf("Nhap Gia Tri K Muon Xoa:");
//	scanf("%d",&k);
//	XoaNodeK(L, k);
//	PrintList(L);

	
}
