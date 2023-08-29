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

	long long width, time;
	cin >> width >> time;

	time %= 2 * width;

	if (time <= width)
		cout << time;
	else
		cout << 2 * width - time;
}