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

		set<int> s;

		int a[3], b[3];
		for (int i = 0; i < 3; i++) {
			scanf("%d", &a[i]);
			s.insert(a[i]);
		}
		for (int i = 0; i < 2; i++) {
			scanf("%d", &b[i]);
			s.insert(b[i]);
		}
		if (a[0] == 0)
			break;

		sort(a, a + 3);
		b[2] = 1;
		bool fail = 0;
		do {
			if (a[0] < b[0] && a[1] < b[1])
				continue;
			if (a[0] > b[0] && a[1] > b[1]) {
				fail = 1;
				break;
			}
			b[2] = max(b[2], a[2] + 1);
		} while (next_permutation(a, a + 3));

		while (s.count(b[2]))
			b[2]++;

		if (fail || b[2] > 52)
			printf("-1\n");
		else
			printf("%d\n", b[2]);

	}
}
