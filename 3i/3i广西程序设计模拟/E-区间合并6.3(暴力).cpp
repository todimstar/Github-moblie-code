#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10
typedef struct a{
    int l,r;
}a;


int main (){
	int n,i,j,cot=0;
    
	scanf("%d",&n);
    a q[n];
    bool flag[n];
    for(i=0;i<n;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        flag[i]=true;
    }
    
	for(i=0;i<n;i++){
	    if(flag[i]){
		    for(j=i+1;j<n;j++){
		        if(flag[j]){
		            if(q[i].r>=q[j].l){
		                if(q[j].r>=q[i].r){
			                q[i].r=q[j].r;
			                flag[j]=false;
			                if(q[j].l<q[i].l){
			                   	q[i].l=q[j].l;
							}
		                }
		                    
		            }
		                
		        }
		    }
		        
		}
	}
	for(i=0;i<n;i++){
		    if(flag[i]){
			    for(j=i+1;j<n;j++){
			        if(flag[j]){
			            if(q[j].r<q[i].r){
							flag[j]=false;
						}   
			        }
			    }
			        
			}
		}
    
    
    
    for(i=0;i<n;i++){
        if(flag[i])cot++;
    }
    printf("%d",cot);
	
	return 0;
}
