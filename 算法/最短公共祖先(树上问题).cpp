//  并查集知乎：https://www.zhihu.com/column/c_1182444932760125440
//  佬的目录：https://zhuanlan.zhihu.com/p/105467597 

#include<iostream>

//using namespace std;

#define MAX 5005

//  c++std有个rank模板会重名的 
int fa[MAX],rank[MAX];//fa数组是存储当前节点的上级，rank数组存储当前根节点的深度 

void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rank[i]=1;
	}
}
//  使用路径压缩缩减了原本长路程的简单版并查集 升级为正常版 
int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));//  递归找上级并且压缩了路径
	//  直到找到fa[x]就是x的,即根节点 就返回x:再通过fa[x]递归，并把结果赋给fa[x]，即可实现压缩路径 
}
//  使用按秩合并 升级为极速版 
void mager(int x,int y){
	x=find(x);y=find(y);// 找到根节点 
	if(rank[x]<=rank[y]){
		fa[x]=y;// 让x的祖先臣服于y; 正常版只用到这一步就行 
	}else fa[y]=x;
	if(rank[x]==rank[y]&&x!=y){//  符合条件的都是臣服与y的x,同时xy深度相等且不同源,让胜者的深度+1 
		rank[y]++;
	}
	
} 

int main (){
	int n,m,p,i;
	std::cin>>n>>m>>p;
	int x,y;
	init(n);
	for(i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		mager(x,y);
	}
	while(p--){
		std::cin>>x>>y;
		printf("%s\n",find(x)==find(y)?"Yes":"No");
	} 
	
	
	return 0;
} 
