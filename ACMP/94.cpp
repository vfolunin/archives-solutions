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

	int damage, health, regen;
	cin >> damage >> health >> regen;

	if (damage <= regen && health > damage) {
		cout << "NO";
		return 0;
	}

	int res = 0;
	while (1) {
		health -= damage;
		res++;

		if (health <= 0)
			break;

		health += regen;
	}

	cout << res;
}