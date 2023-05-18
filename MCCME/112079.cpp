#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCatalan(int n) {
    vector<long long> res = { 1 };
    for (int i = 1; i <= n; i++) {
        res.push_back(0);
        for (int j = 0; j < i; j++)
            res.back() += res[j] * res[i - 1 - j];
    }
    return res.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << getCatalan(n);
}