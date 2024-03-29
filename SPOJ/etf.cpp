#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPhi() {
    const int N = 1e6 + 1;

    vector<long long> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> phi = getPhi();

    cout << phi[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}