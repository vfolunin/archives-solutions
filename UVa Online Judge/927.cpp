#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
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
		vector<long long> c(n + 1);
		for (int i = 0; i <= n; i++)
			scanf("%lld", &c[i]);

		long long d, k;
		scanf("%lld%lld", &d, &k);

		for (int i = 1; 1; i++) {
			if (k <= d * i) {
				long long res = 0;
				for (int j = n; j >= 0; j--)
					res = res * i + c[j];
				printf("%lld\n", res);
				break;
			} else {
				k -= d * i;
			}
		}

	}
}
