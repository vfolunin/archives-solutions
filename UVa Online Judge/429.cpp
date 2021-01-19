#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isEdge(string &a, string &b) {
    if (a.size() != b.size())
        return 0;
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
        diff += a[i] != b[i];
    return diff == 1;
}

void solve(int test) {
    vector<string> words;
    map<string, int> wordIndex;
    while (1) {
        string word;
        cin >> word;
        if (word == "*")
            break;
        wordIndex[word] = words.size();
        words.push_back(word);
    }

    vector<vector<int>> graph(words.size());
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (isEdge(words[i], words[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    if (test)
        cout << "\n";

    cin.ignore();
    while (1) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;

        stringstream ss(line);
        string a, b;
        ss >> a >> b;

        vector<int> dist(words.size(), -1);
        dist[wordIndex[a]] = 0;
        queue<int> q;
        q.push(wordIndex[a]);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        cout << a << " " << b << " " << dist[wordIndex[b]] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}