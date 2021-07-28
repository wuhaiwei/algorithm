#include <stdio.h>
#include <math.h>
#include <string.h>


// 是否是质数
 int isPrime_2( int num )  
{  
     int tmp =sqrt( num);  
     for(int i= 2;i <=tmp; i++)  
        if(num %i== 0)  
          return 0 ;  
     return 1 ;  
 } 


//反转整数
int reverseInt(int n){
	int max = 2147483647;
	int min = -2147483648;
	long result = 0;
	while(n != 0){
		result = result * 10 + n % 10;
		n /= 10;
	}
	return (result > max || result < min) ? 0 : result;
}

int fac(int n){
	if (n == 0)
	{
		return 0;
	}else if(n == 1){
		return 1;
	}else{
		return n * fac(n - 1);
	}
}

int isPrime(int n){
	int tmp = sqrt(n);
	for (int i = 2; i <= tmp; ++i)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}


int main () {
	// 递归阶乘
	// int ret = fac(5);
	// printf("%d\n", ret);


    //是否是质数
	// int ret = isPrime(7);
	// printf("%d\n", ret);


    //反转整数
    int n = 123456678;
    int resverseN = reverseInt(n);
    printf("%d\n", resverseN);



    return 0;
}

