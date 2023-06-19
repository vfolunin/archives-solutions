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

    vector<pair<int, int>> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    int res = a[0].second, resDist = a[1].first - a[0].first;
    for (int i = 1; i < a.size(); i++) {
        int dist = a[i].first - a[i - 1].first;
        if (resDist > dist) {
            resDist = dist;
            res = a[i].second;
        }
    }

    cout << res;
}