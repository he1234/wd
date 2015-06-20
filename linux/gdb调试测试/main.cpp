#include<stdio.h>
#include<string.h>

int main(void)
{
	int a[10];
	memset(a, 0, 40);
	int i;
	for(i = 0; i < 10; ++i)
		a[i] = i*2;

	return 0;
}
