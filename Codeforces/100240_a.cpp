#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Vertex {
        map<char, Vertex> next;
        bool isTerminal;
    } root;

    bool add(const string &s) {
        Vertex *v = &root;
        bool res = 1;

        for (const char &c : s) {
            v = &v->next[c];
            res &= !v->isTerminal;
        }

        v->isTerminal = 1;
        return res & v->next.empty();
    }
};

void solve() {
    int stringCount;
    cin >> stringCount;

    Trie trie;
    bool res = 1;

    for (int i = 0; i < stringCount; i++) {
        string s;
        cin >> s;
        res &= trie.add(s);
    }

    cout << (res ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}