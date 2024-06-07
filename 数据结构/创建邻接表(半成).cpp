#include<iostream>
#include<string>
using namespace std;

class GamePlayer {
	public:
	static int uid = 1000000;//staticʹÿ��Player��uid��ͬ 
	string name = "mihoyo";//string ��ʼ������ 
	//������Ĭ��
	void ScanGamePlayer(){
		cin>>name;
		uid++;
	}
};


#define VexsMax 100

typedef struct ArcNode{  //Arc����adj "adjacent"���ڵ�
	int adjvex;     			//��ָ���β������vexs���±� 
	struct ArcNode *nextarc;	//��һ���� 
	 
}ArcNode;

typedef struct VNode{  //V���� 
	GamePlayer data;	//���ݵ�ָ�� 
	ArcNode *firstarc=NULL;  //����ָ��ĵ�һ���� 
}VNode,Vexs[VexsMax];

struct ALGraph{		 
	Vexs arr;		//������˵,�����ָ���� 
	int vexsnum=0;	//�������
	int arcnodenum=0; //�������
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
		cout << "������ͼ��Ϣ...\nͼ�ܽڵ�����";
		cin >> G.vexsnum;
		cout << "\nͼ��\\��������";
		cin >> G.arcnodenum;
	}
	int num = G.vexsnum;
	for (i = 0; i < num; i++) {
		printf("uid:%d�Ľ�ɫ��(6λ��): ",G.arr[i].data.uid);
		G.arr[i].data.ScanGamePlayer();
	}
	//�ڵ��������
	num=G.arcnodenum;
	string p1,p2;
	int l1,l2;
	for(i = 0; i < num; i++){
		cout<<"��:" ;
		cin>>p1>>p2;
		cout<<'\n';
		l1=localvex(G,p1);
		l2=localvex(G,p2);
		if(l1!=-1&&l2!=-1){	//������ͼ��һ�α�� 
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
