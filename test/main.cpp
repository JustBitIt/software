#include<stdio.h>
#include<stdlib.h>

//extern "C" int my_add(int a, int b,int c);
extern "C" int my_add64(int a, int b, int c, int d, int e, int f);

int main(int argc, char** argv)
{
	char temp[] = "AAAAA";
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;
	int p4 = 4;
	int p5 = 5;
	int p6 = 6;

	//int sum = my_add(p1, p2,p3);
	int sum = my_add64(p1, p2, p3,p4,p5,p6);

	printf("sum=%d\n", sum);

	system("pause");

	return 0;
}