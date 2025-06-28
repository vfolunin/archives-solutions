#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    const long long MOD = 1e9 + 7;
    long long res = 1;
    for (auto &[_, count] : count)
        res = res * (count + 1) % MOD;

    cout << (res - 1 + MOD) % MOD;
}