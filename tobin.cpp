#include <stdio.h>
#include <iostream>

using namespace std;

void print(int n)
{
	if (n >= 2) print(n/2);
	printf("%d", n%2);
}
int main()
{
	int num;
	cin >> num;
	print(num);
	printf("\n");
}
