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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<pair<int, int>> b(bSize);
    for (int i = 0; i < bSize; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(b.begin(), b.end());

    for (int value : a) {
        int r = lower_bound(b.begin(), b.end(), make_pair(value, 0)) - b.begin(), l = r - 1;
        if (l == -1)
            cout << b[r].second + 1 << " ";
        else if (r == bSize)
            cout << b[l].second + 1 << " ";
        else if (value - b[l].first <= b[r].first - value)
            cout << b[l].second + 1 << " ";
        else
            cout << b[r].second + 1 << " ";
    }
}