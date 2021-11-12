#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getF() {
    vector<long long> f = { 1, 1 };
    for (int i = 2; i <= 40; i++)
        f.push_back(f[i - 2] + f[i - 1]);
    return f;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> f = getF();

    cout << f[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}