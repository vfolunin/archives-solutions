#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, den;
    cin >> size >> den;

    int num = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        num += value;
    }

    cout << (num + den - 1) / den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}