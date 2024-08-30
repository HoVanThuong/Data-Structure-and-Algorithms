#include <bits/stdc++.h>

using namespace std;


struct Node{
	float heso;
	int somu;
	Node* link;
};

struct List
{
	Node* first;
	Node* last;
};

void init(List &L)
{
	L.first = NULL;
	L.last = NULL;
}

Node* getNode(float heso, int somu)
{
	Node* newNode = new Node();
	newNode->heso = heso;
	newNode->somu = somu;
	newNode->link = NULL;
	return newNode;
}

void addLast(List &L, Node* newNode)
{
	if (L.first == NULL)
	{
		L.first = newNode;
		L.last = newNode;
	}
	else
	{
		L.last->link = newNode;
		L.last = newNode;
	}
}

void insertLast(List &L, float heso, int somu)
{
	Node* newNode = getNode(heso, somu);
	addLast(L, newNode);
}

void nhapDaThuc(List &L)
{
	float heso;
	int somu;
	printf("Nhap he so va so mu cua da thuc, nhap he so 0 de dung lai:\n");
	do{
		printf("Nhap he so:");
		scanf("%f",&heso);
		printf("Nhap so mu:");
		scanf("%d",&somu);
		if (heso != 0)
			insertLast(L, heso, somu);
	}
	while(heso != 0);
	printf("Da nhap xong!!\n");
}

void xuatList(List L)
{
	Node* temp = L.first;
	int flag = false;
	while(temp)
	{
		if (temp->somu != 0)
			if(temp->heso > 0 && flag == true)
				printf("+%.0f*x^%d ",temp->heso, temp->somu);
			else
				printf("%.0f*x^%d ",temp->heso, temp->somu);
		else
			if(temp->heso > 0 && flag == true)
				printf("+%0.0f ",temp->heso);
			else
				printf("%0.0f ",temp->heso);
		temp = temp->link;
		flag = true;
	}
	printf("\n");
}

void congHaiDaThuc(List L1, List L2, List &L3)
{
	Node* temp1 = L1.first;
	Node* temp2 = L2.first;
	float tongHeSo;
	while(temp1 && temp2)
	{
		if (temp1->somu == temp2->somu)
		{
			tongHeSo = temp1->heso + temp2->heso;
			insertLast(L3, tongHeSo, temp1->somu);
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
		else
		{
			if (temp1->somu > temp2->somu)
			{
				insertLast(L3, temp1->heso, temp1->somu);
				temp1 = temp1->link;
			}
			else{
				insertLast(L3, temp2->heso, temp2->somu);
				temp2 = temp2->link;
			}
		}
	}
	while(temp1)
	{
		insertLast(L3, temp1->heso, temp1->somu);
		temp1 = temp1->link;
	}
	while(temp2)
	{
		insertLast(L3, temp2->heso, temp2->somu);
		temp2 = temp2->link;
	}
}

void interchangeSort(List &L)
{
	for (Node *p = L.first; p != L.last; p = p->link)
	{
		for (Node *q = p->link; q != NULL; q = q->link)
		{
			if (p->somu > q->somu)
			{
				float mup = p->somu;
				float hesop = p->heso;
				p->somu = q->somu;
				p->heso = q->heso;
				q->somu = mup;
				q->heso = hesop;
			}
		}
	}
}
// Nhan 2 da thuc nghe co ve cang :-)))
// Voi format cua bai nay thi con cang x2
// 1. Tim bac cua da thuc
//
// 3. Tien hanh thoi :-)) vc cang

int timBac(List L)
{
	Node* temp = L.first;
	int bac = 0;
	while(temp != NULL)
	{
		if(temp->somu > bac)
		{
			bac = temp->somu;
		}
		temp = temp->link;
	}
	return bac;
}


void nhanHaiDaThuc(List L1, List L2, List &L3)
{
	int bac1 = timBac(L1);
	float heso1[bac1 + 1];
	fill(heso1, heso1 + bac1 + 1, 0.0);
	Node* temp1 = L1.first;
	while(temp1)
	{
		heso1[temp1->somu] += temp1->heso;
		temp1 = temp1->link;
	}
	int bac2 = timBac(L2);
	float heso2[bac2 + 1];
	fill(heso2, heso2 + bac2 + 1, 0.0);
	Node* temp2 = L2.first;
	while(temp2)
	{
		heso2[temp2->somu] += temp2->heso;
		temp2 = temp2->link;
	}
	float heso3[bac1 + bac2 + 1];
	fill(heso3, heso3 + bac1 + bac2 + 1, 0.0);
	for (int i = 0; i <= bac1; i++)
	{
		for (int j = 0; j <= bac2; j++)
		{
			heso3[i+j] += heso1[i]*heso2[j];
		}
	}
	for (int i = 0; i <= bac1 + bac2; i++)
	{
		if (heso3[i] != 0)
			insertLast(L3, heso3[i], i);
	}
}


int main()
{
	List d1, d2, d3;
	init(d1);
	init(d2);
	init(d3);
	nhapDaThuc(d1);
	printf("\nDanh sach bieu dien da thuc d1: ");
	xuatList(d1);
	interchangeSort(d1);
	xuatList(d1);
	nhapDaThuc(d2);
	printf("\nDanh sach bieu dien da thuc d2: ");
	xuatList(d2);
	//congHaiDaThuc(d1, d2, d3);
	//printf("\nDanh sach bieu dien da thuc tong: ");
	//xuatList(d3);
	nhanHaiDaThuc(d1, d2, d3);
	xuatList(d3);
}


