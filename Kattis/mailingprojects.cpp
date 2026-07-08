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

    vector<pair<int, int>> pairs(size);
    for (auto &[t1, t2] : pairs) {
        int tPass;
        cin >> t1 >> tPass >> t2;
        t1 += tPass;
    }

    sort(pairs.begin(), pairs.end());

    long long time = 0;
    for (auto &[t1, t2] : pairs)
        time = max<long long>(time, t1) + t2;

    cout << time;
}