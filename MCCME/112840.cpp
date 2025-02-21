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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    set<pair<int, int>> pairs;
    for (int i = 0; i + 1 < a.size(); i++)
        pairs.insert({ a[i], a[i + 1] });

    int res = size;
    for (int i = 0; i + 1 < b.size(); i++)
        res -= pairs.count({ b[i], b[i + 1] });

    cout << res;
}