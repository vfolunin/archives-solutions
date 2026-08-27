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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> input(n), output(n);
    for (int &x : input)
        cin >> x;

    const int MOD = 1e4 + 1;
    for (int a = 0; a < MOD; a++) {
        for (int b = 0; b < MOD; b++) {
            bool ok = 1;
            for (int i = 0, x = input[0]; ok && i < input.size(); i++) {
                ok &= x == input[i];
                output[i] = x = (a * x + b) % MOD;
                x = (a * x + b) % MOD;
            }
            if (ok) {
                for (int x : output)
                    cout << x << "\n";
                return 0;
            }
        }
    }
}