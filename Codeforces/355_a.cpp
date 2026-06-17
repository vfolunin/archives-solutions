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

	int size, digitRoot;
	cin >> size >> digitRoot;

	if (size > 1 && !digitRoot)
		cout << "No solution";
	else
		cout << digitRoot << string(size - 1, '0');
}