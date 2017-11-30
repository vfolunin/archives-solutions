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

		deque<string> pile, hand;
		for (int i = 0; i < 52; i++) {
			char card[3];
			scanf(" %s", card);
			pile.push_back(card);
		}

		for (int i = 0; i < 25; i++) {
			hand.push_front(pile.back());
			pile.pop_back();
		}

		int y = 0;
		for (int i = 0; i < 3; i++) {
			int x = (isdigit(pile.back()[0]) ? pile.back()[0] - '0' : 10);
			y += x;
			pile.pop_back();
			for (int j = 0; j < 10 - x; j++)
				pile.pop_back();
		}

		for (int i = 0; i < 25; i++) {
			pile.push_back(hand.front());
			hand.pop_front();
		}

		printf("Case %d: %s\n", testN, pile[y - 1].c_str());

	}
}
