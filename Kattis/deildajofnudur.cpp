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
    cin >> s >> s;

    int res = 0;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l; r < s.size(); r++) {
            vector<int> count(26);
            for (int i = l; i <= r; i++)
                count[s[i] - 'a']++;

            int minValue = 1e9, maxValue = 0;
            for (int value : count) {
                if (value) {
                    minValue = min(minValue, value);
                    maxValue = max(maxValue, value);
                }
            }

            if (minValue == maxValue)
                res = max(res, r - l + 1);
        }
    }

    cout << res;
}