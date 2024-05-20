#include<iotream>

using namespace std;

#define VexsMax 100

struct GamPlayer{
	int uid=1000001;
	char name[7]="mihoyo";
};

typedef struct ArcNode{  //Arc弧，adj "adjacent"相邻的
	int adjvex;     			//弧指向的尾顶点在vexs的下标 
	struct ArcNode *nextarc;	//下一条弧 
	 
}ArcNode;

typedef struct VNode{  //V顶点 
	GamePalyer* data=NULL;	//数据的指针 
	ArcNode *firstarc=NULL;  //顶点指向的第一条边 
}VNode,Vexs[VexsMax];

struct ALGragh{
	Vexs//这会是指针吗 
};


int main (){
	
	
	
	return 0;
}
