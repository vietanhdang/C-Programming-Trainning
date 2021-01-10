#include<stdio.h>
int main()
{
    int x1,x2,v1,v2,c;
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    int s=x1;
    int g=x2;
    if ((x2 > x1) && (v1 > v2))
    {
        for (int i=0; i<x2*v1; i++)
        {
            s +=v1;
            g+=v2;
            if(s==g)
            {
                c=s;
            }
        }
        if(c>0)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    else
    {
        printf("NO");
    }
}
