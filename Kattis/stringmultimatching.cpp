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
        vector<int> termIndexes;
        vector<Vertex *> next;
        Vertex *sufLink = 0, *termLink = 0;

        Vertex() : next(128) {}
    };
    list<Vertex> vertices;
    Vertex *root = 0;
    int stringCount = 0;

public:
    Trie() : vertices(1), root(&*vertices.begin()) {}

    void insert(const string &s) {
        Vertex *v = root;
        for (char c : s) {
            if (!v->next[c]) {
                vertices.emplace_back();
                v->next[c] = &vertices.back();
            }
            v = v->next[c];
        }
        v->termIndexes.push_back(stringCount++);
    }

    void build() {
        queue<Vertex *> q;
        root->sufLink = root;
        q.push(root);

        while (!q.empty()) {
            Vertex *v = q.front();
            q.pop();

            for (int ci = 0; ci < v->next.size(); ci++) {
                if (v->next[ci]) {
                    v->next[ci]->sufLink = (v == root ? root : v->sufLink->next[ci]);
                    q.push(v->next[ci]);
                }
            }

            for (int ci = 0; ci < v->next.size(); ci++)
                if (!v->next[ci])
                    v->next[ci] = (v == root ? root : v->sufLink->next[ci]);

            v->termLink = (!v->sufLink->termIndexes.empty() ? v->sufLink : v->sufLink->termLink);
        }
    }

    vector<vector<int>> check(const string &s) {
        vector<vector<int>> res(stringCount);

        Vertex *v = root;
        for (int i = 0; i < s.size(); i++) {
            v = v->next[s[i]];

            if (!v->termIndexes.empty() || v->termLink)
                for (Vertex *term = (!v->termIndexes.empty() ? v : v->termLink); term; term = term->termLink)
                    for (int termIndex : term->termIndexes)
                        res[termIndex].push_back(i);
        }

        return res;
    }
};

bool solve() {
    int patternCount;
    if (!(cin >> patternCount))
        return 0;
    cin.ignore();

    vector<string> patterns(patternCount);
    Trie trie;
    for (string &pattern : patterns) {
        getline(cin, pattern);
        trie.insert(pattern);
    }

    string text;
    getline(cin, text);

    trie.build();
    vector<vector<int>> res = trie.check(text);

    for (int i = 0; i < res.size(); i++) {
        for (int index : res[i])
            cout << index - patterns[i].size() + 1 << " ";
        cout << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}