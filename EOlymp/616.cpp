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

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 1; i + 1 < a.size(); i++)
        res = max(res, (a[i] - a.front()) * (a.back() - a[i]));

    cout << res;
}