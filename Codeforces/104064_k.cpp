#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, vector<int>> count;
    for (int i = 0; i < size; i++) {
        string type, index;
        int delta;
        cin >> type >> index >> delta;

        if (!count.count(type))
            count[type] = { 0, 0, 0 };
        if (index == "left")
            count[type][0] += delta;
        else if (index == "right")
            count[type][1] += delta;
        else
            count[type][2] += delta;
    }

    int can = 0, res = 0;
    for (auto &[_, count] : count) {
        can |= count[0] && count[1] || count[0] && count[2] || count[1] && count[2] || count[2] > 1;
        res += max({ count[0], count[1], count[2] ? 1 : 0 });
    }

    if (can)
        cout << res + 1;
    else
        cout << "impossible";
}