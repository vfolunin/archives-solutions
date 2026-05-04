#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int xCount, yCount, buf;
    cin >> xCount >> yCount >> buf >> buf;

    for (int i = 0; i < xCount; i++)
        cin >> buf;
    for (int i = 0; i < yCount; i++)
        cin >> buf;

    cout << xCount + yCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}