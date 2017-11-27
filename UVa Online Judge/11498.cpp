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

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		int x0, y0;
		scanf("%d%d", &x0, &y0);
		
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == x0 || y == y0)
				printf("divisa\n");
			else if (x < x0 && y < y0)
				printf("SO\n");
			else if (x < x0 && y > y0)
				printf("NO\n");
			else if (x > x0 && y < y0)
				printf("SE\n");
			else if (x > x0 && y > y0)
				printf("NE\n");
		}

	}
}