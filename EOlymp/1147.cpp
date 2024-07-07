#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPPhi() {
    const int N = 200001;

    vector<long long> pPhi(N);
    for (int i = 0; i < N; i++)
        pPhi[i] = i;

    for (int i = 2; i < N; i++)
        if (pPhi[i] == i)
            for (int j = i; j < N; j += i)
                pPhi[j] -= pPhi[j] / i;

    for (int i = 1; i < N; i++)
        pPhi[i] += pPhi[i - 1];

    return pPhi;
}

long long sum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> pPhi = getPPhi();

    long long res = 0;
    for (int from = 1, to; from <= n; from = to + 1) {
        int quot = n / from;
        to = n / quot;
        res += sum(pPhi, from, to) * (n / from) * (n / from);
    }
    res = (res - n * (n + 1) / 2) / 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}