int enterID(inf danhsach[], int numrecords, char *temp, int done)
{
    done = 0;
    while (1)
    {
        printf("Student ID (ex: HE151359): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp) ==0 )
        {
            return 1;
        }
        else if (validID(temp)!=0)
        {
            idProcess(temp);
            strcpy(danhsach[numrecords].ID,temp);
            break;
        }
    }// Done
}
int enterStudentName(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Student Name (ex: Dang Viet Anh): ");
        fflush(stdin);
        gets(temp);
        if (validName(temp)!=0)
        {
            nameProcess(temp);
            strcpy(danhsach[numrecords].name,temp);
            break;
        }
    }// Done
}
int enterDateOfBirth(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Date of birth (ex: 04/07/2001): ");
        fflush(stdin);
        gets(temp);
        if (validDate(temp)==0)
        {
            strcpy(danhsach[numrecords].date,temp);
            break;
        }
    }//Done
}
int enterSex(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Sex (enter 1 if male, 0 if female): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==1 && temp[0]=='1')
        {
            strcpy(danhsach[numrecords].sex,"Male");
            break;
        }
        else if (strlen(temp)==1 && temp[0]=='0')
        {
            strcpy(danhsach[numrecords].sex,"Female");
            break;
        }
        else
        {
            printf("Sex is not valid, please enter again\n");
        }
    }//Done
}
int enterAddress(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Address (ex: Van Du, An Thi, Hung Yen): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==0)
        {
            strcpy(danhsach[numrecords].Address,"Updating");
            break;
        }
        else
        {
            nameProcess(temp);
            strcpy(danhsach[numrecords].Address,temp);
            break;
        }
    }//Done
}
int enterPhone(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Phone (ex: 0368639828): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==0)
        {
            strcpy(danhsach[numrecords].phone,"Updating");
            break;
        }
        else
        {
            if (validPhone(temp)!=0)
            {
                strcpy(danhsach[numrecords].phone,temp);
                break;
            }
        }
    }//Done
}
int enterDiemToan(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM TOAN MOI LA: ");
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN TOAN KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].diemtoan = n;
            break;
        }
    }//Done
}
int enterDiemLy(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM LY MOI LA: ");
        fflush(stdin);
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN LY KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].diemly = n;
            break;
        }
    }//Done
}
int enterDiemHoa(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM HOA MOI LA: ");
        fflush(stdin);
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN HOA KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].diemhoa = n;
            break;
        }
    }//Done
}
