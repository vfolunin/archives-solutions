#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
double x[16], y[16];
double dist[16][16];
double d[1 << 16];

double rec(int mask) {
	if (d[mask] != -1)
		return d[mask];
	if (mask == 0)
		return 0;
	int last = 2 * n - 1;
	while ((mask & (1 << last)) == 0)
		last--;
	double res = 1e100;
	for (int i = 0; i < last; i++) {
		if ((mask & (1 << i)) == 0)
			continue;
		int newMask = mask & ~((1 << i) | (1 << last));
		res = min(res, rec(newMask) + dist[i][last]);
	}
	return d[mask] = res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		scanf("%d", &n);
		if (n == 0)
			break;
		
		for (int i = 0; i < 2 * n; i++)
			scanf("%*s%lf%lf", &x[i], &y[i]);
		
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++)
				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}

		for (int i = 0; i < 1 << 2 * n; i++)
			d[i] = -1;

		printf("Case %d: %.2lf\n", testN, rec((1 << 2 * n) - 1));
	}
}