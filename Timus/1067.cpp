#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Vertex {
        map<string, Vertex> next;
    } root;

    void add(const vector<string> &path) {
        Vertex *v = &root;
        for (const string &dir : path)
            v = &v->next[dir];
    }

    void print(Vertex *v, int offset) {
        for (auto &[dir, to] : v->next) {
            cout << string(offset, ' ') << dir << "\n";
            print(&to, offset + 1);
        }
    }

    void print() {
        print(&root, 0);
    }
};

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != '\\') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

bool solve() {
    int pathCount;
    if (!(cin >> pathCount))
        return 0;

    Trie trie;
    for (int i = 0; i < pathCount; i++) {
        string path;
        cin >> path;
        trie.add(split(path));
    }

    trie.print();
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}