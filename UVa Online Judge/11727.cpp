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

		int a[3];
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		printf("Case %d: %d\n", testN, a[1]);

	}
}