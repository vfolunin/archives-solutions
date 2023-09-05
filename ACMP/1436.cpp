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

	int size;
	cin >> size;

	for (int dots = size / 2, letters = 1; letters <= size; dots--, letters += 2)
		cout << string(dots, '.') << string(letters, 'A') << "\n";
}