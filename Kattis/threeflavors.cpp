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

    string s;
    cin >> s;

    vector<int> count(3);
    for (char c : s)
        count[c - 'a']++;

    string res;
    for (int i = 0; i < s.size(); i++) {
        vector<int> order = { 0, 1, 2 };
        sort(order.begin(), order.end(), [&](int l, int r) {
            return count[l] > count[r];
        });

        bool found = 0;
        for (int index : order) {
            if (count[index] && (res.empty() || res.back() != index + 'a')) {
                res.push_back(index + 'a');
                count[index]--;
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << res;
}