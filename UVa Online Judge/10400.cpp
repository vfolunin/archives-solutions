#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> v(size + 1);
    for (int &x : v)
        cin >> x;

    vector<string> can(v.size(), string(64001, '?'));
    can[0][v[0] + 32000] = ' ';
    for (int i = 0; i + 1 < v.size(); i++) {
        for (long long res = -32000; res <= 32000; res++) {
            if (can[i][res + 32000] == '?')
                continue;
            if (-32000 <= res + v[i + 1] && res + v[i + 1] <= 32000)
                can[i + 1][res + v[i + 1] + 32000] = '+';
            if (-32000 <= res - v[i + 1] && res - v[i + 1] <= 32000)
                can[i + 1][res - v[i + 1] + 32000] = '-';
            if (-32000 <= res * v[i + 1] && res * v[i + 1] <= 32000)
                can[i + 1][res * v[i + 1] + 32000] = '*';
            if (v[i + 1] && res % v[i + 1] == 0 && -32000 <= res / v[i + 1] && res / v[i + 1] <= 32000)
                can[i + 1][res / v[i + 1] + 32000] = '/';
        }
    }

    if (can[v.size() - 2][v.back() + 32000] == '?') {
        cout << "NO EXPRESSION\n";
    } else {
        string ops = "=";
        for (int i = v.size() - 2, res = v.back(); i; i--) {
            ops += can[i][res + 32000];
            if (can[i][res + 32000] == '+')
                res -= v[i];
            else if (can[i][res + 32000] == '-')
                res += v[i];
            else if (can[i][res + 32000] == '*')
                res /= v[i];
            else
                res *= v[i];
        }
        reverse(ops.begin(), ops.end());
        for (int i = 0; i < ops.size(); i++)
            cout << v[i] << ops[i];
        cout << v.back() << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}