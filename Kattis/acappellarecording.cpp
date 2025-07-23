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

    int size, diff;
    cin >> size >> diff;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int from = -2e9, res = 0;
    for (int value : a) {
        if (from + diff < value) {
            from = value;
            res++;
        }
    }

    cout << res;
}