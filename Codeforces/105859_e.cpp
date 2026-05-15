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

    int infectTime, cureTime;
    string s;
    cin >> infectTime >> cureTime >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'H')
            continue;

        int l = i;
        while (0 <= l && s[l] == 'H')
            l--;

        int r = i;
        while (r < s.size() && s[r] == 'H')
            r++;

        int time = 1e9;
        if (0 <= l && s[l] == 'I')
            time = min(time, (i - l) * infectTime);
        if (r < s.size() && s[r] == 'I')
            time = min(time, (r - i) * infectTime);

        if (cureTime <= time) {
            cout << "CURED";
            return 0;
        }
    }

    cout << "ALL INFECTED";
}