#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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




//数组中第K大元素，使用堆排序，构建大顶堆
//mark 堆排序
// 打印结果
void Show(int  arr[], int n)
{
    for (int i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
// 交换数组元素位置
void Swap( int *num_a, int *num_b )
{
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}
 //调整序列为最大堆
// array是待调整的堆数组,i是待调整的数组元素的位置,nlength是数组的长度
void HeapBigAdjust(int array[], int i, int nLength)
{
    int nChild, nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // nChild:左子结点的位置是 父结点位置 * 2 + 1(在数组中的位置)  nChild + 1： 右子结点 
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if (nChild < nLength - 1 && array[nChild + 1] > array[nChild])
            nChild++;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动,替换它的父结点
        if (nTemp < array[nChild])
        {
            array[i] = array[nChild];
        }
        else  // 否则退出循环
        {
            break;
        }
    }
    // 最后把需要调整的元素值放到合适的位置
    array[i] = nTemp;
}
// 使用堆排序找到数组中第K大元素
int findKthLargest(int array[], int length,int k)
{
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        // 调整原始无序序列为最大堆
        HeapBigAdjust(array, i, length);
    }
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i >= length - k; i--)
    {
        // 把第一个元素和当前的最后一个元素交换,
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        Swap(&array[0], &array[i]);
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值
        HeapBigAdjust(array, 0, i);
    }
    return array[length - k];
}



//建立小顶堆
void HeapLittleAdjust(int array[], int i, int nLength)
{
    int nChild, nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // nChild:左子结点的位置是 父结点位置 * 2 + 1(在数组中的位置)  nChild + 1： 右子结点 
        nChild = 2 * i + 1;
        // 得到子结点中较小的结点
        if (nChild < nLength - 1 && array[nChild + 1] < array[nChild])
            nChild++;
        // 如果较小的子结点小于父结点那么把较小的子结点往上移动,替换它的父结点
        if (nTemp > array[nChild])
        {
            array[i] = array[nChild];
        }
        else  // 否则退出循环
        {
            break;
        }
    }
    // 最后把需要调整的元素值放到合适的位置
    array[i] = nTemp;
}
//数组中最小的K个数
int* getLeastNumbers(int array[], int length, int k, int* returnSize){
	 int *resultArr = (int *)malloc(k * sizeof(int));

	for (int i = length / 2 - 1; i >= 0; i--)
    {
        // 调整原始无序序列为最小堆
        HeapLittleAdjust(array, i, length);
    }
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i >= length - k; i--)
    {
        // 把第一个元素和当前的最后一个元素交换,
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最小的
        Swap(&array[0], &array[i]);
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最小值
        HeapLittleAdjust(array, 0, i);
        resultArr[length - 1 - i] = array[i];
    }
    return resultArr;
}





//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//假定nums1有足够的空间
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int tail = m + n - 1;
    --m, --n;
    while (m >= 0 && n >= 0) {
        if (nums1[m] > nums2[n]) nums1[tail--] = nums1[m--];
        else                     nums1[tail--] = nums2[n--];
    }
    while (n >= 0)               nums1[tail--] = nums2[n--];
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




	// 使用堆排序找到数组中第K大元素
	// int arr_test[] = { 8, 4, 2, 3, -55,1234,-567,222,12,5, 1, 6, 9, 0, 3 };
 //    int n = sizeof(arr_test) / sizeof(int);
 //    int k = 5;
 //    int kTh = findKthLargest( arr_test, n, k);
 //    printf("%d\n", kTh);




    //最小的K个数
    int arr_test[] = { 8, 4, 2, 3, -55,1234,-567,222,12,5, 1, 6, 9, 0, 3 };
    int n = sizeof(arr_test) / sizeof(int);
    int k = 5;
    int *resultArr = getLeastNumbers(arr_test,n,k,0);
    Show(resultArr,k);


	
	return 0;
}