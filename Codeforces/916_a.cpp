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

	int delta, h, m;
	cin >> delta >> h >> m;

	int time = h * 60 + m, res = 0;
	while (time % 60 % 10 != 7 && time / 60 % 10 != 7) {
		res++;
		time = (time - delta + 24 * 60) % (25 * 60);
	}

	cout << res;
}