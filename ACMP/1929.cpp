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

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return count[a] > count[b];
    });

    if (!count[order[2]]) {
        cout << "NO";
        return 0;
    }

    count[order[0]] = count[order[1]] = count[order[2]];
    for (char c : s) {
        if (count[c - 'a'] && (c - 'a' == order[0] || c - 'a' == order[1] || c - 'a' == order[2])) {
            count[c - 'a']--;
            cout << c;
        }
    }
}