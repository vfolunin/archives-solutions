#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void add(vector<int> &v, int f) {
    for (int i = 2; i <= f; i++) {
        int n = i;
        for (int d : {2, 3, 5, 7}) {
            while (n % d == 0) {
                n /= d;
                v[d]++;
            }
        }
    }
}

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    vector<int> a(10);
    for (int i = 0; i < aSize; i++) {
        int n;
        cin >> n;
        add(a, n);
    }

    vector<int> b(10);
    for (int i = 0; i < bSize; i++) {
        int n;
        cin >> n;
        add(b, n);
    }

    cout << (a == b ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}