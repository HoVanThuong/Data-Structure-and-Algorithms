#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cho dãy số nguyên A như sau: 
//12 2 15 -3 8 5 1 -8 6 0 4 15 
//1. Sắp xếp dãy trên tăng dần. 
//2. Suy ra số lớn thứ 3 trong dãy. 
//3. Suy ra số lượng phần tử lớn nhất trong dãy. 
//4. Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần. 
//5. Sắp xếp dãy trên theo quy luật sau: 
//• Các số dương (nếu có) ở đầu mảng và có thứ tự giảm dần, 
//Bài thực hành môn Cấu trúc dữ liệu và giải thuật 11
//Khoa CNTT – ĐH Công nghiệp TP. HCM Biên soạn: ThS Võ Thị Xuân Thiều
//• Các số âm (nếu có) ở cuối mảng và có thứ tự tăng dần. 
//6. Sắp xếp dãy trên theo quy luật: 
//• Các số chẵn (nếu có) ở đầu mảng và có thứ tự tăng dần, 
//• Các số lẻ (nếu có) ở cuối mảng và có thứ tự giảm dần.
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if (i <= j) 
		{
			swap(a[i], a[j]);
			i++;j--;
		}
	}while(i < j);
	if (l < j)	QuickSort(a, l, j);
	if (r > i) 	QuickSort(a, i, r);
}
void in(int a[], int n)
{
	for (int i = 0; i < n;  i++)
	{
		//printf("A[%d] = %d\n", i, a[i]);
		printf("%d ", a[i]);
	}
}

int Max3(int a[], int n)
{
	QuickSort(a,0, n - 1);
	if (n >= 3)
	{
		return a[n-3];
	}
	else
	{
		return -1;
	}
}

int CountMax(int a[], int n)
{
	int count = 1;
	QuickSort(a,0,n-1);
	int max = a[n-1];
	int i = n - 2;
	while(a[i] == max)
	{
		count++;
		i--;
	}
	return count;
}

void QuickSortABS(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l, j  = r;
	do {
		while(abs(a[i]) < abs(x)) i++;
		while(abs(a[j]) > abs(x)) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;j--;
		}
		
	}while(i < j);
	if (l < j)	QuickSortABS(a, l ,j);
	if (r > i)	QuickSortABS(a, i, r);
}

void QuickSortGiam(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while(a[i] > x) i++;
		while(a[j] < x) j--;
		if (i <= j) 
		{
			swap(a[i], a[j]);
			i++;j--;
		}
	}while(i < j);
	if (l < j)	QuickSortGiam(a, l, j);
	if (r > i) 	QuickSortGiam(a, i, r);
}


void SortByMySeft(int a[], int n)
{
	QuickSortGiam(a, 0, n-1);
	int idex = -1;
	for (int i = 0; i < n; i ++)
	{
		if (a[i] < 0)
		{
			idex = i;
			break;
		}
	}
	if (idex == -1)
	{
		return;
	}
	else
	{
		QuickSort(a,idex,n-1);
	}
	
}

int SortChanLe(int a[], int n)
{
	int i = 0, j = n - 1;
	do
	{
		while(a[i] % 2 == 0) i++;
		while(a[j] % 2 != 0) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	}while(i < j);
	return j + 1;
}

void SapXep6(int a[], int n)
{
	int idex = SortChanLe(a, n);
	QuickSort(a,0,idex-1);
	QuickSortGiam(a, idex, n - 1);
}

////////////////////////////////////////////////////////////////

typedef struct Sinhvien{
	int MaSo;
	char Hoten[30];
	char Diachi[30];
	float DTB;
} SV;
void NhapSV(SV a[], int &n)
{
	printf("Nhap ma sinh vien:");
	scanf("%d",&a[n].MaSo);
	getchar();
	printf("Nhap ho ten:");
	gets(a[n].Hoten);
	printf("Nhap dia chi:");
	gets(a[n].Diachi);
	printf("Nhap diem trung binh:");
	scanf("%f",&a[n].DTB);
	++n;
}

void inSV(SV a[], int n)
{
	printf("%10s %10s %10s %10s\n","MASO", "HOTEN","DIACHI","DTB");
	for (int i = 0; i < n; i++)
	{
		printf("%10d %10s %10s %10.3f\n", a[i].MaSo, a[i].Hoten, a[i].Diachi, a[i].DTB);
	}
}

void xuatSVX(SV a[], int n, int x)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i].MaSo == x)
		{
			printf("%10d %10s %10s %10.3f\n", a[i].MaSo, a[i].Hoten, a[i].Diachi, a[i].DTB);
			flag = true;
		}
	}
	if (!flag)
		printf("Khong tim thay sinh vien\n");
}

