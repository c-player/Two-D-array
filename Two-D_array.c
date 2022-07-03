#define _CRT_SECURE_NO_WARNINGS 1

//关于二维数组地址的理解
//sizeof(数组名)和 &数组名 中的数组名代表整个数组
//其余数组名代表首元素地址

#include <stdio.h>

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));           //a代表整个数组，所以 3 * 4 * 4 = 48
	printf("%d\n", sizeof(a[0]));        //a[0]代表第一行的数组名，所以 4 * 4 = 16
	printf("%d\n", sizeof(a[0] + 1));    //a[0]是第一行首元素地址，+1代表第一行第二个元素地址，4
	printf("%d\n", sizeof(*(a[0] + 1))); //第二个元素，4
	printf("%d\n", sizeof(a + 1));       //a代表整个数组的首元素地址，即第一行地址，+1代表第二行地址，4
	printf("%d\n", sizeof(*(a + 1)));    //解引用，找到第二行数组，等价于sizeof(a[1])，4 * 4 = 16
	printf("%d\n", sizeof(&a[0] + 1));   //a[0]：第一行数组名，数组名取地址，为第一行元素地址，+1为第二行地址
	//注意：a[0]和&a[0]的地址都是相同的，但是代表的含义不同，原来是首元素地址，&后是整行数组的地址。 4
	printf("%d\n", sizeof(*(&a[0] + 1)));//解引用，找到第二行元素，相当于sizeof(a[1])，4 * 4 = 16
	printf("%d\n", sizeof(*a));          //a是首元素地址，即第一行地址，即&a[0]，解引用找到第一行，4 * 4 = 16
	printf("%d\n", sizeof(a[3]));        
	//sizeof并不会真的去访问第4行，sizeof内部的表达式不参与真实运算，sizeof只根据类型计算大小， 4 * 4 = 16
    return 0;
}