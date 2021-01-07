#include <stdio.h>
#include <string.h>
int main()
{
    int h[9]= {10,5,20,20,4,5,2,25,1};
    int k=h[0],d=0;
    for (int i=0; i<9; i++)
    {
        if (h[i]>k)
        {
            d=i;
            break;
        }
    }
    int g=h[d];
    int min=0, max=0;
    for (int i=d; i<9; i++)
    {
        if (h[i] >g)
        {
            g= h[i];
            max ++;
        }
        else if (h[i]<g)
        {
            g=h[i];
            min ++;
        }
    }
    printf("%d\n%d",max,min);
}
