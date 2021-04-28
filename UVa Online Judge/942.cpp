#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int num, den;
    cin >> num >> den;

    map<int, int> seen;
    string frac;

    for (int i = 0, mod = num % den; 1; i++) {
        if (seen.count(mod)) {
            if (mod) {
                frac.insert(seen[mod], 1, '(');
                frac += ')';
            } else {
                if (frac.size() > 1)
                    frac.pop_back();
            }
            break;
        }

        seen[mod] = i;
        frac += mod * 10 / den + '0';
        mod = mod * 10 % den;
    }

    cout << num / den << "." << frac << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}