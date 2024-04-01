#include<stdio.h>
int gcd(int x,int y){
    int t;
    while(y){//2024.2.18,gcd防y=0复习   //2024.2.29 -->还得是while(y)才能防止 gcd(n,0)出现n%0无法计算情况,完全胜利! 
		t=x%y;
		x=y;
		y=t;
	}
    /*while(t!=0){
        t=x%y;
        x=y;
        y=t;
    }*/
    return x;
}
int main (){
    int x1,y1,xx1,yy1;
    int x2,y2,xx2,g;
    printf("%d",gcd(1,0));
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    
    xx1=x1;yy1=y1;xx2=x2;
    if(y1==y2){
        x1+=x2;
        g=gcd(x1,y1);
        printf("%d %d\n",x1/g,y1/g);
        
        x1-=x2;
        x1-=x2;
        g=gcd(x1,y1);
        printf("%d %d\n",x1/g,y1/g);
        
        x1+=x2;
        x1*=x2;
        y1*=y2;
        g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
		
        y1/=y2;
        x1/=x2;
        x1*=y2;
        y1*=x2;
        g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
        
    }
    else{
        y1*=y2;
        x2*=y1;
        x1*=y2;
        x1+=x2;
        g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
        
        x1-=2*x2;
		g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
		
        x1=xx1;x2=xx2;
        x1*=x2;
        g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
		
        x1=xx1;y1=yy1;
        x1*=y2;
        y1*=x2;
        g=gcd(x1,y1);
		printf("%d %d\n",x1/g,y1/g);
    }
    
    return 0;
}
