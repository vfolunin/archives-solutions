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
        bool isTerminal = 0;
        map<char, Vertex> next;
        Vertex *sufLink = 0;
        map<char, Vertex *> autLink;
    } root;

public:
    void insert(const string &s) {
        Vertex *v = &root;
        for (char c : s)
            v = &v->next[c];
        v->isTerminal = 1;
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

            for (char c = 32; c <= 126; c++) {
                if (v->next.count(c))
                    v->autLink[c] = &v->next[c];
                else
                    v->autLink[c] = (v == &root ? &root : v->sufLink->autLink[c]);
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
    }

    bool check(const string &s) {
        Vertex *v = &root;
        for (char c : s) {
            v = v->autLink[c];
            if (v->isTerminal)
                return 1;
        }
        return 0;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.ignore();

    Trie trie;
    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        trie.insert(s);
    }

    trie.build();

    for (string s; getline(cin, s); )
        if (trie.check(s))
            cout << s << "\n";
}