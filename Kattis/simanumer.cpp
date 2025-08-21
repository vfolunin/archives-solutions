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

    int getSize(const string &s) {
        Node *n = &root;
        for (char c : s) {
            if (!n->next.count(c))
                return 0;
            n = &n->next[c];
        }
        return n->size;
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

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        cout << trie.getSize(s) << "\n";
    }
}