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

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    vector<vector<int>> res;

    for (int ka = 0; ka * a <= n; ka++)
        for (int kb = 0; ka * a + kb * b <= n; kb++)
            if ((n - ka * a - kb * b) % c == 0)
                res.push_back({ ka, kb, (n - ka * a - kb * b) / c });

    cout << res.size() << "\n";
    for (vector<int> &row : res) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}