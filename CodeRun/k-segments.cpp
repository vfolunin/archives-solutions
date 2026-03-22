#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int size, int limit) {
    long long to = -1e9, count = 0;
    for (int value : a) {
        if (to < value) {
            to = value + size;
            count++;
        }
    }
    return count <= limit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    
    int l = -1, r = 2e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m, limit))
            r = m;
        else
            l = m;
    }

    cout << r;
}