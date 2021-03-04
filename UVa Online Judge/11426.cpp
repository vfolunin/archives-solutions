#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPhi() {
    const int N = 4000001;

    vector<int> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> phi = getPhi();

    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i] * (n / i) * (n / i);
    res = (res - n * (n + 1) / 2) / 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}