#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

vector<int> prepare() {
    vector<int> isCubeFree(1e6, 1), cubeFree = { 0, 1 };
    for (int i = 2; i < isCubeFree.size(); i++) {
        if (isCubeFree[i]) {
            cubeFree.push_back(i);
            for (long long j = 1LL * i * i * i; j < isCubeFree.size(); j += i * i * i)
                isCubeFree[j] = 0;
        }
    }
    return cubeFree;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<int> cubeFree = prepare();
    int pos = lower_bound(cubeFree.begin(), cubeFree.end(), n) - cubeFree.begin();

    cout << "Case " << test << ": ";
    if (pos == cubeFree.size() || cubeFree[pos] != n)
        cout << "Not Cube Free\n";
    else
        cout << pos << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}