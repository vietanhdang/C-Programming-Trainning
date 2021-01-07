#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100]= {0*(n+1)}; //tao mang chua 1 day n+1 so 0 de minh them 1 vao
    a[1]=1;
    for (int i=2; i<n+1; i++)
    {
        a[i]= a[i-1]+a[i-2];

    }
    printf("%d",a[n]);

}

