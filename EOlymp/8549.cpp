#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare(int n) {
    vector<int> primeDivisorCount(n + 1), res;

    for (int i = 2; i < primeDivisorCount.size(); i++) {
        if (!primeDivisorCount[i]) {
            for (int j = i; j < primeDivisorCount.size(); j += i)
                primeDivisorCount[j]++;
        } else if (primeDivisorCount[i] >= 3) {
            res.push_back(i);
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare(4e6);
    cout << res[n - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}