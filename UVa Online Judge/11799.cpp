#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int testsCount;
	scanf("%d", &testsCount);
	for (int testN = 1; testN <= testsCount; testN++) {

		int n;
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			res = max(res, x);
		}
		printf("Case %d: %d\n", testN, res);

	}
}
