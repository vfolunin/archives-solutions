#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, diagCount;
    cin >> size >> diagCount;

    if (diagCount == 4 * size - 2)
        cout << diagCount / 2 + 1 << "\n";
    else
        cout << (diagCount + 1) / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}