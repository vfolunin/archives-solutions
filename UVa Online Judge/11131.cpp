#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (c != ',') {
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

void dfs1(map<string, set<string>> &graph, const string &v) {
    for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        dfs1(graph, *it);
    cout << v << "\n";
}

void dfs2(map<string, set<string>> &graph, const string &v) {
    for (auto it = graph[v].rbegin(); it != graph[v].rend(); it++)
        dfs2(graph, *it);
    cout << v << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, set<string>> graph;
    string root;

    while (1) {
        string line;
        if (!(cin >> line))
            break;

        vector<string> words = split(line);

        if (root.empty())
            root = words[0];

        for (int i = 1; i < words.size(); i++)
            graph[words[0]].insert(words[i]);
    }

    cout << "2\n\n";
    dfs1(graph, root);
    cout << "\n";
    dfs2(graph, root);
}