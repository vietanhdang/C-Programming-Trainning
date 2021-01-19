//BAI NAY VARIABLES EM ĐẶT HƠI LỘN XỘN MONG MỌI NGƯỜI THÔNG CẢM Ạ hi!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int numPlayers ;
    char x;
    printf("***************OM BA CAY****************\n");
    while (1==1)
    {
        int people;
        printf("Moi ban nhap vao so nguoi ngoi: ");
        scanf("%d",&people);
        if (people >=2 && people<=12)
        {
            numPlayers = people;

            srand(time(NULL));
            int r=0,t;
            int l= numPlayers*3;
            int h[36]= {1,0*35};
            char list[36][36]= {"1bich","2bich","3bich","4bich","5bich","6bich","7bich","8bich","9bich","1tep","2tep","3tep","4tep","5tep","6tep","7tep","8tep","9tep","1co","2co","3co","4co","5co","6co","7co","8co","9co","1ro","2ro","3ro","4ro","5ro","6ro","7ro","8ro","9ro"};
            for (int i=1; i<36; i++)
            {
                h[i] = i+1;
            }
            for (int k=0; k<35; k++)
            {
                t = h[k];
                r = rand();
                h[k] = h[1+(r%36)];
                h[1+(r%36)] = t;
            }
            for (int i=0; i<numPlayers*3; i+=3)
            {
                printf("\nplayer %d:    ",(i/3)+1);
                for (int k=i; k<i+3; k++)
                {
                    printf("%s ",list[h[k]-1]);
                }
            }

        }
        else
        {
            printf("So nguoi choi khong hop le\n");
        }
        printf("\nBan co muon choi tiep khong y or n\n");
        fflush(stdin);
        printf("your choise: "); scanf("%c",&x);
        if (x=='n')
        {
            break;
        }
    }
}
