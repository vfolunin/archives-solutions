#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long reverse(long long n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoll(s);
}

vector<long long> prepare() {
    vector<long long> f = { 0, 1, 2 };
    for (int i = 3; i <= 60; i++)
        f.push_back(reverse(f[i - 2]) + reverse(f[i - 1]));
    return f;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> f = prepare();

    cout << f[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}