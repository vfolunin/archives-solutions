#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetSum;
    cin >> targetSum;

    for (int k3 = 0; k3 * 3 <= targetSum; k3++) {
        if ((targetSum - k3 * 3) % 7 == 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}