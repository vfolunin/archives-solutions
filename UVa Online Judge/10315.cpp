#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getHandStrength(vector<int> &v, vector<char> &s) {
    if (s[0] == s[4] && v[1] == v[0] + 1 && v[2] == v[0] + 2 && v[3] == v[0] + 3 && v[4] == v[0] + 4)
        return { 9, v[4] };

    if (v[1] == v[4])
        return { 8, v[4] };
    if (v[0] == v[3])
        return { 8, v[3] };

    if (v[0] == v[1] && v[2] == v[4])
        return { 7, v[4] };
    if (v[0] == v[2] && v[3] == v[4])
        return { 7, v[2] };

    if (s[0] == s[4])
        return { 6, v[4], v[3], v[2], v[1], v[0] };

    if (v[1] == v[0] + 1 && v[2] == v[0] + 2 && v[3] == v[0] + 3 && v[4] == v[0] + 4)
        return { 5, v[4] };

    if (v[2] == v[4])
        return { 4, v[4] };
    if (v[1] == v[3])
        return { 4, v[3] };
    if (v[0] == v[2])
        return { 4, v[2] };

    if (v[3] == v[4] && v[1] == v[2])
        return { 3, v[4], v[2], v[0] };
    if (v[3] == v[4] && v[0] == v[1])
        return { 3, v[4], v[1], v[2] };
    if (v[2] == v[3] && v[0] == v[1])
        return { 3, v[3], v[1], v[4] };

    if (v[3] == v[4])
        return { 2, v[4], v[2], v[1], v[0] };
    if (v[2] == v[3])
        return { 2, v[3], v[4], v[1], v[0] };
    if (v[1] == v[2])
        return { 2, v[2], v[4], v[3], v[0] };
    if (v[0] == v[1])
        return { 2, v[1], v[4], v[3], v[2] };

    return { 1, v[4], v[3], v[2], v[1], v[0] };
}

bool solve() {
    static string values = "23456789TJQKA";

    vector<int> aValue(5), bValue(5);
    vector<char> aSuit(5), bSuit(5);

    for (int i = 0; i < 5; i++) {
        char value;
        if (!(cin >> value >> aSuit[i]))
            return 0;
        aValue[i] = values.find(value);
    }

    for (int i = 0; i < 5; i++) {
        char value;
        cin >> value >> bSuit[i];
        bValue[i] = values.find(value);
    }

    sort(aValue.begin(), aValue.end());
    sort(aSuit.begin(), aSuit.end());
    vector<int> aStrength = getHandStrength(aValue, aSuit);

    sort(bValue.begin(), bValue.end());
    sort(bSuit.begin(), bSuit.end());
    vector<int> bStrength = getHandStrength(bValue, bSuit);

    if (aStrength < bStrength)
        cout << "White wins.\n";
    else if (aStrength > bStrength)
        cout << "Black wins.\n";
    else
        cout << "Tie.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}