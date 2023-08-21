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

    long long a, b, ta, tb;
    cin >> a >> b >> ta >> tb;

    cout << (a - 1) * ta << " " << (a + b - 2) * tb;
}