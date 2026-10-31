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

    vector<int> a(size + 1);
    for (int &value : a)
        cin >> value;

    int limit = 32000;
    vector<string> can(a.size(), string(2 * limit + 1, '?'));
    can[0][a[0] + limit] = ' ';

    for (int i = 0; i + 1 < a.size(); i++) {
        for (long long res = -limit; res <= limit; res++) {
            if (can[i][res + limit] == '?')
                continue;
            if (-limit <= res + a[i + 1] && res + a[i + 1] <= limit)
                can[i + 1][res + a[i + 1] + limit] = '+';
            if (-limit <= res - a[i + 1] && res - a[i + 1] <= limit)
                can[i + 1][res - a[i + 1] + limit] = '-';
            if (-limit <= res * a[i + 1] && res * a[i + 1] <= limit)
                can[i + 1][res * a[i + 1] + limit] = '*';
            if (a[i + 1] && res % a[i + 1] == 0 && -limit <= res / a[i + 1] && res / a[i + 1] <= limit)
                can[i + 1][res / a[i + 1] + limit] = '/';
        }
    }

    if (can[a.size() - 2][a.back() + limit] == '?') {
        cout << "NO EXPRESSION\n";
    } else {
        string ops = "=";
        for (int i = a.size() - 2, res = a.back(); i; i--) {
            ops += can[i][res + limit];
            if (can[i][res + limit] == '+')
                res -= a[i];
            else if (can[i][res + limit] == '-')
                res += a[i];
            else if (can[i][res + limit] == '*')
                res /= a[i];
            else
                res *= a[i];
        }
        reverse(ops.begin(), ops.end());
        for (int i = 0; i < ops.size(); i++)
            cout << a[i] << ops[i];
        cout << a.back() << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}