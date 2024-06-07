#include<iostream>

using namespace std;

struct a{
    //int num;
    bool s=false;
    bool e=false;
    int stime;
    int etime;
    int sday;
    int eday;
}book[1001];

//int zhuan(char a)return a-'0';

int main (){
    int n,cot=0,num,tim=0;
    int ci=0,time,sumtime=0,prtime;
    char b[11];//吐，开的时候没考虑到\n开太极限了fgets就没读入\n,导致之后行内存泄漏 
    //int ch[1001];
    //bool flag=true;
    cin>>n;getchar();
    while(fgets(b,sizeof(b),stdin)!=NULL){//  fgets输入特点:1.(char* str,int n,fp/stdin) 2.读到n位或者遇到EOF,所以内存够就能收\n 3.返回值为指针 
		num=b[0]-'0';
        //tim=tim<=((b[4]-'0')*10+b[5]-'0')?((b[4]-'0')*10+b[5]-'0'):0;//吐咯，题目说管理员自动换天不用自己算哈哈 
        if(b[0]=='0'){
	        if(ci>0){
		        //int t=sumtime%ci;
                printf("%d %d\n",ci,(int)(1.0 * sumtime / ci + 0.5));
		        //printf("%d %d\n",ci,t==0?sumtime/ci:(sumtime/ci)+1);
	        }else printf("0 0\n");
	        if(--n==0)return 0; 
		ci=0;sumtime=0;
        continue;
		}
        if(b[2]=='S'){
        	if(!book[num].s){//保证只能被借一次 
	            book[num].s=true;
	            book[num].stime=((b[4]-'0')*10+b[5]-'0')*60+((b[7]-'0')*10+b[8]-'0');
	            book[num].sday=n;
        	}else{
                book[num].stime=((b[4]-'0')*10+b[5]-'0')*60+((b[7]-'0')*10+b[8]-'0');
	            book[num].sday=n;
            }
        }
        else {
        	if(book[num].s){//被借才有还 
            	book[num].e=true;
                book[num].etime=((b[4]-'0')*10+b[5]-'0')*60+((b[7]-'0')*10+b[8]-'0');
                book[num].eday=n;
                //ch[cot++]=num;
                //怎么没把状态清零
				book[num].s=false;
				book[num].e=false; 
                
				int a=book[num].sday-book[num].eday;
				
				if(a==0){//没跨天
					ci++;
					time=book[num].etime-book[num].stime;
					sumtime+=time;
				}/*else {
					if(a==1){// 没有对a<0检查，不知道会不会有隐患
					time=book[num].etime+((60*24)-book[num].stime);
						sumtime+=time;
					}
					else{// a>1,跨了不止一天
						time=book[num].etime+((60*24)*(a-1)-book[num].stime);
						sumtime+=time;
					}
				}*///离谱，想自己上强度题目不给哈哈 
            }
        }
        /*for(int i=0;i<cot;i++){
			int c=ch[i];
			if(book[c].s&&book[c].e){
			}
		}*/
    }//printf("%d %d\n",ci,sumtime);哈哈这也不用，因为管理员告诉了要几天 
    
    return 0;
}
