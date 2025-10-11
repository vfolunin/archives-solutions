#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int getR(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());

    unordered_set<int> values;
    do {
        for (int i = 1; i < s.size(); i++)
            values.insert(stoi(s.substr(i)));
    } while (next_permutation(s.begin(), s.end()));

    int r = 0;
    for (int value : values)
        r += isPrime(value);
    return r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = n - 1, resR = getR(res);
    for (int i = n - 2; i > 0; i--) {
        int r = getR(i);
        if (resR < r) {
            res = i;
            resR = r;
        }
    }

    cout << res;
}