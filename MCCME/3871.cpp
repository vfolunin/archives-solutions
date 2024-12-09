#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    unsigned long long x = 31;
    vector<unsigned long long> p, h;

    Hasher(const string &s) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x;
            h[i] = h[i - 1] * x + s[i] - 'a' + 1;
        }
    }

    unsigned long long getHash(int l, int r) {
        unsigned long long res = h[r];
        if (l)
            res -= p[r - l + 1] * h[l - 1];
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    map<unsigned long long, set<int>> wordsWithHash;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        Hasher hasher(word);
        for (int size = 1; size <= word.size(); size++) {
            unsigned long long hash = hasher.getHash(0, size - 1);
            if (hash == hasher.getHash(word.size() - size, word.size() - 1))
                wordsWithHash[hash].insert(i);
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string word;
        cin >> word;

        Hasher hasher(word);
        unsigned long long hash = hasher.getHash(0, word.size() - 1);

        cout << (wordsWithHash.count(hash) ? wordsWithHash[hash].size() : 0) << "\n";
    }
}