#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> order(s.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return s[a] < s[b];
    });

    for (int i = 0; i < s.size(); i++) {
        if (s[order[i]] < 'A' + i) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i : order)
        cout << i + 1 << " ";
}