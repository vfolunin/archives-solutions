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

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    vector<long long> b(size);
    for (long long &value : b)
        cin >> value;

    int factor;
    cin >> factor;

    const long long MOD = 1e9 + 7;
    long long res = 0;
    for (int i = 0; i < size; i++)
        res = (res + a[i] * b[i]) % MOD;
    res = res * factor % MOD;

    cout << res;
}