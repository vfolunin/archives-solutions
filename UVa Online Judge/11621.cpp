#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    set<long long> s = { 1 };
    while (1) {
        long long x = *s.begin();
        s.erase(s.begin());

        if (x >= n) {
            cout << x << "\n";
            break;
        }

        s.insert(x * 2);
        s.insert(x * 3);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}