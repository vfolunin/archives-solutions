#include <iostream>
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
    string word;

    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

struct Compressor {
    map<string, int> ids;
    vector<string> words;

    int getId(string &word) {
        if (!ids.count(word)) {
            ids[word] = ids.size();
            words.push_back(word);
        }
        return ids[word];
    }

    string getWord(int id) {
        return words[id];
    }
};

struct Graph {
    int vertexCount, sccCount;
    map<int, set<int>> g, gr, gc;
    set<int> visited;
    vector<int> order;
    map<int, int> sccIndexOf, sccSize;

    Graph(int vertexCount) : vertexCount(vertexCount), sccCount(0) {}

    void addEdge(int a, int b) {
        g[a].insert(b);
        gr[b].insert(a);
    }

    void dfs1(int v) {
        visited.insert(v);
        for (int to : g[v])
            if (!visited.count(to))
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        visited.insert(v);
        sccIndexOf[v] = component;
        sccSize[component]++;
        for (int to : gr[v]) {
            if (!visited.count(to))
                dfs2(to, component);
        }
    }

    void condense() {
        for (int v = 0; v < vertexCount; v++)
            if (!visited.count(v))
                dfs1(v);
        reverse(order.begin(), order.end());

        visited.clear();
        for (int v : order)
            if (!visited.count(v))
                dfs2(v, sccCount++);

        for (int v = 0; v < vertexCount; v++)
            for (int to : g[v])
                if (sccIndexOf[v] != sccIndexOf[to])
                    gc[sccIndexOf[v]].insert(sccIndexOf[to]);
    }

    void dfs3(int v) {
        visited.insert(v);
        for (int to : gc[v])
            if (!visited.count(to))
                dfs3(to);
    }

    vector<int> getRes() {
        condense();

        visited.clear();
        for (int scc = 0; scc < sccCount; scc++)
            if (!visited.count(scc) && sccSize[scc] > 1)
                dfs3(scc);

        vector<int> res;
        for (int v = 0; v < vertexCount; v++)
            if (visited.count(sccIndexOf[v]))
                res.push_back(v);
        return res;
    }
};

bool solve() {
    int wordCount;
    cin >> wordCount;
    cin.ignore();

    if (!wordCount)
        return 0;

    Compressor compressor;
    Graph graph(wordCount);

    for (int i = 0; i < wordCount; i++) {
        vector<string> words = readWords();
        int v = compressor.getId(words[0]);

        for (int j = 1; j < words.size(); j++) {
            int to = compressor.getId(words[j]);
            graph.addEdge(v, to);
        }
    }

    vector<string> res;
    for (int v : graph.getRes())
        res.push_back(compressor.getWord(v));
    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}