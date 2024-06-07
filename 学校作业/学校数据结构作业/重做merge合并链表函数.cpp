#include<iostream>

using namespace std;

struct List{
	int elem;
	List* Next;
};

/*bool inintList(List*& Head){
	
}*/

List* MergeList(List* La,List* Lb){ //默认无头结点 
	List* Temp=NULL;
	if(La&&Lb){
		La=La->elem<=Lb->elem?La:Lb; //保La头最小 
		Temp=La;//首个必定不头插 
		La=La->Next;
		while(La){
			if(Lb&&La->elem>Lb->elem){ //设<为保当La前有一个时才头插,=的情况等下一个或者等Lb尾插 
				//用头插?这是啥插??? 
				Temp->Next=Lb;
				Lb=Lb->Next;
				Temp->Next->Next=La;
			}
			Temp=La; //留种 
			La=La->Next;
		} 
		while(Lb){
			Temp->Next=Lb; //这时Temp是La尾指针,且LaLb都存在
			Lb=Lb->Next; 
		}
		return La;
	}else if(La)return La;
	else if(Lb)return Lb;
	else return La;
	/*while(La){
		if(Lb){
			Temp=La; //留前驱 
			if(La->elem>=Lb->elem){
				Temp=La->Next;
				
								
				La=La->Next;
				Temp->Next=Lb;
				Temp->Next->Next=La; // 恢复La链接 
				Lb=Lb->Next; //这是头插尾插??? 
			}
			else La=La->Next;
		}
	}while(Lb){ //如果Lb没摘完 
		if(Temp){ //防止La为空链表 
			Temp->Next=Lb;
			Temp=Lb;
			Lb=Lb->Next;
		}
	}*/
}


int main (){
	
	return 0;
}