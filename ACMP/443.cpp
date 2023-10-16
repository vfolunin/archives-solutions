#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getHash(string &s, int factor, int mod) {
    int hash = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        hash = (hash * factor % mod + s[i] - '0') % mod;
    return hash;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stringCount, factor, mod;
    cin >> stringCount >> mod >> factor;

    map<int, int> hashCount;
    for (int i = 0; i < stringCount; i++) {
        string s;
        cin >> s;
        hashCount[getHash(s, factor, mod)]++;
    }

    int res = 0;
    for (auto &[hash, count] : hashCount)
        res += count * (count - 1) / 2;

    cout << res;
}