#include<iotream>

using namespace std;

#define VexsMax 100

struct GamPlayer{
	int uid=1000001;
	char name[7]="mihoyo";
};

typedef struct ArcNode{  //Arc����adj "adjacent"���ڵ�
	int adjvex;     			//��ָ���β������vexs���±� 
	struct ArcNode *nextarc;	//��һ���� 
	 
}ArcNode;

typedef struct VNode{  //V���� 
	GamePalyer* data=NULL;	//���ݵ�ָ�� 
	ArcNode *firstarc=NULL;  //����ָ��ĵ�һ���� 
}VNode,Vexs[VexsMax];

struct ALGragh{
	Vexs//�����ָ���� 
};


int main (){
	
	
	
	return 0;
}
