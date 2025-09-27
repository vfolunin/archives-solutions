#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isThreebonacci(long long n) {
    if (n % 3 == 0)
        return 1;
    string s = to_string(n);
    return s.find('3') != -1;
}

vector<long long> prepare() {
    long long a, b = 1, c = 2;
    vector<long long> res;
    while (res.size() < 60) {
        a = b;
        b = c;
        c = a + b;
        if (isThreebonacci(c))
            res.push_back(c);
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> res = prepare();

    cout << res[n - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}