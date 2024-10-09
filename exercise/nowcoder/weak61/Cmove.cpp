#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;

int combination(int m,int n){	//算组合数combination，从n中选k个数 
	int nj=1,mj=1,n_mj=1; 
	
	for(int i=2;i<=n;i++){
		nj*=i;
	}for(int i=2;i<=m;i++){
		mj*=i;
	}for(int i=2;i<=n-m;i++)n_mj*=i;
	
	return nj/(mj*n_mj);
}

string delstr(string &s,char ad){		//如何快速删除字符串中一字符并保持原相对位置 
	size_t i=0;
	for(;i<s.size();i++){
		if(s[i]==ad){	//现在想法是裁剪后拼接，但可能会浪费性能与空间 
			break; 
		}
	}return s.substr(0,i)+s.substr(i+1);
}


int main (){
	int T,n,x,y;
	string s;
    int tx,ty;
	
	cin>>T;
	while(T--){
		
        //int way=0;	//最终的方法数		 
        tx=0;ty=0;
        int L=0,R=0,U=0,D=0;

		scanf("%d %d %d",&n,&x,&y);
		cin>>s;
        //if(x==0 && y==0)way++;  //全删有一法 

        for(int i=0;i<s.size();i++){    //在去到给定位置同时存上下左右个数
            if(s[i]=='L'){
                ty--;
                L++;
            }
            else if(s[i]=='R'){
                ty++;
                R++;
            }
            else if(s[i]=='U'){
                tx++;
                U++;
            }
            else if(s[i]=='D'){
                tx--;
                D++;
            }
        }
        
		// if(tx==x && ty==y){
        //     cout<<"YES "<<s;
        //     if(x==0&y==0)
        // }
        
        int dx=tx-x,dy=ty-y;    //用完全部超了多少 
        int tL=L,tR=R,tU=U,tD=D;
        int delL=0,delR=0,delU=0,delD=0;	//删了的计数，方便后面对删了的组合输出方法数 
        //cout<<"start: dx="<<dx<<"dy="<<dy<<endl;
        
        while(dx){
            if(dx>0 && tU>0){//超了x行，删U 
				dx--;tU--;	//删U 
				s = delstr(s,'U');
				delU++;
			} 
            else if(dx<0 && tD>0){//超了-x行，删D
                dx++;tD--;
                s = delstr(s,'D');
                delD++;
            }
            else{
                break;	//要么dx==0竖直方向可以到达，要么D,U无力dx!=0 最后判断便知 
            }
        }
        while(dy){
            if(dy>0 && tR>0){	//超了dy列，删R 
                dy--;tR--;
                s = delstr(s,'R');
                delR++;
            }else if(dy<0 && tL>0){
                dy++;tL--;
                s = delstr(s,'L');
                delL++;
            }
            else{
                break;
            }
        }//cout<<"End: dx="<<dx<<"dy="<<dy<<endl;
        		
        if(!dx && !dy){
        	int cnt=0;		//最终的方法数
        	if(delL>0)cnt+=combination(delL,L);
        	if(delR>0)cnt+=combination(delR,R);
        	if(delU>0)cnt+=combination(delU,U);
        	if(delD>0)cnt+=combination(delD,D);
            cout<<"YES "+s+" "<<cnt<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        

	}
	
	return 0;
}
