#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct studentManage
{
    int SI;
    char ID[10];
    char name[50];
    char date[11];
    char card[100];
    char Address[1000];
    char phone[11];
    char homeName[50];
    char homePhone[11];
};
void menu() {
    printf("=================He thong quan ly Profile Sinh Vien================\n");
    printf("1. Tao danh sach sinh vien moi\n");
    printf("2. Xuat danh sach sinh vien voi ma Student ID\n");
    printf("3. Cap nhat lai thong tin cua sinh vien voi ma Student ID\n");
    printf("4. Xoa sinh vien voi ma student ID\n");
    printf("5. Xuat danh sach cua toan bo sinh vien\n");
    printf("0. THOAT!!!\n");
}
struct studentManage ptr; // console to read
void printProductInfo(struct studentManage p)
{
    printf("NO: %d  Student ID: %s | Name: %-15s | Date of birth: %s | Citizen ID Card: %d | Address: %-25s | Phone number: %s | Parent(s) Name: %-15s | Parent(s) Phone Number: %s\n",p.SI,p.ID,p.name,p.date,p.card,p.Address,p.phone,p.homeName,p.homePhone);
}
void createProfileStudent()
{
    struct studentManage data[1000];
    int i = 0;
    int n;
    fflush(stdin);
    data[i].SI = i+1;
    printf("Student ID (ex: HE151359): "); gets(data[i].ID);
    printf("Student Name (ex: Dang Viet Anh): "); gets(data[i].name);
    printf("Date of birth (ex: 04/07/2001): "); gets(data[i].date);
    printf("Citizen ID Card (ex: 033201003496): "); gets(data[i].card);
    printf("Address (ex: Van Du, An Thi, Hung Yen): "); gets(data[i].Address);
    printf("Phone number (ex:0368639828): "); gets(data[i].phone);
    printf("Parent(s) Name (ex: Dang Quang Quan): "); gets(data[i].homeName);
    printf("Parent(s) Phone Number (ex: 0974427944): "); gets(data[i].homePhone);
    printf("=================================\n");
    char file_name[100] = "studentSE1607.dat";
    FILE *fp = NULL;
    fp = fopen(file_name,"a");// open file append mode
     if (fp == NULL)
    {
        printf("Can't open file %s for waitting..\n",file_name);
        exit(1); // stop
    }
    fwrite( &data[i],sizeof(struct studentManage),1,fp);
    if (fwrite != 0)
    {
        printf("Student informational data has been recorded\n");
        i++;
    }
    else
    {
        printf("Student informational data hasn't been recorded\n");
    }

    //printProductInfo(data[i]);

}
void printFromFile()
{
    char file_name[100] = "studentSE1607.dat";
    FILE *fp = NULL;
    fp = fopen(file_name,"r");
    if (fp == NULL)
    {
        printf("Can't open %s for reading...\n",file_name);
        exit(1);
    }
    while (fread(&ptr,sizeof(struct studentManage),1,fp))
    {
        printProductInfo(ptr);
    }
}
int selectMenu()
{
    int n = 0;
    printf("\n\nMoi chon menu: ");
    scanf("%d",&n);
    if (n > 0 || n < 6)
        return n;
    else return selectMenu();
}
void menuProcessing()
{
	int select = selectMenu();
	switch (select)
	{
	case 1:
		printf("======================Tao danh sach sinh vien====================\n");
		createProfileStudent();
		break;
    case 5:
        printf("======================Danh sach sinh vien cua lop la====================\n");
        printFromFile();
        break;
	case 99:
		printf("Thoat!!!\n");
		exit(1);
		break;
	}
}


int main()
{
    while (1)
    {
        menu();
   menuProcessing();
    }

}
