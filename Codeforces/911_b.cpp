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

    int n, a, b;
    cin >> n >> a >> b;

    int res = 0;
    for (int ta = 1, tb = n - 1; ta < n; ta++, tb--)
        res = max(res, min(a / ta, b / tb));

    cout << res;
}