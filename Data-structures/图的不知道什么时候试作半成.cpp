#include<iotream>

using namespace std;

struct GamPlayer {
	int uid = 1000001;
	char name[7] = "mihoyo";
};

#define VexsMax 100

typedef struct ArcNode{  //Arc弧，adj "adjacent"相邻的
	int adjvex;     			//弧指向的尾顶点在vexs的下标 
	struct ArcNode *nextarc;	//下一条弧 
	 
}ArcNode;

typedef struct VNode{  //V顶点 
	GamePalyer* data=NULL;	//数据的指针 
	ArcNode *firstarc=NULL;  //顶点指向的第一条边 
}VNode,Vexs[VexsMax];

struct ALGragh{
	Vexs arr;		//依书上说,这会是指针吗 
	int vexsnum=0;	//相关数量
	int arcnodenum=0; //相关数量
};


CreateALGraph(ALGraph* G) {
	int i;
	if (!G.vexsnum) {
		cout << "请完善图信息...\n图总节点数：";
		cin >> G.vexsnum;
		cout << "\n图弧\\边总数：";
		cin >> G.arcnodenum;
	}
	int num = G.vexsnum;
	for (i = 0; i < num; i++) {
		cin>>G.arr[i].
	}
}


int main (){
	
	ALGraph f1;
	CreateALGraph(f1);
	
	return 0;
}
