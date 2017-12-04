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

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		long long k;
		if (scanf("%lld", &k) == EOF)
			break;

		vector< pair<long long, long long> > ans;
		for (long long y = k + 1; y <= 2 * k; y++) {
			if (k * y % (y - k) == 0)
				ans.push_back(make_pair(k * y / (y - k), y));
		}

		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("1/%lld = 1/%lld + 1/%lld\n", k, ans[i].first, ans[i].second);

	}
}
