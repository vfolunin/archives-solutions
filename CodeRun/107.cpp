#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int teamCount, int teamSize, int dist) {
    int teams = 0;
    for (int from = 0; from < a.size(); ) {
        if (from + teamSize - 1 < a.size() && a[from + teamSize - 1] - a[from] <= dist) {
            teams++;
            from += teamSize;
        } else {
            from++;
        }
    }
    return teams >= teamCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, teamCount, teamSize;
    cin >> size >> teamCount >> teamSize;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, teamCount, teamSize, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}