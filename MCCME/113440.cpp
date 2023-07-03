#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    int a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<vector<long long>>> res(a + 1, vector<vector<long long>>(b + 1, vector<long long>(c + 1, n)));
    for (int ka = 0; ka <= a; ka++) {
        for (int kb = 0; kb <= b; kb++) {
            for (int kc = 0; kc <= c; kc++) {
                if (ka)
                    res[ka][kb][kc] = min(res[ka][kb][kc], res[ka - 1][kb][kc] / 2);
                if (kb)
                    res[ka][kb][kc] = min(res[ka][kb][kc], (res[ka][kb - 1][kc] + 1) / 2);
                if (kc)
                    res[ka][kb][kc] = min(res[ka][kb][kc], max((res[ka][kb][kc - 1] - 1) / 2, 0LL));
            }
        }
    }

    cout << res[a][b][c];
}