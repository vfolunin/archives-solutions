#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long f, fi, mod;
    vector<long long> p, pi, h;

    Hasher(const string &s) : f(29), fi(758620695), mod(1e9 + 7) {
        p.resize(s.size());
        pi.resize(s.size());
        h.resize(s.size());

        p[0] = pi[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * f) % mod;
            pi[i] = (pi[i - 1] * fi) % mod;
            h[i] = (h[i - 1] + (p[i] * (s[i] - 'a' + 1)) % mod) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l) {
            res = (res - h[l - 1] + mod) % mod;
            res = (res * pi[l]) % mod;
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<string> words;
    string word;
    while (cin >> word)
        words.insert(word);

    set<unsigned long long> hashes;
    for (const string &word : words) {
        Hasher hasher(word);
        hashes.insert(hasher.getHash(0, word.size() - 1));
    }

    for (const string &word : words) {
        Hasher hasher(word);
        for (int i = 0; i + 1 < word.size(); i++) {
            if (hashes.count(hasher.getHash(0, i)) &&
                hashes.count(hasher.getHash(i + 1, word.size() - 1))) {
                cout << word << "\n";
                break;
            }
        }
    }
}