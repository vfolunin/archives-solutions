#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int rec(int n) {
    static vector<int> memo(1e5 + 1, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    if (n < 10 || isPrime(n))
        return res = 2;

    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
        if (rec(stoi(s.substr(0, i) + s.substr(i + 1))) == 2)
            return res = 1;

    return res = 2;
}

void solve() {
    int n;
    cin >> n;

    cout << (rec(n) == 1 ? "Aayush\n" : "Akash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}