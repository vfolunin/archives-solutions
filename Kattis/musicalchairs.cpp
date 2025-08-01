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
    for (int i = 0; i < a.size(); i++) {
        a[i].first = i + 1;
        cin >> a[i].second;
    }

    int pos = 0;
    while (a.size() > 1) {
        pos = (pos + a[pos].second - 1) % a.size();
        a.erase(a.begin() + pos);
        pos %= a.size();
    }

    cout << a[0].first;
}