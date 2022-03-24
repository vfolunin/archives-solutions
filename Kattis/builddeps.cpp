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

void dfs(map<string, set<string>> &graph, const string &v, set<string> &visited, vector<string> &order) {
    visited.insert(v);
    for (const string &to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited, order);
    order.push_back(v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    cin.ignore();

    map<string, set<string>> graph;
    for (int i = 0; i < vertexCount; i++) {
        vector<string> tokens = readWords();
        tokens[0].pop_back();
        for (int j = 1; j < tokens.size(); j++)
            graph[tokens[j]].insert(tokens[0]);
    }

    string start;
    cin >> start;

    set<string> visited;
    vector<string> order;
    dfs(graph, start, visited, order);
    reverse(order.begin(), order.end());

    for (string &v : order)
        cout << v << "\n";
}