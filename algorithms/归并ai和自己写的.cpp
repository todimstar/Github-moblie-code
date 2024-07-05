
#include <stdio.h>



// 合并两个已排序的数组

void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int merged[]) {

	int leftIndex = 0, rightIndex = 0, mergedIndex = 0;



	// 合并两个子数组

	while (leftIndex < leftSize && rightIndex < rightSize) {

		if (left[leftIndex] <= right[rightIndex]) {

			merged[mergedIndex++] = left[leftIndex++];

		} else {

			merged[mergedIndex++] = right[rightIndex++];

		}

	}



	// 复制剩余的左侧数组元素

	while (leftIndex < leftSize) {

		merged[mergedIndex++] = left[leftIndex++];

	}



	// 复制剩余的右侧数组元素

	while (rightIndex < rightSize) {

		merged[mergedIndex++] = right[rightIndex++];

	}

}



// 归并排序函数

void mergeSort(int arr[],int size) {

	if (size <= 1) {

		// 数组大小为0或1时，已经是排序好的

		return;

	}



	int mid = size / 2;



	// 临时数组

	int left[mid];

	int right[size - mid];



	// 复制左侧子数组

	for (int i = 0; i < mid; i++) {

		left[i] = arr[i];

	}



	// 复制右侧子数组

	for (int i = mid; i < size; i++) {

		right[i - mid] = arr[i];

	}



	// 递归排序左右子数组

	mergeSort(left, mid);

	mergeSort(right, size - mid);



	// 合并两个已排序的子数组

	int merged[size];

	merge(arr, left, mid, right, size - mid, merged);



	// 将合并后的数组复制回原数组

	for (int i = 0; i < size; i++) {

		arr[i] = merged[i];

	}

}

const int N=1000;
int temp[N];
void merge_sort(int a[],int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	merge_sort(a,l,mid);merge_sort(a,mid+1,r);

	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=r)temp[k++]=a[j++];

	for(i=0,j=l;i<k;i++,j++){
		a[j]=temp[i];
	}
}


int main() {

	int arr[] = {38, 27, 43, 3, 9, 82, 10};

	int size = sizeof(arr) / sizeof(arr[0]);



	// 排序数组

	merge_sort(arr, 0,size-1);



	// 输出排序后的数组

	for (int i = 0; i < size; i++) {

		printf("%d ", arr[i]);

	}

	printf("\n");



	return 0;

}
