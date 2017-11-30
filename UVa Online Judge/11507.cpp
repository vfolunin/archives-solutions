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

	map<string, map<string, string> > bend;

	bend["+x"]["No"] = "+x";
	bend["+x"]["+y"] = "+y";
	bend["+x"]["-y"] = "-y";
	bend["+x"]["+z"] = "+z";
	bend["+x"]["-z"] = "-z";

	bend["-x"]["No"] = "-x";
	bend["-x"]["+y"] = "-y";
	bend["-x"]["-y"] = "+y";
	bend["-x"]["+z"] = "-z";
	bend["-x"]["-z"] = "+z";

	bend["+y"]["No"] = "+y";
	bend["+y"]["+y"] = "-x";
	bend["+y"]["-y"] = "+x";
	bend["+y"]["+z"] = "+y";
	bend["+y"]["-z"] = "+y";

	bend["-y"]["No"] = "-y";
	bend["-y"]["+y"] = "+x";
	bend["-y"]["-y"] = "-x";
	bend["-y"]["+z"] = "-y";
	bend["-y"]["-z"] = "-y";

	bend["+z"]["No"] = "+z";
	bend["+z"]["+y"] = "+z";
	bend["+z"]["-y"] = "+z";
	bend["+z"]["+z"] = "-x";
	bend["+z"]["-z"] = "+x";

	bend["-z"]["No"] = "-z";
	bend["-z"]["+y"] = "-z";
	bend["-z"]["-y"] = "-z";
	bend["-z"]["+z"] = "+x";
	bend["-z"]["-z"] = "-x";
	
	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		string dir = "+x";
		for (int i = 1; i < n; i++) {
			char change[10];
			scanf(" %s", change);
			dir = bend[dir][change];
		}

		printf("%s\n", dir.c_str());

	}
}
