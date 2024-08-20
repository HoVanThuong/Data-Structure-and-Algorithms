#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


typedef struct Word{
	char Name[30];
	char Meaning[30];
} Word;

void readFile(Word W[], int &n)
{
	FILE* f = fopen("test.txt", "r");
	if (!f)
	{
		printf("Khong the mo tep");
		exit(1);
	}
	else{
			int i = 0;
	while(fscanf(f,"%[^,],%[^\n]", W[i].Name, W[i].Meaning) != EOF)
	{
		i++;
	}
	n = i;
	fclose(f);
	}

}


void timKiem(Word W[], int l, int r, char tu[])
{
	if (l > r){
		printf("Khong tim thay");
		return;
	}
	int mid = (l + r) / 2;
	if (strcmp(W[mid].Name, tu) == 0)
	{
		printf("Nghia cua tu %s: %s\n", W[mid].Name, W[mid].Meaning);
		return;
	}
	if (strcmp(W[mid].Name, tu) > 0)
		timKiem(W, l , mid - 1, tu);
	else
		timKiem(W, mid + 1, r, tu);
}


void in(Word w[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		printf("%s : %s\n", w[i].Name, w[i].Meaning);
	}
}



void sapXep(Word W[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j  = i + 1; j < n; j++)
		{
			if (strcmp(W[i].Name,W[j].Name) > 0)
			{
				Word temp = W[i];
				W[i] = W[j];
				W[j] = temp;
			}
		}
	}
}


int main()
{
	Word W[100];
	int n = 0;
	readFile(W,n);
	in(W,n);
	sapXep(W,n);
	timKiem(W,0, n - 1, "Attribute");
	in(W,n);
}