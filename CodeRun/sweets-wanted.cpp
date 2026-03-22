#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    vector<long long> p = a;
    partial_sum(p.begin(), p.end(), p.begin());

    long long res = a.back() * a.size() - p.back();
    for (int i = 0; i + 1 < a.size(); i++)
        res = min<long long>(res, a[i] * (i + 1) - p[i] + a.back() * (a.size() - i - 1) - (p.back() - p[i]));

    cout << res;
}