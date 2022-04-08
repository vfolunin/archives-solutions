#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

struct Graph {
    int sccCount = 0;
    map<string, set<string>> g, gr;
    set<string> visited;
    vector<string> order;
    map<string, int> sccIndexOf;

    void addEdge(string &a, string &b) {
        g[a].insert(b);
        gr[b].insert(a);
    }

    void dfs1(const string &v) {
        visited.insert(v);
        for (const string &to : g[v])
            if (!visited.count(to))
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(const string &v, int component) {
        visited.insert(v);
        sccIndexOf[v] = component;
        for (const string &to : gr[v]) {
            if (!visited.count(to))
                dfs2(to, component);
        }
    }

    void findScc() {
        for (auto &[v, _] : g)
            if (!visited.count(v))
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (string &v : order)
            if (!visited.count(v))
                dfs2(v, sccCount++);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    cin.ignore();

    Graph graph;

    for (int i = 0; i < vertexCount; i++) {
        vector<string> tokens = readWords();
        tokens[0] += "#";
        graph.addEdge(tokens[0], tokens[1]);
        for (int j = 1; j < tokens.size(); j++)
            graph.addEdge(tokens[j], tokens[0]);
    }

    graph.findScc();

    map<int, int> sccSize;
    int maxSccSize = 0;

    for (auto &[v, scc] : graph.sccIndexOf) {
        sccSize[scc] += v.back() == '#';
        maxSccSize = max(maxSccSize, sccSize[scc]);
    }

    cout << vertexCount - maxSccSize;
}