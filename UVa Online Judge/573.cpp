#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		double h, u, d, f;
		scanf("%lf%lf%lf%lf", &h, &u, &d, &f);
		if (h == 0)
			break;
		f = u * (f / 100);

		double ch = 0;
		for (int i = 1; 1; i++) {
			ch += u;
			if (ch > h + 1e-9) {
				printf("success on day %d\n", i);
				break;
			}
			ch -= d;
			if (ch < -1e-9) {
				printf("failure on day %d\n", i);
				break;
			}
			u = max(0.0, u - f);
		}

	}
}
