#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testsCount;
	scanf("%d", &testsCount);
	for (int testN = 1; testN <= testsCount; testN++) {

		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b)
			printf("<\n");
		else if (a > b)
			printf(">\n");
		else
			printf("=\n");

	}
}