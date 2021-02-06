#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int chimpCount;
    if (!(cin >> chimpCount))
        return 0;

    vector<long long> chimpHeight(chimpCount);
    for (long long &h : chimpHeight)
        cin >> h;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long h;
        cin >> h;

        auto l = lower_bound(chimpHeight.begin(), chimpHeight.end(), h);
        if (l != chimpHeight.begin())
            cout << *prev(l);
        else
            cout << "X";
        cout << " ";

        auto r = upper_bound(chimpHeight.begin(), chimpHeight.end(), h);
        if (r != chimpHeight.end())
            cout << *r;
        else
            cout << "X";
        cout << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}