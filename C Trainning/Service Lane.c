#include <stdio.h>
int main()
{
//    !!!!!!!!!!YOU CAN CHANGE THE RANGE OF THE VARIABLE BELOW IF YOUR TEST CASE LIMITS!!!!!!!!!  
    int test[10000],width[100000];
    int cases[1000][1000]; 
    int n,t;
    scanf("%d %d",&n,&t);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&width[i]);
    }
    for (int i=0; i<t; i++)
    {
        for (int j=0; j<2; j++)
        {
            scanf("%d",&cases[i][j]);
        }
    }
    //      size=8;
    for (int i=0; i<t; i++)
    {
        for (int j=cases[i][0]; j<=cases[i][1]; j++)
        {
            test[j]=width[j];

        }
        int min = test[cases[i][0]];
        for (int j=cases[i][0]; j<=cases[i][1]; j++)
        {
            if(test[j]<min)
            {
                min = test[j];
            }
        }
        printf("%d \n",min);
    }
}



