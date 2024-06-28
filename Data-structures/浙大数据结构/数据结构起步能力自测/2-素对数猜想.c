#include<stdio.h>
#include<time.h>

clock_t start,stop;
double ttime;
int p[10000];

int main (){
	int n,i,d=0,j,cot=1;
	scanf("%d",&n);
	start=clock();p[0]=2;
	for(i=3;i<=n;i+=2){//素数只有奇数，除了2而这又用不到2 
		for(j=2;j*j<=i;j++){//只到sqrt(i)不用到i/2更快了 
			if(i%j==0){j=-1;break;}
		}if(!(j==-1)){p[cot++]=i;}
	}for(i=1;i<cot;i++){
		if(p[i]-p[i-1]==2)d++;
	}
	printf("%d",d);
	stop=clock();
	ttime=((double)(stop-start))/CLK_TCK;
	printf("\ntime=%fs",ttime);
	return 0;
} 
