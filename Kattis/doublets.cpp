#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> from(graph.size(), -2);
    queue<int> q;

    q.push(start);
    from[start] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (from[to] == -2) {
                from[to] = v;
                q.push(to);
            }
        }
    }

    if (from[finish] == -2)
        return {};

    vector<int> path;
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> words;
    unordered_map<string, int> wordId;
    while (1) {
        string word;
        getline(cin, word);

        if (word == "")
            break;

        words.push_back(word);
        wordId[word] = wordId.size();
    }

    vector<vector<int>> graph(words.size());
    for (int i = 0; i < words.size(); i++) {
        for (int pos = 0; pos < words[i].size(); pos++) {
            char c = words[i][pos];
            for (words[i][pos] = 'a'; words[i][pos] <= 'z'; words[i][pos]++) {
                if (!wordId.count(words[i]))
                    continue;
                int j = wordId[words[i]];
                if (i < j) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
            words[i][pos] = c;
        }
    }

    string a, b;
    for (int i = 0; cin >> a >> b; i++) {
        vector<int> path = bfs(graph, wordId[a], wordId[b]);
        if (i)
            cout << "\n";
        if (path.empty()) {
            cout << "No solution.\n";
        } else {
            for (int v : path)
                cout << words[v] << "\n";
        }
    }
}