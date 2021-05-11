#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getCatalan() {
    vector<long long> res = { 1 };
    for (int i = 1; i <= 26; i++) {
        res.push_back(0);
        for (int j = 0; j < i; j++)
            res.back() += res[j] * res[i - 1 - j];
    }
    return res;
}

vector<long long> getSuperCatalan() {
    vector<long long> res = { 0, 1, 1 };
    for (int i = 3; i <= 26; i++)
        res.push_back((3 * (2 * i - 3) * res[i - 1] - (i - 3) * res[i - 2]) / i);
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> catalan = getCatalan();
    static vector<long long> superCatalan = getSuperCatalan();

    cout << superCatalan[n] - catalan[n - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}