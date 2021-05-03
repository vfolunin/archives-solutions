#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> words;
    map<string, int> wordId;

    while (1) {
        string word;
        cin >> word;

        if (word == "--")
            break;

        words.push_back(word);
        wordId[word] = wordId.size();
    }
    
    DSU dsu(words.size());
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (words[i].size() != words[j].size())
                continue;
            int diff = 0;
            for (int k = 0; k < words[i].size() && diff <= 1; k++)
                diff += words[i][k] != words[j][k];
            if (diff == 1)
                dsu.merge(i, j);
        }
    }

    string a, b;
    while (cin >> a >> b)
        cout << (dsu.connected(wordId[a], wordId[b]) ? "Yes\n" : "No\n");
}