#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int main(){
	int shiyan[]={1,2,3,4,5},i;
		
		srand(time(NULL));
		
		for(i=0;i<=5;i++){
			shiyan[i]=rand()%999;
			printf("shiyan[]=%s",shiyan); //���û����������+1 
		}
	
	
	
	return 0;
} 
