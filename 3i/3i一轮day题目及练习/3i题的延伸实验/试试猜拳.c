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
		
		printf("���ȭ(����0.ʯͷ1.��2.)..."); 
		scanf("%d",&ren);
		printf("robot��%d\n",robot);
		
		printf("sb=%d\n",sb);
		
		if(ren==1 && robot==0){
			
			printf("����������һ��...\n");
			a+=1;
			winren+=1;
		}
		if(ren==2 && robot==1){
			
			printf("����������һ��...\n");
			a+=1;
			winren+=1;
		}
		if(ren==0 && robot==2){
			
			printf("����������һ��...\n");
			a+=1;
			winren+=1;
		}
		if(ren==0 && robot==1){
			
			printf("��������...\n");
			a+=1;
			winrobot+=1;
		}
		if(ren==1 && robot==2){
			
			printf("��������...\n");
			a+=1;
			winrobot+=1;
		}
		if(ren==2 && robot==0){
			
			printf("��������...\n");
			a+=1;
			winrobot+=1;
		}
		
		if(winren==3){
			
			printf("��һ�ʤ,��Ϸ����...\n");
			break; 
		}
		if(winrobot==3){
			
			printf("robot��ʤ,��Ϸ����...\n");
			break; 
		}
	}
	return 0;
 } 
