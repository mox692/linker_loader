#include<stdio.h>

extern int func(); 

int main() {
	int a = func();
	printf("res is %d\n", a);
	return 0;
}
