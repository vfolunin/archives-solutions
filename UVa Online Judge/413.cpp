#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> a;
    while (1) {
        int x;
        cin >> x;

        if (!x)
            break;

        a.push_back(x);
    }

    if (a.empty())
        return 0;

    double upSum = 0, upCount = 0, downSum = 0, downCount = 0;

    int l = 0, r = 0;
    while (r < a.size() && a[l] == a[r])
        r++;
    bool isUp = r < a.size() && a[l] < a[r];

    while (r < a.size()) {        
        while (r < a.size() && (isUp && a[r - 1] <= a[r] || !isUp && a[r - 1] >= a[r]))
            r++;

        if (isUp) {
            upSum += r - l - 1;
            upCount++;
        } else {
            downSum += r - l - 1;
            downCount++;
        }

        isUp ^= 1;
        l = r - 1;
    }

    cout << "Nr values = " << a.size() << ":  ";
    cout << fixed << upSum / (upCount ? upCount : 1) << " ";
    cout << downSum / (downCount ? downCount : 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}