#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
using namespace std;

class Trie {
    struct Vertex {
        bitset<150> isTerminal = false;
        map<char, Vertex> next;
        Vertex *sufLink = nullptr;
        map<char, Vertex *> autLink;
    } root;

public:
    void add(const string &s, int i) {
        Vertex *v = &root;
        for (const char &c : s)
            v = &v->next[c];
        v->isTerminal.set(i);
    }

    void build() {
        queue<Vertex *> q;
        root.sufLink = &root;
        q.push(&root);

        while (!q.empty()) {
            Vertex *v = q.front();
            q.pop();

            for (auto &[c, to] : v->next) {
                to.sufLink = (v == &root ? &root : v->sufLink->autLink[c]);
                q.push(&to);
            }

            for (char c = 'a'; c <= 'z'; c++) {
                if (v->next.count(c))
                    v->autLink[c] = &v->next[c];
                else
                    v->autLink[c] = (v == &root ? &root : v->sufLink->autLink[c]);
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
    }

    vector<int> check(const string &s) {
        vector<int> res(150);
        Vertex *v = &root;
        for (const char &c : s) {
            v = v->autLink[c];
            if (v->isTerminal.any())
                for (int i = 0; i < 150; i++)
                    res[i] += v->isTerminal[i];
        }
        return res;
    }
};

bool solve() {
    int patternCount;
    cin >> patternCount;

    if (!patternCount)
        return 0;

    vector<string> patterns(patternCount);
    Trie trie;
    for (int i = 0; i < patternCount; i++) {
        cin >> patterns[i];
        trie.add(patterns[i], i);
    }
    trie.build();

    string text;
    cin >> text;

    vector<int> res = trie.check(text);
    int maxRes = *max_element(res.begin(), res.end());

    cout << maxRes << "\n";
    for (int i = 0; i < patternCount; i++)
        if (res[i] == maxRes)
            cout << patterns[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}