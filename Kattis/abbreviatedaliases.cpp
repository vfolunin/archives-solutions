#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Node {
        map<char, Node> next;
        int size = 0;
    } root;

    void insert(const string &s) {
        Node *n = &root;
        for (char c : s) {
            n->size++;
            n = &n->next[c];
        }
        n->size++;
    }

    int getCompressedSize(Node *n) {
        if (n->size <= 1)
            return 0;

        int res = n->size;
        for (auto &[_, to] : n->next)
            res += getCompressedSize(&to);
        return res;
    }

    int getCompressedSize() {
        return getCompressedSize(&root);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    Trie trie;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        trie.insert(s);
    }

    cout << trie.getCompressedSize();
}