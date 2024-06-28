#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct point{
	int x,y;
}a[4];

double d[6];

int qf(){
	double p1,p2,s1,s2;
    p1=(d[0]+d[1]+d[2])/2;p2=(d[3]+d[4]+d[5])/2;
    s1=sqrt(p1*(p1-d[0])*(p1-d[1])*(p1-d[2]));s2=sqrt(p2*(p2-d[3])*(p2-d[4])*(p2-d[5]));
    if(s1>s2)return 0;
    else if(s1<s2)return 2;
    else return 1;
    
}


int main (){
	
	char str[][8]={"Alice","Draw","100kg"};
	
	scanf("%d %d",&a[0].x,&a[0].y);
	for(int i=1;i<4;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	d[0]=sqrt((a[4].x-a[0].x)*(a[4].x-a[0].x)+(a[4].y-a[0].y)*(a[4].y-a[0].y));
	d[1]=sqrt((a[4].x-a[2].x)*(a[4].x-a[2].x)+(a[4].y-a[2].y)*(a[4].y-a[2].y));
	d[2]=sqrt((a[2].x-a[0].x)*(a[2].x-a[0].x)+(a[2].y-a[0].y)*(a[2].y-a[0].y));
	d[3]=sqrt((a[4].x-a[3].x)*(a[4].x-a[3].x)+(a[4].y-a[3].y)*(a[4].y-a[3].y));
	d[4]=sqrt((a[3].x-a[1].x)*(a[3].x-a[1].x)+(a[3].y-a[1].y)*(a[3].y-a[1].y));
	d[5]=sqrt((a[1].x-a[4].x)*(a[1].x-a[4].x)+(a[1].y-a[4].y)*(a[1].y-a[4].y));
	
	
	cout<<str[qf()];
	
	return 0;
}




