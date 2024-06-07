/*力扣217 存在重复元素 https://leetcode.cn/problems/contains-duplicate/submissions/537244617/
给你一个整数数组 nums 如果任一值在数组中出现 至少两次,返回 true ；
如果数组中每个元素互不相同，返回 false 。*/

#include<iostream>
#include<stdlib.h>
#include<cstring>//memset  memset一般只拿来赋0值，因为1字节1字节的动 

using namespace std;


bool containsDuplicate(int* nums, int numsSize) {
    int hash[200002],key,N=180000,for0=0;	// * Best fast-->int hash[180000],key,N=170000,for0=0; 
    memset(hash,0,sizeof(hash)); //sizeof(hash)才能保证4*200002个字节都0了 Because the sizeof(hash) equal 800008; 
	//cout<<4*200002<<"="<<sizeof(hash)<<endl; 
    for(int i=0;i<numsSize;i++){
    	if(nums[i]){		//非0正常走 
	        key=(nums[i]%N+N)%N;    //排除负数并得到key值
	        if(!hash[key])hash[key]=nums[i];
	        else{
	            if(hash[key]==nums[i])return true;
	            else{key++;         //偏移一法
	                while(hash[key]!=0){
	                    if(hash[key]==nums[i])return true;
	                    key++;
	                }
	            }
	        }
    	}else{				//0来特判 
			if(!for0)for0++;
			else return true;
		}
    }return false;
}


int main (){
	int n=6;
	int a[200001]={0,4,5,0,3,6};
	
	//scanf("%d",&n);
	//for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	//qsort(a,n,sizeof(a[0]),compare);
	cout<<containsDuplicate(a,6);
	
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	
	return 0;
}
