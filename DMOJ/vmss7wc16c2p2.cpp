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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'G')
            pos.push_back(i);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l) << "\n";
    }   
}