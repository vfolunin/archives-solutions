#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isArithmetic(vector<int> &p) {
    if (p.size() <= 2)
        return 1;
    for (int i = 2; i < p.size(); i++)
        if (p[i] - p[i - 1] != p[1] - p[0])
            return 0;
    return 1;
}

void solve() {
    int size;
    cin >> size;

    vector<int> p(size);
    for (int &x : p)
        cin >> x;

    if (isArithmetic(p)) {
        cout << "arithmetic\n";
        return;
    }

    sort(p.begin(), p.end());

    if (isArithmetic(p))
        cout << "permuted arithmetic\n";
    else
        cout << "non-arithmetic\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}