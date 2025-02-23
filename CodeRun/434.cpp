#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int sum, vector<int> &res) {
    if (!sum) {
        for (int i = 0; i < res.size(); i++)
            cout << (i ? " + " : "") << res[i];
        cout << "\n";
        return;
    }

    for (int value = 1; value <= (res.empty() ? sum : min(sum, res.back())); value++) {
        res.push_back(value);
        rec(sum - value, res);
        res.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> res;
    rec(n, res);
}