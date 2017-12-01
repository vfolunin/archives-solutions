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

		int h, w;
		scanf("%d%d", &h, &w);
		if (h == 0 && w == 0)
			break;

		int k;
		if (h == 0 || w == 0)
			k = 0;
		else if (h == 1 || w == 1)
			k = max(h, w);
		else if (h == 2 || w == 2)
			k = 2 * (max(h, w) / 4 * 2 + (max(h, w) % 4 >= 1) + (max(h, w) % 4 >= 2));
		else
			k = (h * w + 1) / 2;

		printf("%d knights may be placed on a %d row %d column board.\n", k, h, w);

	}
}
