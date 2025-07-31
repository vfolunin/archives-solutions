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
        int value = -1;
    } root;

    void insert(const string &s, int value) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->value = value;
    }

    int toDec(const string &s, int base) {
        int res = 0;
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            if (n->value != -1) {
                res = res * base + n->value;
                n = &root;
            }
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int base;
    cin >> base;

    Trie trie;
    for (int i = 0; i < base; i++) {
        string s;
        cin >> s;

        trie.insert(s, i);
    }

    string s;
    cin >> s;

    cout << trie.toDec(s, base);
}