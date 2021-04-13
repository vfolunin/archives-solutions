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

    int n;
    cin >> n;

    set<int> mersennePrimes = { 2, 3, 5, 7, 13, 17 };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cin.ignore();

        cout << (mersennePrimes.count(x) ? "Yes\n" : "No\n");
    }
}