#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<bool> getIsPrime() {
    const int N = 4e7;
    vector<bool> isPrime(N, 1);
    for (int i = 2; i < N; i++)
        if (isPrime[i])
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
    return isPrime;
}

vector<int> prepare() {
    const int N = 1e6 + 1;
    vector<int> res(N);
    static vector<bool> isPrime = getIsPrime();
    for (int i = 1; i < N; i++)
        res[i] = res[i - 1] + isPrime[3 * i + 7];
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();
    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}