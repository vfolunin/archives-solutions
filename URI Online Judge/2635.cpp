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
        int count = 0, maxLength = 0;
    } root;

    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s) {
            v->count++;
            v->maxLength = max<int>(v->maxLength, s.size());
            v = &v->next[c];
        }
        v->count++;
        v->maxLength = max<int>(v->maxLength, s.size());
    }

    pair<int, int> get(string &s) {
        Vertex *v = &root;
        for (const char &c : s) {
            if (!v->next.count(c))
                return { -1, -1 };
            v = &v->next[c];
        }
        return { v->count, v->maxLength };
    }
};

bool solve() {
    int wordCount;
    if (!(cin >> wordCount))
        return 0;

    Trie trie;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        trie.add(word);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string word;
        cin >> word;

        auto [count, maxLength] = trie.get(word);
        if (count != -1)
            cout << count << " " << maxLength << "\n";
        else
            cout << "-1\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}