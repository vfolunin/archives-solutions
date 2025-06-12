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

    int size, penalty;
    cin >> size >> penalty;

    vector<pair<long long, int>> a(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<pair<long long, int>> b(size);
    for (int i = 0; i < b.size(); i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    for (int i = 0; i < b.size(); i++) {
        long long value;
        cin >> value;

        b[i].first = value - penalty * b[i].first;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> res(size);
    for (int i = 0; i < res.size(); i++)
        res[b[i].second] = a[i].second;

    for (int index : res)
        cout << index + 1 << " ";
}