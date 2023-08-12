#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Item {
	char type;
	int amount, canChange;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int itemCount;
	cin >> itemCount;

	vector<Item> items(itemCount);
	int totalAmount = 0;
	for (auto &[type, amount, canChange] : items) {
		cin >> type >> amount;
		totalAmount += amount;
	}

	int addAmount = 100;
	for (auto &[type, amount, canChange] : items) {
		canChange = (amount * 100) % totalAmount;
		amount = (amount * 100) / totalAmount;
		addAmount -= amount;
	}

	for (auto &[type, amount, canChange] : items) {
		if (type == '+' && canChange && addAmount) {
			amount++;
			addAmount--;
		}
	}
	for (auto &[type, amount, canChange] : items) {
		if (type == '-' && canChange && addAmount) {
			amount++;
			addAmount--;
		}
	}

	for (auto &[type, amount, canChange] : items)
		cout << amount << "\n";
}