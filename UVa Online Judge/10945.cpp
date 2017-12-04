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


string leaveOnlyLetters(string text) {
	string res;
	for (int i = 0; i < text.size(); i++) {
		if (isalpha(text[i]))
			res += tolower(text[i]);
	}
	return res;
}

string reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		char s[100010];
		fgets(s, 100009, stdin);
		if (!strcmp(s, "DONE\n"))
			break;

		string p = leaveOnlyLetters(s);
		if (p == reverse(p))
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");

	}
}
