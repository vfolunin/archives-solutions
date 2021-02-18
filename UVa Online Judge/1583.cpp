#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10;
        n /= 10;
    }
    return res + n;
}

vector<int> prepare() {
    const int N = 1e5 + 1;
    vector<int> res(N);

    for (int i = 1; i <= N; i++) {
        int j = i + digitSum(i);
        if (j < N && !res[j])
            res[j] = i;
    }

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