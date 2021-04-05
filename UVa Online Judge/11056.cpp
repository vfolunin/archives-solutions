#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string lower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

bool compare(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return lower(a.second) < lower(b.second);
}

bool solve() {
    int pilotCount;
    if (!(cin >> pilotCount))
        return 0;

    vector<pair<int, string>> times(pilotCount);
    for (auto &[time, name] : times) {
        string buf;
        int m, s, ms;
        cin >> name >> buf >> m >> buf >> s >> buf >> ms >> buf;
        time = m * 60000 + s * 1000 + ms;
    }

    sort(times.begin(), times.end(), compare);

    for (int i = 0; i < pilotCount; i += 2) {
        cout << "Row " << i / 2 + 1 << "\n";
        cout << times[i].second << "\n";
        if (i + 1 < pilotCount)
            cout << times[i + 1].second << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}