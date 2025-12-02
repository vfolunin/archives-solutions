#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> wordSize, int spaceSize, int lineLimit, long long lineSize) {
	int lineCount = 1;
	long long curLineSize = 0;

	for (int size : wordSize) {
		if (curLineSize + (curLineSize ? spaceSize : 0) + size <= lineSize) {
			curLineSize += (curLineSize ? spaceSize : 0) + size;
		} else {
			curLineSize = size;
			lineCount++;
		}
	}

	return lineCount <= lineLimit;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int wordCount, lineLimit, spaceSize;
	cin >> wordCount >> lineLimit >> spaceSize;

	vector<int> wordSize(wordCount);
	for (int &size : wordSize)
		cin >> size;

	long long l = *max_element(wordSize.begin(), wordSize.end()), r = l;
	while (!can(wordSize, spaceSize, lineLimit, r))
		r *= 2;

	while (l + 1 < r) {
		long long m = l + (r - l) / 2;
		if (can(wordSize, spaceSize, lineLimit, m))
			r = m;
		else
			l = m;
	}

	cout << r;
}