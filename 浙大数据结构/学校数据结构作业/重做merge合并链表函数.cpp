#include<iostream>

using namespace std;

struct List{
	int elem;
	List* Next;
};

bool inintList(List*& Head){
	
}

void MergeList(List* La,List* Lb){ //默认无头结点 
	List* Temp=NULL;
	while(La){
		if(Lb&&La->elem<=Lb->elem){
			Temp=La;
			La=La->Next;
			Temp->Next=Lb;
			Temp->Next->Next=La; // 恢复La链接 
			Lb=Lb->Next;
		}
	}while(Lb){ //如果Lb没摘完 
		if(Temp){ //防止La为空链表 
			Temp->Next=Lb;
			Temp=Lb;
			Lb=Lb->Next;
		}
	}
}


int main (){
	
	return 0;
}
