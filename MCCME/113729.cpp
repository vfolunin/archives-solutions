#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<unordered_set<int>> &graph, int v, unordered_set<int> &visited) {
    visited.insert(v);
    for (int to : graph[v])
        if (!visited.contains(to))
            dfs(graph, to, visited);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int wordCount, letterCount;
    cin >> wordCount >> letterCount;

    vector<vector<int>> words(wordCount);
    for (vector<int> &word : words) {
        int size;
        cin >> size;

        word.resize(size);
        for (int &letter : word) {
            cin >> letter;
            letter--;
        }
    }

    unordered_set<int> starts;
    vector<unordered_set<int>> graph(letterCount);
    for (int i = 0; i + 1 < words.size(); i++) {
        int j = 0;
        while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j])
            j++;

        if (j == words[i + 1].size() && words[i].size() > words[i + 1].size()) {
            cout << "No";
            return 0;
        }

        if (j < words[i].size()) {
            if (words[i][j] < words[i + 1][j])
                graph[words[i + 1][j]].insert(words[i][j]);
            else
                starts.insert(words[i][j]);
        }
    }

    unordered_set<int> capitalized;
    for (int start : starts)
        dfs(graph, start, capitalized);

    for (vector<int> &word : words)
        for (int &letter : word)
            if (capitalized.contains(letter))
                letter -= letterCount;

    for (int i = 0; i + 1 < words.size(); i++) {
        if (words[i] > words[i + 1]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n" << capitalized.size() << "\n";
    for (int letter : capitalized)
        cout << letter + 1 << " ";
}