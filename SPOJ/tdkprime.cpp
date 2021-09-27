#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 9e7;
    static bool isComposite[N];
    for (int i = 2; i * i <= N; i++)
        if (!isComposite[i])
            for (int j = i * i; j < N; j += i)
                isComposite[j] = 1;

    static vector<int> primes;
    primes.reserve(5e6 + 1);
    for (int i = 2; i < N; i++)
        if (!isComposite[i])
            primes.push_back(i);
    return primes;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> primes = getPrimes();

    cout << primes[n - 1] << "\n";
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