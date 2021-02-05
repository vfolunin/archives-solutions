#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            pos.push_back(i);

    int queryCount;
    cin >> queryCount;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);

        int count = upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
        cout << (count == r - l + 1 || count == 0 ? "Yes\n" : "No\n");
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}