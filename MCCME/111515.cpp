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

    int size, minTime;
    cin >> size >> minTime;

    vector<pair<int, int>> a(size);
    for (auto &[time, to] : a)
        cin >> time >> to;

    sort(a.begin(), a.end());

    cout << lower_bound(a.begin(), a.end(), pair<int, int>(minTime, 1e9))->second;
}