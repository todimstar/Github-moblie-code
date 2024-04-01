#include<stdio.h>
int zhuan(char a,char b){
    int zhuan=0;
    zhuan=10*(a-'0')+(b-'0');
    return zhuan;
}
int main(){
    int n,i;
    char now[9];
    char gq[9];
    int nowi=0,gqi=0,sum,cot;
    scanf("%d",&n);
    scanf("%s",now);
    nowi=3600*(zhuan(now[0],now[1]))+60*(zhuan(now[3],now[4]))+zhuan(now[6],now[7]);
    
	printf("nowi=%d\n",nowi); 
	
    for(i=0;i<n;i++){
        gqi=0;cot=0;
        scanf("%s",gq);
        gqi=3600*(zhuan(gq[0],gq[1]))+60*(zhuan(gq[3],gq[4]))+zhuan(gq[6],gq[7]);
        
		printf("gqi=%d\n",gqi); // 
        
        printf("%d",nowi-gqi); 
        while(sum!=nowi){//因为这个循环结束不了 
            sum=gqi+1;
            cot++;
            
        }
        printf("sum=%d\ncot=%d",sum,cot);//所以想用累加来算但也碰不到nowi 
    }
    
    return 0;
}
