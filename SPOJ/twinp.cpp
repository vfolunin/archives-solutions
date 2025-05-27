#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    const int N = 2e7;
    vector<int> isPrime(N, 1);
    vector<int> twins;

    for (int i = 2; i * i < N; i++)
        if (isPrime[i])
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;

    for (int i = 2; i + 2 < N; i++)
        if (isPrime[i] && isPrime[i + 2])
            twins.push_back(i);
    return twins;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> twins = prepare();

    cout << twins[n - 1] << " " << twins[n - 1] + 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}