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

    long long a, b;
    cin >> a >> b;

    if (b == 0 || a == 0 || a == 2 || a == -2 && b % 2 == 0)
        cout << '=';
    else if (a == 1 || a == -1 && b % 2 == 0)
        cout << '>';
    else
        cout << '<';
}