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

		char piece;
		int h, w;
		scanf(" %c%d%d", &piece, &h, &w);

		if (piece == 'r') {
			printf("%d\n", min(h, w));
		} else if (piece == 'k') {
			printf("%d\n", (h * w + 1) / 2);
		} else if (piece == 'Q') {
			printf("%d\n", min(h, w));
		} else {
			printf("%d\n", ((h + 1) / 2) * ((w + 1) / 2));
		}

	}
}
