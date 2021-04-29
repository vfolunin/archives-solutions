#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


class Trie {
    struct Vertex {
        map<char, Vertex> next;
        int size = 0;
    } root;

    void dfs(Vertex *v, int depth, int &res) {
        res = max(res, depth * v->size);
        for (auto &[_, to] : v->next)
            dfs(&to, depth + 1, res);
    }

public:
    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s) {
            v->size++;
            v = &v->next[c];
        }
        v->size++;
    }

    int dfs() {
        int res = 0;
        dfs(&root, 0, res);
        return res;
    }
};

void solve() {
    int stringCount;
    cin >> stringCount;

    Trie trie;
    for (int i = 0; i < stringCount; i++) {
        string s;
        cin >> s;
        trie.add(s);
    }

    cout << trie.dfs() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}