//  ���鼯֪����https://www.zhihu.com/column/c_1182444932760125440
//  �е�Ŀ¼��https://zhuanlan.zhihu.com/p/105467597 

#include<iostream>

//using namespace std;

#define MAX 5005

//  c++std�и�rankģ��������� 
int fa[MAX],rank[MAX];//fa�����Ǵ洢��ǰ�ڵ���ϼ���rank����洢��ǰ���ڵ����� 

void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rank[i]=1;
	}
}
//  ʹ��·��ѹ��������ԭ����·�̵ļ򵥰沢�鼯 ����Ϊ������ 
int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));//  �ݹ����ϼ�����ѹ����·��
	//  ֱ���ҵ�fa[x]����x��,�����ڵ� �ͷ���x:��ͨ��fa[x]�ݹ飬���ѽ������fa[x]������ʵ��ѹ��·�� 
}
//  ʹ�ð��Ⱥϲ� ����Ϊ���ٰ� 
void mager(int x,int y){
	x=find(x);y=find(y);// �ҵ����ڵ� 
	if(rank[x]<=rank[y]){
		fa[x]=y;// ��x�����ȳ�����y; ������ֻ�õ���һ������ 
	}else fa[y]=x;
	if(rank[x]==rank[y]&&x!=y){//  ���������Ķ��ǳ�����y��x,ͬʱxy�������Ҳ�ͬԴ,��ʤ�ߵ����+1 
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
