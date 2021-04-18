#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sopf(int n) {
    int res = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res += i;
            n /= i;
        }
    }
    if (n > 1)
        res += n;
    return res;
}

vector<int> prepare() {
    const int N = 5e5 + 1;
    vector<int> lsopf(N);
    for (int i = 2; i < N; i++) {
        int s = sopf(i);
        if (s == i)
            lsopf[i] = 1;
        else
            lsopf[i] = 1 + lsopf[s];
    }
    return lsopf;
}

void solve(int test) {
    int l, r;
    cin >> l >> r;
    if (l > r)
        swap(l, r);

    static vector<int> lsopf = prepare();

    int res = 1;
    for (int i = l; i <= r; i++)
        res = max(res, lsopf[i]);
    
    cout << "Case #" << test << ":\n" << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}