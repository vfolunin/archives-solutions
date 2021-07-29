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
        bool isWord = 0;
    } root;

    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s)
            v = &v->next[c];
        v->isWord = 1;
    }

    int dfs(Vertex *v, int length) {
        int res = v->isWord ? length : 0;
        for (auto &[_, to] : v->next)
            res += dfs(&to, length + (v->next.size() > 1 || v->isWord || v == &root));
        return res;
    }

    int dfs() {
        return dfs(&root, 0);
    }
};

bool solve() {
    int wordCount;
    if (!(cin >> wordCount))
        return 0;

    Trie words;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        words.add(word);
    }

    double res = (double)words.dfs() / wordCount;

    cout.precision(2);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}