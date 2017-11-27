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

		int participants, budget, hotels, weeks;
		if (scanf("%d%d%d%d", &participants, &budget, &hotels, &weeks) == EOF)
			break;

		int bestPrice = budget + 1;
		for (int i = 0; i < hotels; i++) {
			int price;
			scanf("%d", &price);
			for (int j = 0; j < weeks; j++) {
				int beds;
				scanf("%d", &beds);
				if (beds >= participants)
					bestPrice = min(bestPrice, price * participants);
			}
		}

		if (bestPrice > budget)
			printf("stay home\n");
		else
			printf("%d\n", bestPrice);

	}
}