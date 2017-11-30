#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	char suits[] = "SHDC";

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		char buf[100];
		if (scanf(" %[^\n]", &buf) == EOF)
			break;
		
		map< char, set<char> > obtainedCards;
		for (int i = 0; buf[i]; i += 3)
			obtainedCards[buf[i + 1]].insert(buf[i]);

		int score = 0;
		int stoppedSuitsCount = 0;

		for (int i = 0; i < 4; i++) {
			set<char> &cards = obtainedCards[suits[i]];
			score += 4 * cards.count('A');
			score += 3 * cards.count('K');
			score += 2 * cards.count('Q');
			score += 1 * cards.count('J');
			score -= cards.size() == 1 && cards.count('K');
			score -= cards.size() <= 2 && cards.count('Q');
			score -= cards.size() <= 3 && cards.count('J');
			bool stopped = 0;
			stopped |= cards.count('A');
			stopped |= cards.size() >= 2 && cards.count('K');
			stopped |= cards.size() >= 3 && cards.count('Q');
			stoppedSuitsCount += stopped;
		}

		if (score >= 16 && stoppedSuitsCount == 4) {
			printf("BID NO-TRUMP\n");
			continue;
		}

		for (int i = 0; i < 4; i++) {
			set<char> &cards = obtainedCards[suits[i]];
			score += 1 * (cards.size() == 2);
			score += 2 * (cards.size() <= 1);
		}

		if (score < 14) {
			printf("PASS\n");
		} else {
			char bestSuit = 'S';
			for (int i = 1; i < 4; i++)
				if (obtainedCards[bestSuit].size() < obtainedCards[suits[i]].size())
					bestSuit = suits[i];
			printf("BID %c\n", bestSuit);
		}

	}
}
