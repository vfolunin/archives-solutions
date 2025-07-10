#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, targetCount;
    cin >> size >> targetCount;

    int count = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count += value <= 0;
    }

    cout << (count < targetCount ? "WAIT\n" : "DISPATCH\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}