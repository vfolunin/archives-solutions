#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int guestCount;
    cin >> guestCount;

    if (!guestCount)
        return 0;

    vector<string> guests(guestCount);
    for (string &guest : guests)
        cin >> guest;

    sort(guests.begin(), guests.end());

    string &a = guests[(guestCount - 1) / 2];
    string &b = guests[guestCount / 2];
    string res = a, cur = a;

    while (cur.size() > 1) {
        cur.pop_back();
        if (cur.back() != 'Z')
            cur.back()++;
        if (a <= cur && cur < b)
            res = cur;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}