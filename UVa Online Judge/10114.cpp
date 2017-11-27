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

		int months, n;
		double down, owe;
		scanf("%d%lf%lf%d", &months, &down, &owe, &n);

		if (months < 0)
			break;

		vector<double> depreciation(months + 1, -1);
		for (int i = 0; i < n; i++) {
			int index;
			scanf("%d", &index);
			scanf("%lf", &depreciation[index]);
		}
		
		double carPrice = owe + down;
		double payment = owe / months;

		for (int i = 0; i <= months; i++) {
			if (depreciation[i] == -1)
				depreciation[i] = depreciation[i - 1];
			if (i)
				owe -= payment;
			carPrice *= 1 - depreciation[i];
			if (owe + 1e-9 < carPrice) {
				printf("%d %s\n", i, (i == 1 ? "month" : "months"));
				break;
			}
		}

	}
}