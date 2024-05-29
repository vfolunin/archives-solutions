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
    sort(a.begin(), a.end());

    vector<int> b(size);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    vector<int> c(size);
    for (int &value : c)
        cin >> value;
    sort(c.begin(), c.end());

    long long res = 0;
    for (int value : b) {
        long long aCount = lower_bound(a.begin(), a.end(), value) - a.begin();
        long long cCount = c.end() - upper_bound(c.begin(), c.end(), value);
        res += aCount * cCount;
    }
    cout << res;
}