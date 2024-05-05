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

    int aSize, bSize, limit;
    cin >> aSize >> bSize >> limit;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int res = 0;
    for (int ai = 0, bi = 0; ai < a.size(); ai++) {
        while (bi < b.size() && b[bi] < a[ai] - limit)
            bi++;
        if (bi < b.size() && b[bi] <= a[ai] + limit) {
            res++;
            bi++;
        }
    }

    cout << res;
}