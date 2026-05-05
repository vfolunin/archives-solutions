#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int vertexCount) {
        for (int v = 0; v < vertexCount; v++)
            parent.push_back(v);
    }

    int findRoot(int v) {
        return parent[v] == v ? v : parent[v] = findRoot(parent[v]);
    }

    bool areConnected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    void connect(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB)
            return;
        if (rand() % 2)
            parent[rootA] = rootB;
        else
            parent[rootB] = rootA;
    }
};

struct Compressor {
    unordered_map<string, int> compressed;

    int compress(const string &s) {
        if (auto it = compressed.find(s); it != compressed.end())
            return it->second;
        return compressed[s] = compressed.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ruleCount;
    cin >> ruleCount;

    set<string> words;
    vector<pair<string, string>> isRules, notRules;
    for (int i = 0; i < ruleCount; i++) {
        string a, op, b;
        cin >> a >> op >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        words.insert(a);
        words.insert(b);

        if (op == "is")
            isRules.push_back({ a, b });
        else
            notRules.push_back({ a, b });
    }

    DSU dsu(words.size());
    Compressor compressor;

    for (auto &[a, b] : isRules)
        dsu.connect(compressor.compress(a), compressor.compress(b));

    string root = *words.begin();
    for (const string &word : words) {
        int size = min({ (int)root.size(), (int)word.size(), 3 });
        if (root.substr(0, size) == word.substr(0, size))
            dsu.connect(compressor.compress(root), compressor.compress(word));
        else
            root = word;
    }

    for (auto &[a, b] : notRules) {
        if (dsu.areConnected(compressor.compress(a), compressor.compress(b))) {
            cout << "wait what?";
            return 0;
        }
    }

    cout << "yes";
}