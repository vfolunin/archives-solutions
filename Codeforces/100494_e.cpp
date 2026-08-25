#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int participants, budget, hotels, weeks;
	cin >> participants >> budget >> hotels >> weeks;

	int bestPrice = budget + 1;
	for (int i = 0; i < hotels; i++) {
		int price;
		cin >> price;
		for (int j = 0; j < weeks; j++) {
			int beds;
			cin >> beds;
			if (beds >= participants)
				bestPrice = min(bestPrice, price * participants);
		}
	}

	if (bestPrice > budget)
		printf("stay home\n");
	else
		printf("%d\n", bestPrice);
}