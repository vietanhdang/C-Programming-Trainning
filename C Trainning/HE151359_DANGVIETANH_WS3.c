#include <stdio.h>
#include <string.h>
#define maxElement 1000
#define maxLength 30
int main()
{
    //Giải bài toán tổng quát (gồm + - * / nhiều phép tính) hoi kho thay a
    //em chỉ giải được một biểu thức (+ -) ất kì thôi ạ.
    char str1[maxElement];
    char newString[maxElement][maxLength];
    int i,j,ctr;
    printf("Input  a expression (plus and minus) ex: [12 + 13 - 85 +- 62] : ");
    scanf("%[^\n]", str1);
    j=0; ctr=0;
    for(i=0;i<=(strlen(str1));i++)
    {
        if(str1[i]==' ' || str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {

            newString[ctr][j]=str1[i];
            j++;
        }
    }
    int h[maxElement]={atoi(newString[0])};
    for(i=0;i < ctr;i++)
    {
        if(newString[i][0] == '-')
        {
                h[i+1] = -atoi(newString[i+1]);
        }
        else if(newString[i][0] == '+')
        {
             h[i+1] = atoi(newString[i+1]);
        }
    }
    int result=0;
    for(i=0;i < ctr;i++)
    {
        result +=h[i];
    }
    printf("Result of a expression (plus and minus) are: %d ",result);
}
