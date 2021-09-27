#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> cooks, int mealCount, int timeLimit) {
    for (int time : cooks)
        for (int sum = time, mul = 1; sum <= timeLimit; mul++, sum += mul * time)
            if (--mealCount <= 0)
                return 1;
    return 0;
}

void solve() {
    int mealCount, cookCount;
    cin >> mealCount >> cookCount;

    vector<int> cooks(cookCount);
    for (int &time : cooks)
        cin >> time;

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(cooks, mealCount, m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}