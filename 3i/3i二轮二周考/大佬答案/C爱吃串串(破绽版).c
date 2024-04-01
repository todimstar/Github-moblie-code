#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100] = "0";
    scanf("%s",arr);
    int len = 0;
    int i = 0;
    int sum1 = 0;
    int sum2 = 0;
    len = strlen(arr);
    if(len%2!=0)
    {
        printf("That's too bad\n");
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(arr[i]=='a')
            {
                sum1++;
            }
            else if(arr[i]=='b')
            {
                sum2++;
            }
        }
        if(sum1==sum2)
        {
            printf("Nice bro\n");
        }
    }
    return 0;
}
