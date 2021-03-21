#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    const int N = 1e6 + 1;

    vector<int> divisorCount(N, 1);
    for (int i = 2; i < N; i++) {
        divisorCount[i]++;
        for (int j = 2 * i; j < N; j += i)
            divisorCount[j]++;
    }

    vector<int> res(N);
    res[0] = 1;
    for (int i = 1; i < N; i++)
        res[i] = (divisorCount[i] >= divisorCount[res[i - 1]] ? i : res[i - 1]);

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

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}