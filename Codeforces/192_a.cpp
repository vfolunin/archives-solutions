#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    unordered_set<long long> seen;
    for (long long i = 1; i * (i + 1) / 2 <= n; i++) {
        seen.insert(i * (i + 1) / 2);
        if (seen.count(n - i * (i + 1) / 2)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}