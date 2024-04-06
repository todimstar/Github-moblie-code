#include<iostream>
#include<string.h>
//牛客二分算法[NOIP2012]借教室
using namespace std;

/*int main (){
    int n,m,i;
    scanf("%d %d",&n,&m);
    int day_room[n];
    int d,s,t,j;
    for(i=1;i<=n;i++){
        scanf("%d",&day_room[i]);
    }for(i=1;i<=m;i++){
        scanf("%d %d %d",&d,&s,&t);
        for(j=s;j<=t;j++){
            day_room[j]-=d;
            if(day_room[j]<0){
                printf("-1\n%d",i);
                return 0;
            }
        }
    }printf("0");

    return 0;
}*///暴力会超时,因为有10^6

//int perfix[1000009], room[1000009], d[1000009], s[1000009], t[1000009];

int m,n;//     唯有perfix会有更改所以不const 
bool perfix_check(int* perfix,const int room[],const int d[],const int s[],const int t[],int mid) {
	int i;
	for(i=1;i<=mid;i++){
		perfix[s[i]]+=d[i];
		perfix[t[i]+1]-=d[i];
	}//手法:使s[i]位教室借用，使t[i]+1位教室归还; 
	//这也算差分么，感觉只是个处理手段罢了 
	for(i=1;i<=n;i++){
		perfix[i]+=perfix[i-1];//前缀和
		if(perfix[i]>room[i])return false; 
	} return true;
}


int main () {
	int i;
	scanf("%d %d", &n, &m);
	int room[n+1],d[m+1], s[m+1], t[m+1];
	int perfix[n+2];
	for (i = 1; i <= n; i++) {
		scanf("%d", &room[i]);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &d[i], &s[i], &t[i]);
	}
	int l=1,r=m+1,mid;//    why????? why?r=m的边界才对 //哈哈哈哈哈,在问文言一心码字的时候发现边界l==m时最后退出循环l==m+1==r，哈哈所以只要再把这个特例算进最后的输出里就行O(∩_∩)O哈哈~ 
	while(l<r){ //若是l<=r,则下面r=mid-1; 
		memset(perfix,0,sizeof(perfix));
		mid=l+(r-l)/2;
		if(perfix_check(perfix,room,d,s,t,mid))l=mid+1;//往右边界找 
		else r=mid;
	}
	if(l==m||l==m+1)printf("0");//  当然也可以l>=m;不过||的话只有前一个不符合才判断第二个，感觉是不是就不用重载>=符了就会快点?哈哈 
	else printf("-1\n%d",l);
	return 0;
}
