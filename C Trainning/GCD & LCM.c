#include <stdio.h>
#include <stdlib.h>
int GCD(int a, int b)
{
    while (a != b)
    {
        if(a>b)
        {
            a= a-b;
        }
        else
        {
            b= b-a;
        }

    }
    return a;
}
int LCM(int a, int b)
{
    return (a*b) / GCD(a,b);
}
int main()
{
    printf("%d",LCM(10,15));
    return 0;
}
