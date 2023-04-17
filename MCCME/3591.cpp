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
    
    int pointCount;
    cin >> pointCount;

    vector<int> ys(pointCount);
    for (int &y : ys) {
        int x;
        cin >> x >> y;
    }

    vector<int> pl(pointCount);
    for (int i = 1; i < pl.size(); i++)
        pl[i] = pl[i - 1] + (ys[i - 1] < ys[i] ? ys[i] - ys[i - 1] : 0);

    vector<int> pr(pointCount);
    for (int i = pr.size() - 2; i >= 0; i--)
        pr[i] = pr[i + 1] + (ys[i] > ys[i + 1] ? ys[i] - ys[i + 1] : 0);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        if (l <= r)
            cout << pl[r] - pl[l] << "\n";
        else
            cout << pr[r] - pr[l] << "\n";
    }
}