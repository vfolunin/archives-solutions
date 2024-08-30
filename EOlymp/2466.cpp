#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Trie {
    struct Vertex {
        bool isTerminal = false;
        map<char, Vertex> next;
        Vertex *sufLink = 0;
        map<char, Vertex *> autLink;
    } root;

    bool dfs(Vertex *v, map<Vertex *, int> &visited) {
        visited[v] = 1;
        for (char c = '0'; c <= '1'; c++) {
            Vertex *to = v->autLink[c];
            if (!to->isTerminal)
                if (!visited.count(to) && dfs(to, visited) || visited[to] == 1)
                    return true;
        }
        visited[v] = 2;
        return false;
    }

public:
    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s)
            v = &v->next[c];
        v->isTerminal = true;
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

            for (char c = '0'; c <= '1'; c++) {
                if (v->next.count(c))
                    v->autLink[c] = &v->next[c];
                else
                    v->autLink[c] = (v == &root ? &root : v->sufLink->autLink[c]);
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
    }

    bool check() {
        map<Vertex *, int> visited;
        return dfs(&root, visited);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    Trie trie;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        trie.add(s);
    }

    trie.build();

    cout << (trie.check() ? "TAK" : "NIE");
}