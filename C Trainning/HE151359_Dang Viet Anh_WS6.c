#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 200
#define maxElements 200
int numVail(char inStr[maxLength])
{
    for (int i=0; i<strlen(inStr); i++)
    {
        if (inStr[i] <48 || inStr[i] >57)
        {
            return 0;
        }
    }
}
int main()
{
    char arr[maxElements][maxLength]= {"\0"};
    int currentNumberElements = 0;
    char temp1[maxLength];
    int splitCount =0;
    FILE *fp = NULL;
    char str[maxLength];
    printf("===============Sum of numbers divisible by 3===============\n");
    printf("Enter numbers (end with: Enter | #.#)\n");
    fflush(stdin);
    while(1)
    {
        char temp[maxLength];
        scanf("%[^\n]", temp);
        if ((strcmp(temp, "") !=0) && (strcmp(temp,"#.#") !=0) )
        {
            if (numVail(temp) != 0) //Check valid of the number
            {
                int check = atoi(temp);
                fp = fopen("testcase.txt","a");
                if (fp != NULL)
                {
                    if (check%3==0)
                    {
                        fprintf(fp, "%s, hop le\n", temp);
                        strcpy(arr[currentNumberElements],temp);
                        currentNumberElements++;
                    }
                    else
                    {
                        fprintf(fp, "%s, khong hop le\n", temp);
                    }
                    fclose(fp);
                }
            }
        }
        else
            break;
        fflush(stdin);
        strcpy(temp,"");
    }
    int sum=0;
    fp = fopen("testcase.txt","a");
    if (currentNumberElements == 0)
    {

        fprintf(fp,"Khong co so nao hop le chia het cho 3: ");
    }
    else
    {
        fprintf(fp,"Cac so chia het cho 3 la: ");
    for (int i=0; i<currentNumberElements; i++)
    {
        if (fp != NULL && strcmp(arr[i],"") !=0)
        {
            fprintf(fp, "%s ", arr[i]);
            sum += atoi(arr[i]);
        }
    }
    fprintf(fp,"\nTong la: %d",sum);
    }
    //read data from file
//    fp = fopen("testcase.txt","r");
//    int line=1;
//    if (fp != NULL)
//    {
//        while (fscanf(fp, "%60[^\n]%*c", str) != EOF )
//        {
//            printf("%s\n",str);
//            line++;
//        }
//        fclose(fp);
//        printf("File is closed.\n");
//    }
//    else
//    {
//        printf("Failed to open file.\n");
//    }
}
