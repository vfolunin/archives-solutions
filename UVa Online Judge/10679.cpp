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
        bitset<1000> isTerminal;
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

            for (char c0 : "aA") {
                for (char c = c0; c < c0 + 26; c++) {
                    if (v->next.count(c))
                        v->autLink[c] = &v->next[c];
                    else
                        v->autLink[c] = (v == &root ? &root : v->sufLink->autLink[c]);
                }
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
    }

    bitset<1000> check(const string &s) {
        Vertex *v = &root;
        bitset<1000> res;
        for (const char &c : s) {
            v = v->autLink[c];
            res |= v->isTerminal;
        }
        return res;
    }
};

void solve() {
    string text;
    cin >> text;

    int wordCount;
    cin >> wordCount;

    Trie t;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        t.add(word, i);
    }
    t.build();

    bitset<1000> found = t.check(text);
    for (int i = 0; i < wordCount; i++)
        cout << (found[i] ? "y\n" : "n\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}