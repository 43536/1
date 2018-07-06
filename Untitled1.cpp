#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 1000 

float tinhTBC(int a[], int n);
void xoaPTC(int a[], int &n);
void xuat(int a[], int n);
int timVTCMin(int a[], int n);
void ReadFile(int a[], int &n){
	FILE*fp=fopen("input.txt", "rt");
	if(fp==NULL)
		printf("Khong mo duoc file");
	fscanf(fp,"%d", &n);
	for(int i=0; i<n; i++)
		fscanf(fp, "%d", &a[i]);
	fclose(fp);
}

void hienThiMenu(){
	printf("\n1. Nhap danh sach thi sinh");
	printf("\n2. Tinh gia tri trung binh cong");
	printf("\n3. Tim vi tri phan tu co gia tri chan nho nhat");
	printf("\n4. Xoa cac phan tu co gia tri chan");
	printf("\n0. Thoat chuong trinh");
}

int main(){
	int phimchon;
	int a[MAX],n;
	do{
		hienThiMenu();
			printf("\nChon mot chuc nang: ");
			scanf("%d", &phimchon);
		switch(phimchon)
		{
		case 1:

			ReadFile(a,n);

			break;
		case 2:
			xuat(a,n);
			printf("\nGia tri trung binh cua mang: %.2f", tinhTBC(a,n));
			break;
		case 3:
			printf("\nVi tri co phan tu chan be nhat: %d", timVTCMin(a,n));
			break;
		case 4:
			xoaPTC(a,n);
			xuat(a,n);
			break;
		case 0:
			exit(1);
		default:
			printf("CHUC NANG BAN CHON KHONG TON TAI");
			break;
		}

	}while(1);
}
float tinhTBC(int a[], int n){
	float tong=0;
	for(int i=0; i<n; i++)
		tong+=a[i];
	return tong/n;
}
int timVTCMin(int a[], int n){
	int  min=0;
	int vtmin=-1;
	for(int i=0; i<n; i++)
		if(a[i]%2==0)
		{
			vtmin=i;
			min=a[i];
			break;
		}
	for(int i=vtmin+1; i<n; i++)
		if(a[i]%2==0 && a[i]<min)
			vtmin=i;
	return vtmin;
}
void xuat(int a[], int n){
	for(int i=0; i<n; i++)
		printf("%d\t", a[i]);
}
void xoaPTC(int a[], int &n){
	for(int i=0; i<n; i++){
		while(a[i]%2==0){
			for(int j=i;j<n-1;j++)
				a[j]=a[j+1];

			n--;
		}		
	}
	
}




	





