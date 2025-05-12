#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    unordered_map<string, unordered_map<string, int>> graph;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        for (int i = 0; i + 3 < word.size(); i++)
            graph[word.substr(i, 3)][word.substr(i + 1, 3)]++;
        graph[word.substr(word.size() - 3)];
    }

    int edgeCount = 0;
    for (auto &[v, adj] : graph)
        edgeCount += adj.size();

    cout << graph.size() << "\n" << edgeCount << "\n";
    for (auto &[v, adj] : graph)
        for (auto &[to, w] : adj)
            cout << v << " " << to << " " << w << "\n";
}