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
        bool isTerminal = 0;
        int maxSize = 1;
        char maxC = 0;
    } root;

    void insert(const string &s) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->isTerminal = 1;
    }

    void prepare(Node *n) {
        if (!n)
            return;

        for (auto &[c, to] : n->next) {
            prepare(&to);
            n->maxSize = max(n->maxSize, 1 + to.maxSize);
        }

        for (auto &[c, to] : n->next) {
            if (n->maxSize == 1 + to.maxSize) {
                n->maxC = c;
                break;
            }
        }
    }

    void traverse(Node *n, string &path) {
        if (!n)
            return;

        if (n->isTerminal)
            path += "P";

        for (auto &[c, to] : n->next) {
            if (c == n->maxC)
                continue;

            path += c;
            traverse(&to, path);
            path += "-";
        }

        if (n->maxC) {
            path += n->maxC;
            traverse(&n->next[n->maxC], path);
            path += "-";
        }
    }

    string getPath() {
        prepare(&root);
        string path;
        traverse(&root, path);
        while (path.back() == '-')
            path.pop_back();
        return path;
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

        trie.insert(s);
    }

    string path = trie.getPath();

    cout << path.size() << "\n";
    for (char c : path)
        cout << c << "\n";
}