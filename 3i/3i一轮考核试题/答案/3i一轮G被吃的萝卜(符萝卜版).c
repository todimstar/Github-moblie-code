#include<stdio.h>
int main()
{
    int n,i,j,t;
    int q[1001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
 
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)//为啥要这样？ 
        {
            if(q[i]>q[j])
            {
                t=q[i];
                q[i]=q[j];
                q[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }   
    return 0;
}
