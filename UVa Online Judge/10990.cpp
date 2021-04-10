#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPhi() {
    const int N = 2e6 + 10;

    vector<int> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

vector<long long> prepare() {
    vector<int> phi = getPhi();

    vector<long long> depth(phi.size());
    for (int i = 2; i < depth.size(); i++)
        depth[i] = depth[phi[i]] + 1;

    for (int i = 1; i < depth.size(); i++)
        depth[i] += depth[i - 1];

    return depth;
}

void solve() {
    int l, r;
    cin >> l >> r;

    static vector<long long> p = prepare();

    cout << p[r] - p[l - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}