void Sort1(SV a[], int l, int r)
{
	SV x = a[(l + r) / 2];
	int i = l, j = r;
	do{
		while(a[i].DTB < x.DTB) i++;
		while(a[j].DTB > x.DTB) j--;
		if (i <= j)
		{
			SV temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;j--;
		}
	}while(i < j);
	if (l < j) Sort1(a, l, j);
	if (r > i) Sort1(a, i, r);
}

void Sort2(SV a[], int l, int r)
{
	SV x = a[(l + r) / 2];
	int i = l, j = r;
	do 
	{
		while(strcmp(a[i].Hoten,x.Hoten) < 0) i++;
		while(strcmp(a[j].Hoten,x.Hoten) > 0) j--;
		if (i <= j)
		{
			SV temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;j--;
		}
	}while(i < j);
	if (l < j) Sort2(a, l, j);
	if (r > i) Sort2(a, i, r);
}

void GhiFile(SV a[], int n)
{
	FILE *file = fopen("C:\C++\C++Code\Sinhvien.txt","w");
	if (!file)
	{
		printf("Khong the tao hoac mo file\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(file, "%d,%s,%s,%f\n",a[i].MaSo,a[i].Hoten,a[i].Diachi,a[i].DTB);
		}
	}
	fclose(file);
}

void DocFile(SV a[], int &n)
{
	FILE* file = fopen("Sinhvien.txt","r");
	if (!file)
	{
		printf("Khong the mo file\n");
		exit(1);
	}
	else{
		int i = 0;
		while(fscanf(file,"%d,%[^,],%[^,],%f",&a[i].MaSo,a[i].Hoten,a[i].Diachi,&a[i].DTB) != EOF)
		{
			i++;
		}
		n = i;
	}
	fclose(file);
}


void SuaSv(SV a[], int n, int x)
{
	bool flag = false;
	int i  = 0;
	for (; i < n; i++)
	{
		if (a[i].MaSo == x)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		printf ("Khong tim thay");
	}
	else
	{
			printf("Nhap ma sinh vien:");
		scanf("%d",&a[i].MaSo);
		getchar();
		printf("Nhap ho ten:");
		gets(a[i].Hoten);
		printf("Nhap dia chi:");
		gets(a[i].Diachi);
		printf("Nhap diem trung binh:");
		scanf("%f",&a[i].DTB);	
	}
}

void xoaSV(SV a[], int &n, int x)
{
	bool flag = true;
	int i = 0;
	for (;i < n ;i++)
	{
		if (a[i].MaSo == x)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		printf("Khong tim thay sinh vien");
	}
	else
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1]; 
		}
		n--;
		
	}
}


void dtbCaoNhat(SV a[], int n)
{
	Sort1(a, 0, n - 1);
	float max = a[n-1].DTB;
	int i = n - 1;
	do {
		printf("%10d %10s %10s %10.3f\n", a[i].MaSo, a[i].Hoten, a[i].Diachi, a[i].DTB);
		i--;	
	}while(a[i].DTB == max);
}
int main()
{
//	int a[] = {21,41,61,81,101,121,1001,161,181,201};
//	int n = 10;
//	SortByMySeft(a, n);
//	//QuickSortGiam(a, 0, n -1);
//	SapXep6(a, n);
//	//printf("%d \n",SortChanLe(a, n));
//	in(a, n);
	
	SV DanhSachSV[50];
	int n = 0;
//	NhapSV(DanhSachSV,n);
//	NhapSV(DanhSachSV, n);
//	NhapSV(DanhSachSV, n);
//	inSV(DanhSachSV,n);
//	xuatSVX(DanhSachSV,n,123);
//	Sort1(DanhSachSV, 0, n - 1);
//	inSV(DanhSachSV, n);
//	GhiFile(DanhSachSV, n);
	DocFile(DanhSachSV, n);
	inSV(DanhSachSV, n);
	printf("\n");
	dtbCaoNhat(DanhSachSV, n);
	xoaSV(DanhSachSV, n, 123);
	printf("\n");
	inSV(DanhSachSV,n);
}
//Cho mảng một chiều quản lý thông tin của các sinh viên trongmột lớp học 
//(tối đa 50 sinh viên). Mỗi sinh viên gồm các thông tin: MSSV, họ và tên, 
//giới tính, địa chỉ và điểm trung bình. Viết chương trình thực hiện các yêu 
//cầu sau:
//1. Nhập các sinh viên vào danh sách.
//2. In danh sách sinh viên.
//3. Xuất thông tin của sinh viên có mã số x.
//4. Sắp xếp danh sách sinh viên theo thứ tự tăng dần của điểm trung bình.
//5. Sắp xếp danh sách sinh viên theo thứ tự tăng dần của họ và tên.
//6. Ghi danh sách sinh viên vào FILE
//7. Đọc danh sách sinh viên từ FILE
//8. Sửa thông tin của một sinh viên có mã X
//9. Xóa sinh viên có mã X
//10.Xuất ra các sinh viên có điểm trung bình cao nhất
