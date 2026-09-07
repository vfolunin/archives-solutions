#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCost(vector<int> &a, int start) {
    long long cost = 0;
    for (int i = 0; i < a.size(); i++)
        cost += abs(a[i] - start - i);
    return cost;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l = -3e5, r = 3e5;
    while (l + 100 < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (getCost(a, m1) < getCost(a, m2))
            r = m2;
        else
            l = m1;
    }

    long long res = 1e18;
    for (int i = l; i <= r; i++)
        res = min(res, getCost(a, i));

    cout << res;
}