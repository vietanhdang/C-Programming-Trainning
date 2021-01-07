#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    printf("\nNhap n = ");
    scanf("%d", &n);
    int dem;
    for(int i = 2; i <= n; i++)
    {
        dem = 0;  //khoi tao bien de dem so lan ma n chia het cho 2
        while(n % i == 0)
        {
            dem++;
            n /= i;
        }
        if(dem) // lam viec voi bien dem
        {
            if(dem >1)
            {
                printf("%d ^ %d",i,dem);
            }
            else printf("%d", i);
            if(n > i)
            {
                printf(" * ");
            }
        }
    }

}
