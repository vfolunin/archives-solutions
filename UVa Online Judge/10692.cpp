#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPhi() {
    const int N = 10001;

    vector<int> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

int binPow(int x, int p, int mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * (x % mod) % mod;
    int r = binPow(x, p / 2, mod);
    return r * r % mod;
}

int powerTower(vector<int> &tower, int i, int mod) {
    if (i + 1 == tower.size())
        return tower[i] % mod;
    static vector<int> phi = getPhi();
    int p = phi[mod] + powerTower(tower, i + 1, phi[mod]);
    return binPow(tower[i], p, mod);
}

bool solve(int test) {
    string s;
    cin >> s;

    if (s == "#")
        return 0;

    int mod = stoi(s);

    int size;
    cin >> size;

    vector<int> tower(size);
    for (int &x : tower)
        cin >> x;

    int res = powerTower(tower, 0, mod);

    cout << "Case #" << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}