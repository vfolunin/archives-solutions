#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	vector<int> a(5);
	unordered_map<int, int> count;
	for (int &value : a) {
		cin >> value;
		count[value]++;
	}

	sort(a.begin(), a.end());

	vector<int> counts(6);
	for (auto &[value, count] : count)
		counts[count]++;

	if (counts[5])
		cout << "Impossible";
	else if (counts[4])
		cout << "Four of a Kind";
	else if (counts[2] && counts[3])
		cout << "Full House";
	else if (a[0] + 1 == a[1] && a[0] + 2 == a[2] && a[0] + 3 == a[3] && a[0] + 4 == a[4])
		cout << "Straight";
	else if (counts[3])
		cout << "Three of a Kind";
	else if (counts[2] == 2)
		cout << "Two Pairs";
	else if (counts[2])
		cout << "One Pair";
	else
		cout << "Nothing";
}