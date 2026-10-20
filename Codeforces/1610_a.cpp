#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int height, width;
    cin >> height >> width;

    if (height == 1 && width == 1)
        cout << "0\n";
    else if (height == 1 || width == 1)
        cout << "1\n";
    else
        cout << "2\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}