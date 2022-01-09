#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(vector<vector<int>> &graph, int pos, string &substring) {
    for (int c = 0; c < 26; c++) {
        if (graph[pos][c] != -1) {
            substring.push_back('a' + c);
            cout << substring << "\n";
            print(graph, graph[pos][c], substring);
            substring.pop_back();
        }
    }
}

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    vector<vector<int>> graph(word.size() + 1, vector<int>(26, -1));
    for (int i = word.size() - 1; i >= 0; i--) {
        graph[i] = graph[i + 1];
        graph[i][word[i] - 'a'] = i + 1;
    }

    string substring;
    print(graph, 0, substring);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}