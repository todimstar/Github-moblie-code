#include<stdio.h>

//using namespace std;
int lq[30][20]; 

long long pdd(int i,int j){
	int a,b;
	long long tmax=0;
	for(a=i;a<i+5;a++){
		for(b=j;b<j+5;b++){
			tmax+=lq[a][b];
		}
	}return tmax;
}

int main (){
	int i,j;
	for(i=0;i<30;i++){
		for(j=0;j<20;j++)scanf("%d",&lq[i][j]);
	}
	long long max=0,t;
	for(i=0;i+5<30;i++){
		for(j=0;j+5<20;j++){
			t=pdd(i,j);
			if(max<t)max=t;
		}
	}
	
	printf("%ld",max);//171248
	return 0;
}
