#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxLength 1000
#define maxElements 1000
int printAllElements(char arr[maxElements][maxLength])
{
    for(int i=0; i<maxElements; i++)
    {
        if (strcmp(arr[i],"") !=0)
        {
            printf("Element[%d] = %s \n",i,arr[i]);
        }
    }
}
int del_character(char inString[maxLength], char outString[maxLength])
{
    int j=0;
    for (int i=0; i<strlen(inString); i++)
    {
        if (!((inString[i]<48 && (inString[i] != 32) ) || ((inString[i]>57)&&(inString[i]<65)) || ((inString[i]>90)&&(inString[i]<97)) || (inString[i]>122)))
        {
            outString[j] = inString[i];
            j++;
        }
    }
}
int split_arr(char inString[maxLength], char outString[maxElements][maxLength])
{
    int n = strlen(inString);
    int length=0;
    int countSearch = 0;
    for (int i=0; i<=n; i++)
    {
        if(inString[i] == ' ' || inString[i] == '\0')
        {
            outString[countSearch][length] = '\0';
            countSearch++;
            length = 0;
        }
        else
        {
            outString[countSearch][length] = inString[i];
            length++;
        }
    }
    return countSearch;
}
int sortAllElements(int currentNumberElements, char arr[maxElements][maxLength])
{
    for (int i=0; i<currentNumberElements; i++)
    {
        for (int j= i+1 ; j<currentNumberElements; j++)
        {
            if (strcmp(arr[i],arr[j]) >0 )
            {
                char temp1[maxLength];
                strcpy(temp1,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp1);
            }
        }
    }
}
int max(int n, int a[])
{
    int d =0;
    for (int i=0 ;i<n;i++)
    {
            if (a[i]  > d)
            {
                d = a[i];
            }
    }
    return d;
}
int upCase(int split, char arr[maxElements][maxLength])
{
    for (int i=0; i<split;i++)
    {
        if(arr[i][0] >= 97 && arr[i][0] <= 122)
        {
            arr[i][0] = arr[i][0]-32;
        }
    }
}
int main()
{
    char arr1[maxElements][maxLength]={"\0"};
    char temp1[maxLength];
    int splitCount =0;
    printf("===============WORD RECOMMENDATION SYSTEM AND COUNTER===============\n");
    printf("Enter a string (end with: Enter)\n");
    printf("String is: ");
    char temp[maxLength];
    scanf("%[^\n]", temp);
    printf("======================================================\n");
    printf("This string is included %d CHARACTERS and",strlen(temp));
    del_character(temp,temp1);
    split_arr(temp1,arr1);
    int splitcount;
    splitCount = split_arr(temp1,arr1);
    printf(" %d Words\n",splitCount);
    printf("======================================================\n");
    printf("KEYWORD DENSITY\n\n");
    upCase(splitCount,arr1); //Options can be change in lower-or uppercase (at the beginning of each word)
    sortAllElements(splitCount,arr1);
    int countStr[maxElements];
    int count;
    for (int i=0; i<splitCount;i++)
    {
        if (strcmp(arr1[i],"")!=0)
        {
            countStr[i] = -1;
        }
    }
    for (int i=0; i<splitCount;i++)
    {
        count =1;
        for (int j=i+1; j<splitCount;j++)
        {
            if (strcmp(arr1[i],arr1[j]) == 0)
            {
                count ++;
                countStr[j] = 0;
            }
        }
        if (countStr[i] != 0)
        {
            countStr[i] = count;
        }
    }
    int d = max(splitCount,countStr);
    for (int i=d; i>=1;i--)
    {
        for (int j=0; j<splitCount;j++)
        {
            if (i == countStr[j])
            {
                printf("\n%s || (%d)\n",arr1[j],i);
            }
        }
    }

    //sort elements in arr in ascending order (A to Z)
}
