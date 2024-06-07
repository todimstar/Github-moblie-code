#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
	int x;int y;
}p;
int main (){
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	p p1[m],p2[n];
	for(i=0;i<m;i++){
		scanf("%d",&p1[i].x);
	}for(i=0;i<m;i++){
		scanf("%d",&p1[i].y);
	}for(i=0;i<n;i++){
		scanf("%d",&p2[i].x);
	}for(i=0;i<n;i++){
		scanf("%d",&p2[i].y);
	}
	int mm,nn;
	nn=m>=n?n:m;mm=m>=n?m:n;
	double d=0;
	for(i=0;i<nn;i++){
		for(j=0;j<mm;j++){
			d=(p1[i].x-p2[i].x)*(p1[i].x-p2[i].x)-(p1[i].y-p2[i].y)*(p1[i].y-p2[i].y);
			if(d>=10){while(1);}
		}
	}printf("%d",nn);
	return 0;
}
