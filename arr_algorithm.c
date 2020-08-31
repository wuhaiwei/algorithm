#include <stdio.h>
#include <string.h>


// 二分查找
int binary_search(int a[], int left, int right, int element){
	while(left <= right){
		int mid = (left + right) / 2;
		if (a[mid] > element)
		{
			right = mid - 1;
		}else if(a[mid] < element){
			left = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}


// 查找有序数组中某个数首次出现的位置   {1,2,34,45,45,45,45,56,678,8999,8899};
int index_of_element_by_binary_search(int a[],int left,int right,int element){
	while(left <= right){
		int mid = (left + right) / 2;
		if (a[mid] == element && a[mid - 1] != element)
		{
			return mid;
		}else if(a[mid] >= element){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}


//数组中组成最大的数
void maxIndexAndNum(int a[],int n){
	int max = a[0];
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] > max){
			max = a[i];
			index = i;
		}
	}
	printf("%d\n", max);
	printf("%d\n", index);
}



int main(){


	//二分查找
	// int a[] = {1,4,5,6,7,8,9,10};
	// int ret = binary_search(a,0,sizeof(a)/sizeof(int) - 1,10);
	// printf("%d\n", ret);


	// 查找有序数组中某个数首次出现的位置
	// int a[] = {1,2,34,45,45,45,45,56,56,678,8999,8899};
	// int ret = index_of_element_by_binary_search(a,0,(sizeof(a)/sizeof(int) - 1),56);
	// printf("%d\n", ret);



	// 数组中最大的数
	// int a[] = {3,23,-23,1000,-400,543,1,0,34242,556};
	// int n = sizeof(a) / sizeof(int);
	// maxIndexAndNum(a, n);


	
	return 0;
}