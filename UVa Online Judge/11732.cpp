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
        int size = 0, end = 0;
    } root;

    long long add(const string &s) {
        Vertex *v = &root;
        long long res = v->size;
        v->size++;

        for (const char &c : s) {
            v = &v->next[c];
            res += v->size * 2;
            v->size++;
        }

        res += v->end;
        v->end++;
        return res;
    }
};

bool solve(int test) {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    Trie trie;
    long long res = 0;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        res += trie.add(word);
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}