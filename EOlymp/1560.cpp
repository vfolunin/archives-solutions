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

    vector<int> res(1e6 + 1);
    for (int i = 2; i < res.size(); i++) {
        res[i] = res[i - 1] + 1;
        if (i % 2 == 0)
            res[i] = min(res[i], res[i / 2] + 1);
        if (i % 3 == 0)
            res[i] = min(res[i], res[i / 3] + 1);
    }

    for (int n; cin >> n; )
        cout << res[n] << "\n";
}