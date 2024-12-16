#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getGrundy(int size, int take) {
    static vector<int> memo(41, -1);
    int &res = memo[size];
    if (res != -1)
        return res;

    set<int> toGrundy;
    for (int l = 0, r = size - take; r >= l; l++, r--)
        toGrundy.insert(getGrundy(l, take) ^ getGrundy(r, take));

    res = 0;
    while (toGrundy.count(res))
        res++;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int take;
    string s;
    cin >> take >> take >> s;

    vector<int> parts;
    int part = 0;
    for (char c : s) {
        if (c == 'O') {
            part++;
        } else {
            if (part >= take)
                parts.push_back(part);
            part = 0;
        }
    }
    if (part >= take)
        parts.push_back(part);

    if (parts.empty()) {
        cout << 0;
        return 0;
    }

    int res = 0;
    for (int part : parts)
        res ^= getGrundy(part, take);

    cout << (res ? 1 : 2);
}