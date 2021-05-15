#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    const int N = 2e7 + 1;
    vector<long long> res(N, 1);
    
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            res[j] += i;
    
    for (int i = 2; i < N; i++)
        res[i] += res[i - 1];

    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> res = prepare();

    cout << res[n] - 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}