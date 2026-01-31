#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    static long long getHash(const string &s, long long factor = 31, long long mod = 1e9 + 7) {
        vector<long long> p(1, 1);
        for (int i = 1; i < s.size(); i++)
            p.push_back(p[i - 1] * factor % mod);

        vector<long long> h(1, s[0] == 'G');
        for (int i = 1; i < s.size(); i++)
            h.push_back((h[i - 1] + (s[i] == 'G') * p[i]) % mod);
        return h.back();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int factor, mod, targetHash, size;
    cin >> factor >> mod >> targetHash >> size;

    int found = 0, minHash = mod, maxHash = -1;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        int hash = Hasher::getHash(s, factor, mod);

        if (hash == targetHash) {
            if (!found)
                cout << "FOUND\n";
            found = 1;
            cout << s << "\n";
        }

        minHash = min(minHash, hash);
        maxHash = max(maxHash, hash);
    }

    if (!found)
        cout << "NOT FOUND\n" << minHash << " " << maxHash;
}