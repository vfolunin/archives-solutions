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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<pair<int, int>> a(aSize);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i].first;
        a[i].first++;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());

    vector<pair<int, int>> b(bSize);
    for (int i = 0; i < b.size(); i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());

    vector<int> res(a.size(), -1);
    for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ai++) {
        if (a[ai].first <= b[bi].first) {
            res[a[ai].second] = b[bi].second;
            bi++;
        }
    }

    cout << res.size() - count(res.begin(), res.end(), -1) << "\n";
    for (int value : res)
        cout << value + 1 << " ";
}