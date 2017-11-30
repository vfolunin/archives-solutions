#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		int reqs, props;
		scanf("%d%d", &reqs, &props);
		if (reqs == 0 && props == 0)
			break;

		for (int i = 0; i < reqs; i++)
			scanf(" %*[^\n]");

		int bestN = -1;
		double bestCost;
		char bestProp[100];
		for (int i = 0; i < props; i++) {
			int n;
			double cost;
			char prop[100];
			scanf(" %[^\n]%lf%d", prop, &cost, &n);
			if (bestN < n || bestN == n && bestCost > cost) {
				bestN = n;
				bestCost = cost;
				strcpy(bestProp, prop);
			}
			for (int j = 0; j < n; j++)
				scanf(" %*[^\n]");
		}

		printf("%sRFP #%d\n%s\n", (testN == 1 ? "" : "\n"), testN, bestProp);

	}
}
