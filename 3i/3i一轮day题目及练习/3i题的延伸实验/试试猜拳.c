#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
	int a=0;
	int winren=0;
	int winrobot=0;
	int robot;
	int ren;
	int sb;
	
	srand(time(NULL));
	robot=rand()%3;
	sb=rand()%10;
	
	while(a<=99){
		
		printf("请出拳(剪刀0.石头1.布2.)..."); 
		scanf("%d",&ren);
		printf("robot出%d\n",robot);
		
		printf("sb=%d\n",sb);
		
		if(ren==1 && robot==0){
			
			printf("六六，让你一局...\n");
			a+=1;
			winren+=1;
		}
		if(ren==2 && robot==1){
			
			printf("六六，让你一局...\n");
			a+=1;
			winren+=1;
		}
		if(ren==0 && robot==2){
			
			printf("六六，让你一局...\n");
			a+=1;
			winren+=1;
		}
		if(ren==0 && robot==1){
			
			printf("还得是朕...\n");
			a+=1;
			winrobot+=1;
		}
		if(ren==1 && robot==2){
			
			printf("还得是朕...\n");
			a+=1;
			winrobot+=1;
		}
		if(ren==2 && robot==0){
			
			printf("还得是朕...\n");
			a+=1;
			winrobot+=1;
		}
		
		if(winren==3){
			
			printf("玩家获胜,游戏结束...\n");
			break; 
		}
		if(winrobot==3){
			
			printf("robot获胜,游戏结束...\n");
			break; 
		}
	}
	return 0;
 } 
