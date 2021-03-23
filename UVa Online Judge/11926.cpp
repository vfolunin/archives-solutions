#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int oneTimeTaskCount, repeatingTaskCount;
    cin >> oneTimeTaskCount >> repeatingTaskCount;

    if (!oneTimeTaskCount && !repeatingTaskCount)
        return 0;

    vector<int> tasks(1000000);

    for (int i = 0; i < oneTimeTaskCount; i++) {
        int l, r;
        cin >> l >> r;
        for (int t = l; t < r; t++)
            tasks[t]++;
    }

    for (int i = 0; i < repeatingTaskCount; i++) {
        int l, r, period;
        cin >> l >> r >> period;
        for (int curL = l, curR = r; curL < tasks.size(); curL += period, curR += period)
            for (int t = curL; t < curR && t < tasks.size(); t++)
                tasks[t]++;
    }

    if (*max_element(tasks.begin(), tasks.end()) > 1)
        cout << "CONFLICT\n";
    else
        cout << "NO CONFLICT\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}