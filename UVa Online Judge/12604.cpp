#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

struct Hasher {
    unsigned long long f = 131, fi = 281629680514649643;
    vector<unsigned long long> p, pi, h;

    Hasher(const string &s) {
        p.resize(s.size());
        pi.resize(s.size());
        h.resize(s.size());

        p[0] = pi[0] = 1;
        h[0] = s[0];

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * f;
            pi[i] = pi[i - 1] * fi;
            h[i] = h[i - 1] + (p[i] * s[i]);
        }
    }

    unsigned long long getHash(int l, int r) {
        unsigned long long res = h[r];
        if (l) {
            res -= h[l - 1];
            res *= pi[l];
        }
        return res;
    }
};

void rotateCypher(string &word, string &alphabet) {
    for (char &c : word)
        c = alphabet[(alphabet.find(c) + 1) % alphabet.size()];
}

void solve() {
    string alphabet, word, text;
    cin >> alphabet >> word >> text;

    Hasher hasher(text);
    unordered_map<unsigned long long, int> hashes;
    for (int l = 0, r = word.size() - 1; r < text.size(); l++, r++)
        hashes[hasher.getHash(l, r)]++;

    vector<int> res;
    for (int i = 0; i < alphabet.size(); i++) {
        unsigned long long hash = Hasher(word).getHash(0, word.size() - 1);
        if (auto it = hashes.find(hash); it != hashes.end() && it->second == 1)
            res.push_back(i);
        rotateCypher(word, alphabet);
    }

    if (res.empty()) {
        cout << "no solution\n";
    } else if (res.size() == 1) {
        cout << "unique: " << res[0] << "\n";
    } else {
        cout << "ambiguous: ";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? " " : "\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}