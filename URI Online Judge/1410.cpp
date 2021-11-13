#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aCount, dCount;
    cin >> aCount >> dCount;

    if (!aCount && !dCount)
        return 0;

    vector<int> a(aCount);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> d(dCount);
    for (int &x : d)
        cin >> x;
    sort(d.begin(), d.end());

    cout << (a[0] < d[1] ? "Y\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}