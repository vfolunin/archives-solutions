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

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    vector<int> b(3);
    for (int &value : b)
        cin >> value;

    sort(b.begin(), b.end());
    int res = 0;

    do {
        res = max(res, a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
    } while (next_permutation(b.begin(), b.end()));

    cout << res;
}