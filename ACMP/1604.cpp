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

    long long v, t1, a1, t2, a2;
    cin >> v >> t1 >> a1 >> t2 >> a2;

    long long res = v;

    v += t1 * a1;
    res = max(res, v);

    v += t2 * a2;
    res = max(res, v);

    cout << res;
}