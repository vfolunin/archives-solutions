#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    int xorSum = 0;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        xorSum ^= x;
    }

    cout << "Case #" << test << ": " << xorSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}