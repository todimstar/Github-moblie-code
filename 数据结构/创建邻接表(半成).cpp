#include<iostream>
#include<string>
using namespace std;

class GamePlayer {
	public:
	static int uid = 1000000;//static使每个Player的uid不同 
	string name = "mihoyo";//string 初始化问题 
	//各函数默认
	void ScanGamePlayer(){
		cin>>name;
		uid++;
	}
};


#define VexsMax 100

typedef struct ArcNode{  //Arc弧，adj "adjacent"相邻的
	int adjvex;     			//弧指向的尾顶点在vexs的下标 
	struct ArcNode *nextarc;	//下一条弧 
	 
}ArcNode;

typedef struct VNode{  //V顶点 
	GamePlayer data;	//数据的指针 
	ArcNode *firstarc=NULL;  //顶点指向的第一条边 
}VNode,Vexs[VexsMax];

struct ALGraph{		 
	Vexs arr;		//依书上说,这会是指针吗 
	int vexsnum=0;	//相关数量
	int arcnodenum=0; //相关数量
};


int localvex(ALGraph &G,string p){
	int i,num=G.vexsnum;
	for(i=0;i<num;i++){
		if(G.arr[i].data.name==p)return i;
	}return -1;
}

bool CreateALGraph(ALGraph &G) {
	int i;
	if (!G.vexsnum) {
		cout << "请完善图信息...\n图总节点数：";
		cin >> G.vexsnum;
		cout << "\n图弧\\边总数：";
		cin >> G.arcnodenum;
	}
	int num = G.vexsnum;
	for (i = 0; i < num; i++) {
		printf("uid:%d的角色名(6位内): ",G.arr[i].data.uid);
		G.arr[i].data.ScanGamePlayer();
	}
	//节点数组完成
	num=G.arcnodenum;
	string p1,p2;
	int l1,l2;
	for(i = 0; i < num; i++){
		cout<<"边:" ;
		cin>>p1>>p2;
		cout<<'\n';
		l1=localvex(G,p1);
		l2=localvex(G,p2);
		if(l1!=-1&&l2!=-1){	//若有向图则一次便可 
			ArcNode* a=new ArcNode;
			a->adjvex=l2;
			a->nextarc=G.arr[l1].firstarc;
			G.arr[l1].firstarc=a;
		}
		
		
	}
	return true;
}

int PrintALGraph(const ALGraph& G){
	
}


int main (){
	
	ALGraph f1;
	CreateALGraph(f1);
	PrintALGraph(f1);
	
	return 0;
}
