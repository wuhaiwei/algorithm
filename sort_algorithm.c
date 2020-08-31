#include <stdio.h>

//冒泡排序
void sort_maopao(int a[],int n){
	int i,j;
	for(i=0;i<n - 1;i++)  
		{//n个数要进行n-1趟比较
		for(j=0;j<n-1-i;j++)          
			if(a[j]>a[j+1])          //依次比较两个相邻的数，将小数放在前面，大数放在后面
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	}
	for(i=0;i<n;++i)               //输出比较之后的数组
		printf(" %d",a[i]);
	printf("\n");
}

// 插入排序
void insert_sort(int a[],int n)
//待排序元素用一个数组a表示，数组有n个元素
{
    int i,j;
    int temp;
    for ( i=1; i<n; i++) //i表示插入次数，共进行n-1次插入
  {
      temp=a[i]; //把待排序元素赋给temp，temp在while循环中并不改变，这样方便比较，并且它是要插入的元素
      j=i-1;
      //while循环的作用是将比当前元素大的元素都往后移动一个位置
      while ((j >= 0) && (a[j] > temp)){
          a[j+1]=a[j];
          j--; // 顺序比较和移动,依次将元素后移动一个位置
      }
 
      a[j+1]=temp;//元素后移后要插入的位置就空出了，找到该位置插入
  }
}


// 选择排序:
// 选择排序首先在未排序序列中找到最小（大）元素，
// 存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，
// 然后放到已排序序列的末尾。
void selection_sort(int a[],int n){
	int i, j, temp, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				// 记录最小的值的位置
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}


// 快速排序ß
void sort_by_quick(int a[], int left, int right) {
	// https://blog.csdn.net/starlet_kiss/article/details/86010904?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
	if(left > right)
		return;

	int i, j, t, temp;
    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while(i != j) { //顺序很重要，要先从右边开始找
    	while(i < j && a[j] >= temp)
    		j --;
    	while(i < j && a[i] <= temp)
    		i ++;    
    	if(i < j)//交换两个数在数组中的位置
    	{
    		t = a[i];
    		a[i] = a[j];
    		a[j] = t;
    	}
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;
    sort_by_quick(a, left, i-1);//继续处理左边的，这里是一个递归的过程
    sort_by_quick(a, i+1, right);//继续处理右边的 ，这里是一个递归的过程
}



//mark 堆排序
// 打印结果
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
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
 
// array是待调整的堆数组,i是待调整的数组元素的位置,nlength是数组的长度
void HeapAdjust(int array[], int i, int nLength)
{
    int nChild, nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // nChild:左子结点的位置是 父结点位置 * 2 + 1  nChild + 1： 右子结点 
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if (nChild != nLength - 1 && array[nChild + 1] > array[nChild])
            ++nChild;
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
// 堆排序算法
void HeapSort(int array[], int length)
{
    // 调整序列的前半部分元素,（即每个有孩子的节点）调整完之后是一个大顶堆，第一个元素是序列的最大的元素
    for (int i = length / 2 - 1; i >= 0; --i)
    {
        HeapAdjust(array, i, length);
    }
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i > 0; --i)
    {
        // 把第一个元素和当前的最后一个元素交换,
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        Swap(&array[0], &array[i]);
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array, 0, i);
    }
}


int main () {

    // 冒泡排序
    // int a[] = {1,3,6,2,66,4};
    // int n = sizeof(a)/sizeof(int);
    // sort_maopao(a,n);
    


    //插入排序
 //    int a[] = {1,3,6,2,66,4};
 //    int n = sizeof(a)/sizeof(int);
 //    insert_sort(a,n);
 //    for(int i=0;i<n;++i)               
	// 	printf(" %d",a[i]);
	// printf("\n");


    // 选择排序
 //    int a[] = {1,3,6,2,66,4};
 //    int n = sizeof(a)/sizeof(int);
 //    selection_sort(a,n);
 //    for(int i=0;i<n;++i)               
	// 	printf(" %d",a[i]);
	// printf("\n");


    // 快速排序
 //    int a[] = {76,3,6,2,-56,-23,44,66,4,555,23,100,2};
 //    // int a[] = {6, 1, 2, 7, 9, 15, 4, 5, 10, 8};
 //    int n = sizeof(a)/sizeof(int);
 //    sort_by_quick(a,0,n - 1);
 //    for(int i=0;i<n;++i)               
	// 	printf(" %d",a[i]);
	// printf("\n");



	//测试数据
    int arr_test[10] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    //排序前数组序列
    Show( arr_test, 10 );
    HeapSort( arr_test, 10 );
    //排序后数组序列
    Show( arr_test, 10 );

    return 0;
}

