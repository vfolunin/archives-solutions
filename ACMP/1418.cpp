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

    int res = -1;
    sort(a.begin(), a.end());
    do {
        if (a.front() && a.back() % 2 == 0)
            res = max(res, a[0] * 100 + a[1] * 10 + a[2]);
    } while (next_permutation(a.begin(), a.end()));

    if (res != -1)
        cout << res;
    else
        cout << "Impossible";
}