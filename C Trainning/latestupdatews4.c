#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxLength 30
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
int lowercase(char str[maxLength])
{
    for (int i=0; i<strlen(str); i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i] = str[i]+32;
        }
        else
        {
            str[i]+=0;
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
int main()
{
    int inputNumber;
    char arr[maxElements][maxLength]={"\0"};
    char arr1[maxElements][maxLength] = {"\0"};
    int currentNumberElements = 0;
    printf("Enter number of elements in the array (Max : 1000 Elements): ");
    scanf("%d",&inputNumber);
    printf("Input method: At the end of a string, press enter \n");
    fflush(stdin);
    char temp[maxLength];
    while(currentNumberElements < inputNumber)
    {
        printf("String %d is: ",currentNumberElements+1);
        scanf("%[^\n]", temp);
        if ((strcmp(temp,"") !=0))
        {
            strcpy(arr[currentNumberElements],temp);
            strcpy(arr1[currentNumberElements],temp);
            currentNumberElements ++;
        }
        else
            break;
        fflush(stdin);
//        strcpy(temp,"");
    }
    printf("================Array Original===================\n");
    printAllElements(arr);

    printf("================Problem 1===================\n");
    printf("Result after ascending sort in this array: \n");
    //sort elements in arr in ascending order (A to Z)

    // Result after ascending sort in this array
    sortAllElements(currentNumberElements,arr);
    printAllElements(arr);
    sortAllElements(currentNumberElements,arr1);
    for (int i=0;i<inputNumber;i++)
    {
        lowercase(arr1[i]);
    }
//    ///////////////////////////////////////////////
    printf("================Problem 2===================\n");
//    //Find the elements contain string
//    //Find exact search value in array
    while(1==1)
    {

        printf("Enter the search value: ");
        fflush(stdin);
        char search[maxLength];
        int searchFound = 0;
        scanf("%[^\n]",search);
        for (int i=0 ; i<currentNumberElements; i++)
        {
            //Find the elements contain part of string
            if( strcmp(arr[i],search) == 0)
            {
                printf("Found exactly : %s : at Element[%d] in the array.\n",search,i);
                searchFound ++;
            }
        }
        int count=0;
        //Relative search
        if(searchFound == 1)
        {
            break;
        }
        else
        {
            printf("====================================================\n");
            printf("Cannot find the exact value contained in this array \n");
            printf("====================================================\n");
            printf("Initializing the equivalent search ()\n");
            printf("====================================================\n");
            printf("Results of relative search: %s\n",search);
            char temp1[maxLength]; //saves the string after delete character (better relative search)
            char temp2[maxLength];
            char tempSearch1[maxElements][maxLength];
            char tempSearch2[maxElements][maxLength];
            del_character(search,temp1);
            del_character(search,temp2);
            lowercase(temp1);
            split_arr(temp1,tempSearch1);
            int countSearch = split_arr(temp1,tempSearch1); // Separate the input ranges for comparison////////
            split_arr(temp2,tempSearch2);
            for (int i=0; i<inputNumber; i++)
            {
                for (int j=0; j<countSearch; j++)
                {

                    if( strstr(arr1[i], tempSearch1[j]) != NULL)
                    {
                        printf("Element[%d] (may contain): %s\n",i,tempSearch2[j]);
                        count++;
                    }
                }
            }
            /////////////////////////////////////
            // Checks if it equals any of the above strings
            if (count>0)
            {
                //printf("Contain values: %s : that you have imported to search",search);
                break;
            }
            else
            {
                printf("Not contain values: %s : that you have imported to search \n",search);
            }
        }
        // Add element to array if it's not available yet
        if (searchFound == 0 && count == 0)
        {
            printf("Would you like to add this value here (y/n): ");
            char c;
            fflush(stdin);
            scanf("%c",&c);
            if (c == 'y' || c=='Y')
            {
                strcpy(arr[currentNumberElements],search);
                currentNumberElements++;
                printf("New element \ %s \ is added to array. \n",search);
                printf("New array are: \n");
                sortAllElements(currentNumberElements,arr);
                printAllElements(arr);
                break;
            }
        }
    }
}
