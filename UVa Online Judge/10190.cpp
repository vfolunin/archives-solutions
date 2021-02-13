#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    if (n <= 1 || m <= 1) {
        cout << "Boring!\n";
        return 1;
    }

    vector<int> v;
    for (; n % m == 0; n /= m)
        v.push_back(n);
    
    if (n == 1) {
        v.push_back(1);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
    } else {
        cout << "Boring!\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}