#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Original number was " << n << "\n";

    set<long long> seen;
    while (1) {
        string s = to_string(n);
        
        sort(s.rbegin(), s.rend());
        long long a = stoll(s);

        sort(s.begin(), s.end());
        long long b = stoll(s);

        n = a - b;
        cout << a << " - " << b << " = " << n << "\n";
        if (seen.count(n))
            break;
        seen.insert(n);
    }

    cout << "Chain length " << seen.size() + 1 << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}