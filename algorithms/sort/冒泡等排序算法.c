#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void maopao(int a[],int len);	//==冒泡== 实验量大起来冒泡就最慢了
void xuanze(int a[],int len);	//==选择== 选择第二慢
void suiji(int a[],int len);	//==随机数组生成== 
void myinset(int a[],int len);	//my插入排序 
void inset(int a[],int len);	//插入排序 插入确实在冒泡选择插入里最快
void mykuaipai(int a[],int len);//my快排 
void quickSort(int a[],int left,int right);//快排一
 
void MyQuickSort(int nums[], int left,int right);
int partition(int nums[], int left,int right);
void swap(int nums[], int l,int r);


/*
void zhi_cha_paixu(int arr[], int n)
{	clock_t start1 = clock();
    printf("进入直插%ld\n",start1);
    int j, key;
    for (int i = 1; i < n; i++) // 除了第一个都是未排序区
    {
        key = arr[i]; // 记录第i个数据
        j = i - 1; // i前一个数据
        while (j >= 0 && arr[j] > key)
        {
            //compare_count++; // 增加比较次数
            arr[j + 1] = arr[j]; // 将大于key的元素向后移动
            //move_count++; // 增加移动次数
            j = j - 1;
        }
        arr[j + 1] = key; // 将key放入正确位置
        //move_count++; // 增加移动次数
    }
    clock_t end1 = clock();
	printf("结束直插%ld\n使用时间为%lf\n",end1,(double)end1-start1);
}
//找数组的最大值
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countSort(int arr[], int n, int exp)
{
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = { 0 };
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}
void ji_shu_paixu(int arr[], int n)
{	clock_t start1 = clock();
	    printf("进入jishu%lf\n",start1);
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
    clock_t end1 = clock();
	printf("结束jishu%ld\n使用时间为%lf\n",end1,(double)end1-start1);
}
*/

int main (){
	
	int n,i;
	scanf("%d",&n);
	int a[n],b[n],c[n];
	suiji(a,n);//========自动挡 
	/*for(i=0;i<n;i++){
		scanf("%d",&a[i]);//手动挡 
	}*/
	printf("随机生成的是:"); 
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
		b[i]=a[i];
		c[i]=a[i];
	}
	zhi_cha_paixu(a,n);
	ji_shu_paixu(b,n);
	printf("\n");
	clock_t begin1 = clock();
	printf("%ld\n",begin1);
	maopao(a,n);
	clock_t end1 = clock();
	printf("%ld\n",end1);
	double duration1 = (end1 - begin1);
	printf("maopao函数耗时=%lf\n排序之后的是:",duration1); 
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	clock_t begin2 = clock();
	inset(b,n);
	clock_t end2 = clock();
	double duration2 = (end2 - begin2);
	printf("inset函数耗时=%lf\n排序之后的是:",duration2); 
	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	clock_t begin3 = clock();
	xuanze(c,n);
	clock_t end3 = clock();
	double duration3 = (end3 - begin3);
	printf("xuanze函数耗时=%lf\n排序之后的是:",duration3); 
	for(i=0;i<n;i++){
		printf("%d ",c[i]);
	}
	
	return 0;
}

void quickSort(int a[],int left,int right){
	if(left==right)return;
	
	//Random random=new Random();
	int i=left;
	int j=right;
	int pivot=a[i];
	while(i<j){
		while(i<j&&a[j]>=pivot)j--;
		a[i]=a[j];//感觉可以等到都查完再换ij 
		while(i<j&&a[i]<=pivot)i++;
		a[j]=a[i];
	}
	a[i]=pivot;
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



void inset(int a[],int len){
	int i,j,t;
	int count=0,cntwai=0,cntnei=0; 
	for(i=1;i<len;i++){
		t=a[i];cntwai++;
		for(j=i;j>=1 && /*a[j]*/t<a[j-1];j--){count++;cntnei++;
			//t=a[j];//2024.6.28优化减少赋值操作
			a[j]=a[j-1];
			//a[j-1]=t;
		}a[j]=t;//为什么可以j,因为如果t是>=a[j-1]t得赋给a[j]，如果是因为j==0,上一次赋值也把a[1]=a[0]可以搞a[0]了
	}
	printf("inset的count=%d,cntwai=%d,cntnei=%d\n",count,cntwai,cntnei);
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
	int i,j,k,t,cntwai=0,count=0,cntnei=0;
	for(i=0;i<len;i++){//==i<len-1;就能少走一点点，虽然<len最后j也会因为j=len走掉;所以几乎差不多 
		k=i;count++;
		for(j=i+1;j<len;j++){cntwai++;
			if(a[j]<a[k]){
				k=j;cntnei++;
			} 
		}
		t=a[i];
		a[i]=a[k];
		a[k]=t;
	} printf("xunaze的外层和交换count=%d,应该跟冒泡只差只因为flag提前结束的cntwai=%d,找最小值移动的cntnei=%d\n",count,cntwai,cntnei);
}//啥子哦，选择还是比冒泡多走呀，虽然确实count对标交换是少，嗯，难道就是少的这里？



void maopao(int a[],int len){//==优化后的冒泡倒是自我感觉良好捏,连基本有序的时候都跟插入排序一样次数 666; 
	int flag=1,i,t;int count=0,cntwai=0,cntnei=0;
	while(len-- && flag){
		flag=0;cntwai++;
		for(i=0;i<len;i++){cntnei++;
			if(a[i]>a[i+1]){//顺序前小后大 
				flag=1;count++;
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
		
	}
	printf("maopao的count=%d,cntwai=%d,cntnei=%d\n",count,cntwai,cntnei);
} 
