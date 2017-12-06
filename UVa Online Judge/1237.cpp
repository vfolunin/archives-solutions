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

struct Manufacturer {
	char name[30];
	int l, r;
} mf[10010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testsCount;
	scanf("%d", &testsCount);
	for (int testN = 1; testN <= testsCount; testN++) {

		if (testN > 1)
			printf("\n");

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf(" %s%d%d", mf[i].name, &mf[i].l, &mf[i].r);
		
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int cost;
			scanf("%d", &cost);
			int index = -1;
			for (int j = 0; j < n; j++) {
				if (mf[j].l <= cost && cost <= mf[j].r) {
					if (index == -1) {
						index = j;
					} else {
						index = -1;
						break;
					}
				}
			}
			if (index == -1)
				printf("UNDETERMINED\n");
			else
				printf("%s\n", mf[index].name);
		}

	}
}
