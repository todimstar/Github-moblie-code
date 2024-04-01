#include<stdio.h>
int main(){
    int i,n,x,q;
    int c=0;
    int sb=0;
    scanf("%d %d",&n,&x);
    
    for(i=1;i<=n;i++)
	{
        for(q=i;q>0;q=q/10)
		{
            if(q%10==x)
			{
                c+=1;
            }

		}
    }
    printf("%d",c);
    
    return 0;
}
