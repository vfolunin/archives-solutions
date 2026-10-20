#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x <= y; x++)
            cout << (x == 0 || x == y) << " ";
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}