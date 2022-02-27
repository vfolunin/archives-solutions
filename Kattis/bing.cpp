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

public:
    int add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s) {
            v->size++;
            v = &v->next[c];
        }
        return v->size++;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    Trie trie;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        cout << trie.add(word) << "\n";
    }
}