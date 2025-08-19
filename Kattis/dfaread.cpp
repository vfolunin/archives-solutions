#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertexCount, alphabetSize, start, finishCount;
    string alphabet;
    cin >> vertexCount >> alphabetSize >> start >> finishCount >> alphabet;
    start--;

    unordered_set<int> finishes;
    for (int i = 0; i < finishCount; i++) {
        int finish;
        cin >> finish;
        finish--;
        finishes.insert(finish);
    }

    vector<unordered_map<char, int>> graph(vertexCount);
    for (int v = 0; v < graph.size(); v++) {
        for (char c : alphabet) {
            cin >> graph[v][c];
            graph[v][c]--;
        }
    }
    
    int queryCount;
    cin >> queryCount;
    cin.ignore();

    for (int i = 0; i < queryCount; i++) {
        string s;
        getline(cin, s);

        int v = start;
        for (char c : s)
            v = graph[v][c];

        cout << (finishes.count(v) ? "accept\n" : "reject\n");
    }
}