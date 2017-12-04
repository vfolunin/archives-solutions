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


string reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

string mirror(string s) {
	string m1 = "AEHIJLMOSTUVWXYZ12358";	string m2 = "A3HILJMO2TUVWXY51SEZ8";	string res;	for (int i = 0; i < s.size(); i++) {		if (m1.find(s[i]) != -1)			res += m2[m1.find(s[i])];		else			res += '-';	}	return reverse(res);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		char s[100];
		if (scanf(" %s", s) == EOF)
			break;

		bool pal = (reverse(s) == s);
		bool mir = (mirror(s) == s);

		if (!pal && !mir)
			printf("%s -- is not a palindrome.\n\n", s);
		if (pal && !mir)
			printf("%s -- is a regular palindrome.\n\n", s);
		if (!pal && mir)
			printf("%s -- is a mirrored string.\n\n", s);
		if (pal && mir)
			printf("%s -- is a mirrored palindrome.\n\n", s);

	}
}
