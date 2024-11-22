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

    int sum, a, b;
    cin >> sum >> a >> b;

    vector<pair<int, int>> res;
    for (int ka = 0; ka * a <= sum; ka++)
        if ((sum - ka * a) % b == 0)
            res.push_back({ ka, (sum - ka * a) / b });
    
    cout << res.size() << "\n";
    for (auto &[ka, kb] : res)
        cout << ka << " " << kb << "\n";
}