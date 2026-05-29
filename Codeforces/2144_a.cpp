#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> p = a;
    partial_sum(p.begin(), p.end(), p.begin());

    for (int l = 1; l < a.size(); l++) {
        for (int r = l; r + 1 < a.size(); r++) {
            int mod1 = getSum(p, 0, l - 1) % 3;
            int mod2 = getSum(p, l, r) % 3;
            int mod3 = getSum(p, r + 1, p.size() - 1) % 3;

            if (mod1 == mod2 && mod1 == mod3 || mod1 != mod2 && mod1 != mod3 && mod2 != mod3) {
                cout << l << " " << r + 1 << "\n";
                return;
            }
        }
    }

    cout << "0 0\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}