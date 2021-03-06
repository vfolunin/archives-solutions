#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPhi() {
    const int N = 50001;

    vector<int> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

vector<int> prepare() {
    vector<int> res = getPhi();
    for (int i = 1; i < res.size(); i++)
        res[i] += res[i - 1];
    for (int i = 0; i < res.size(); i++)
        res[i] = 2 * res[i] - 1;
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> res = prepare();

    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}