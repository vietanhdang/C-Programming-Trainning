//BAI NAY VARIABLES EM ĐẶT HƠI LỘN XỘN MONG MỌI NGƯỜI THÔNG CẢM Ạ hi!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char x;
    int people;
    int l;
    int h[36];
    int z[36]= {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    char list[36][36]= {"1bich","2bich","3bich","4bich","5bich","6bich","7bich","8bich","9bich","1tep","2tep","3tep","4tep","5tep","6tep","7tep","8tep","9tep","1co","2co","3co","4co","5co","6co","7co","8co","9co","1ro","2ro","3ro","4ro","5ro","6ro","7ro","8ro","9ro"};
    printf("***************OM BA CAY****************\n");
    while (1==1)
    {
//        srand(time(NULL));
        printf("Moi ban nhap vao so nguoi ngoi: ");
        scanf("%d",&people);
        if (people >=2 && people<=12)
        {
            l = people*3;
            for (int i=0; i<36; i++)
            {
                h[i] = i;
            }

            for (int k=0; k<36; k++)
            {
                int t = h[k];
                int r = (rand()%36);
                h[k] = h[r];
                h[r] = t;
            }

            for (int i=0; i<l; i+=3)
            {
                int s=0;
                printf("\nplayer %d:    ",(i/3)+1);
                for (int k=i; k<i+3; k++)
                {
                    s+=z[h[k]];
                    printf("%s ",list[h[k]]);

                }
                if(s%10==0)
                    printf("\ttong la: %d",10);
                else
                {
                    printf("\ttong la: %d",s%10);
                }

            }
        }
        else
        {
            printf("So nguoi choi khong hop le\n");
        }
        printf("\nBan co muon choi tiep khong y or n\n");
        fflush(stdin);
        printf("your choise: ");
        scanf("%c",&x);
        if (x=='n')
        {
            break;
        }
    }
}

