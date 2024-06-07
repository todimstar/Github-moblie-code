#include<stdio.h>
#include <stdlib.h>
#include <time.h>

	#include <random>  

	#include <ctime>  
	// 创建一个随机数引擎，这里使用默认的随机数引擎（一般是mt19937，即Mersenne Twister算法）  
		
	std::default_random_engine generator(static_cast<unsigned int>(std::time(nullptr)));  
		
			  
		
			// 创建一个均匀分布，用于生成在指定范围内的随机数  
		
	

void maopao(int a[],int len);	//==冒泡== 
void xuanze(int a[],int len);	//==选择== 
void suiji(int a[],int len);	//==随机数组生成== 
void myinset(int a[],int len);	//my插入排序 
void inset(int a[],int len);	//插入排序 
void mykuaipai(int a[],int len);//my快排 
void quickSort(int a[],int left,int right);//快排一
 
 void MyQuickSort(int nums[], int left,int right);
 int partition(int nums[], int left,int right);
 void swap(int nums[], int l,int r);



int main (){
	
	int n,i;
	scanf("%d",&n);
	int a[n];
	suiji(a,n);//========自动挡 
	/*for(i=0;i<n;i++){
		scanf("%d",&a[i]);//手动挡 
	}*/
	printf("随机生成的是:"); 
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	quickSort(a,0,n-1);
	printf("函数排序之后的是:"); 
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

void quickSort(int a[],int left,int right){
	if(left>=right)return;
	
	/*std::uniform_int_distribution<int> distribution(left, right); // left和right是随机数的范围  
		  
	
		// 生成一个随机数  
	
	int random_number = distribution(generator);*/
	srand((unsigned)time(NULL));
	int random_number=rand()%(right-left+1)+left;
	
	int i=left;
	int j=right;
	int pivot=a[random_number];
	a[random_number]=a[i];
	a[i]=pivot;
	while(i<j){
		while(i<j&&a[j]>=pivot)j--;
		a[i]=a[j];
		while(i<j&&a[i]<=pivot)i++;
		a[j]=a[i];
	}
	a[i]=pivot;//这是原来的算法有的，也许有冲突了这样 
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}



void mykuaipai(int a[],int len){
	if(len==1)return;
	int i=0,j;
	int pivot;
	pivot=a[0];
	for(j=len;j>=0;j--){
		if(a[j]<pivot){
			a[0]=a[j];
			break;
		}
	}
	for(i=1;i<=j;i++){
		if(a[i]>pivot){
			a[j]=a[i];
			break;
		}
	}
	for(;j>=i;j--){
		if(j==i){
			a[j]=pivot;
			break;
		}
	}
	int la[j];
	for(i=0;i<j;i++){
		la[i]=a[i];
	}
	mykuaipai(la,j);
	int ra[len-j-1];
	for(i=0;i<len-j-1;i++){
		ra[i]=a[j+1+i];
	}
	mykuaipai(ra,len-j-1);
	
}

/*Random random =new Random();//随机数? 
void swap(int nums[], int l,int r){
	int temp=nums[l];
	nums[l]=nums[r];
	nums[r]=temp;
}

int partition(int nums[], int left,int right){//分区 
	int len=right-left+1;
	int j=random.nextInt(len)+left;
	swap(nums,j,right); 

	int pivot=nums[right];//必须是nums的最后一位且right须是最后一位的下标???不是可以随机化吗 
	
	int fast=left,slow=left;
	while(fast<right) {		//快指针到right头就停 
		if(nums[fast]<pivot){//出现不该出现在右边的数就换走 
			swap(nums,fast,slow);
			slow++;
		}
		fast++;
	}
	swap(nums,slow,right);
	return slow; 
} 

void MyQuickSort(int nums[], int left,int right){//遍历二叉树 
	if(left>=right)return;
	//分区
	int j=partition(nums,left,right);
	
	MyQuickSort(nums,left,j-1); //左分区
	MyQuickSort(nums,j+1,right);//右分区 
}
*/


void inset(int a[],int len){
	int i,j,t;
	int count=0; 
	for(i=1;i<len;i++){
		for(j=i;j>=1 && a[j]<a[j-1];j--){count++;
			t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
		}
	}
	printf("其count=%d",count);
}



void myinset(int a[],int len){
	int i,j,t;
	int count=0;
	for(i=0;i<len-1;i++){//==先从前开始一个个看有没有前大于后的 
		
		//if(a[i]>a[i+1]){//这判断好像重复或者说那啥 
			for(j=i+1;j>0;j--){//==若有则把该数往前对比，前数大于它就换位，直至不大于它 
				if(a[j]<a[j-1]){count++;
					t=a[j-1];
					a[j-1]=a[j];
					a[j]=t;
				}
				//else{
					//break;//==他的好像跟我不太一样,wc我的竟然没排好... 
				}
			}
		printf("其count=%d",count);
	}




void suiji(int a[],int len){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<len;i++){
	    a[i]=rand()%len;
	}
}


void xuanze(int a[],int len){//==选择排序对于较有序的的数组会做很多无用功，目前感觉时间复杂度最大的排序算法 
	int i,j,k,t;
	for(i=0;i<len;i++){//==i<len-1;就能少走一点点，虽然<len最后j也会因为j=len走掉;所以几乎差不多 
		k=i;
		for(j=i+1;j<len;j++){
			if(a[j]<a[k]){
				k=j;
			} 
		}
		t=a[i];
		a[i]=a[k];
		a[k]=t;
	} 
}



void maopao(int a[],int len){//==优化后的冒泡倒是自我感觉良好捏,连基本有序的时候都跟插入排序一样次数 666; 
	int flag=1,i,t;int count=0;
	while(len-- && flag){
		flag=0;
		for(i=0;i<len;i++){
			if(a[i]>a[i+1]){//顺序前小后大 
				flag=1;count++;
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
		printf("其count=%d",count);
	}
	
} 
