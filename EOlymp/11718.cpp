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

    int size, queryCount;
    string s;
    cin >> size >> queryCount >> s;

    vector<int> pos;
    for (int i = 0; i + 1 < s.size(); i++)
        if (s[i] == s[i + 1])
            pos.push_back(i);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << upper_bound(pos.begin(), pos.end(), r - 1) - lower_bound(pos.begin(), pos.end(), l) << "\n";
    }
}