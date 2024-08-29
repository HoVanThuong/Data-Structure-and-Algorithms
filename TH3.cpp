#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
typedef struct Node{
	int data;
	Node* link;
} Node;

typedef struct List{
	Node* first;
	Node* last;
} List;

Node* SearchNode(List L, int x);
void Init(List &L)
{
	L.first = NULL;
	L.last = NULL;
}

Node* GetNode(int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));// Trong c

	newNode->data = x;
	newNode->link = NULL;
	return newNode;
}

void AddFirst(List &L, Node* newNode)
{
	if (L.first == NULL)
	{
		L.first = newNode;
		L.last = L.first;
	}
	else
	{
		if (!SearchNode(L, newNode->data))
		{
			newNode->link = L.	first;
			L.first = newNode;
		}
		else
		{
			printf("Trung gia tri!!!!\n");
		}
	}
}

void AddLast(List &L, Node* newNode)
{
	if (L.first == NULL)
	{
		L.first = newNode;
		L.last = L.first;
	}
	else
	{
		L.last->link = newNode;
		L.last = newNode;
	}
}
void InsertFirst(List &L, int x)
{
	Node* newNode = GetNode(x);
	AddFirst(L, newNode);
}

void InsertLast(List &L, int x)
{
	Node* newNode = GetNode(x);
	AddLast(L, newNode);
}

void CreateListFirst(List &L)
{
	int x;
	do
	{
		printf("Nhap gia tri muon them, nhap -1 de dung lai:\n");
		scanf("%d",&x);
		if(x != -1){
			InsertFirst(L, x);
		}
	}while(x != -1);
	printf("Da nhap xong\n");
}
void CreateListLast(List &L)
{
	int x;
	do
	{
		printf("Nhap gia tri muon them, nhap -1 de dung lai:\n");
		scanf("%d",&x);
		if(x != -1){
			InsertLast(L, x);
		}
	}while(x != -1);
	printf("Da nhap xong\n");
}
void PrintList(List L)
{
	Node* head = L.first;
	while(head != NULL){
		printf("%d ",head->data);
		head = head->link;
	}
}

long SumEvenNumber(List L)
{
	Node* temp = L.first;
	long sum = 0;
	while(temp != NULL)
	{
		if (temp->data % 2 == 0)
		{
			sum += temp->data;
		}
		temp = temp->link;
	}
	return sum;
}

Node* SearchNode(List L, int x)
{
	Node* temp = L.first;
	while(temp != NULL)
	{
		if(temp->data == x)
		{
			return temp;
		}
		temp = temp->link;
	}
	return NULL;
}

void Separating_List(List &L, List &L1, int x)
{
	if (L.first == NULL)
	{
		printf("Danh sach khong ton tai !!!!");
	}
	else
	{
		Node* temp = L.first;
	List L2;
	Init(L2);
	while(temp != NULL)
	{
		if (temp->data > x)
		{
			InsertLast(L1, temp->data);
		}
		else
		{
			InsertLast(L2, temp->data);
		}
		temp = temp->link;
	}
	L = L2;
	}
}
int main()
{
	List L, L1;
	Init(L);
	Init(L1);
	//CreateListFirst(L);
	//CreateListLast(L);
	PrintList(L);
	printf("\n");
//	printf("Tong chan la: %ld \n", SumEvenNumber(L));
//	if (SearchNode(L, 8) != NULL)
//	{
//		printf("Tim thay\n");
//		
//	}
//	else
//	{
//		printf("Khong tim thay \n");
//	}
	Separating_List(L, L1, 5);
	PrintList(L);
	printf("\n");
	printf("L1 la:\n");
	PrintList(L1);
	
}