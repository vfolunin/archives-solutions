#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string, int> dijkstra(map<string, set<pair<string, int>>> &graph, const string &startVertex) {
    map<string, int> dist;
    dist[startVertex] = 0;
    set<pair<int, string>> q = { { dist[startVertex], startVertex } };

    while (!q.empty()) {
        string v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (!dist.count(to) || dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

bool solve() {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    string lang1, lang2;
    cin >> lang1 >> lang2;

    map<string, set<pair<string, int>>> graph;
    for (char c = 'a'; c <= 'z'; c++)
        graph["#start"].insert({ lang1 + "_" + c, 0 });

    for (int i = 0; i < wordCount; i++) {
        string langA, langB, word;
        cin >> langA >> langB >> word;
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != word[0]) {
                graph[langA + "_" + c].insert({ langB + "_" + word[0], word.size() });
                graph[langB + "_" + c].insert({ langA + "_" + word[0], word.size() });
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
        graph[lang2 + "_" + c].insert({ "#finish", 0 });

    map<string, int> dist = dijkstra(graph, "#start");
    if (dist.count("#finish") && dist["#finish"])
        cout << dist["#finish"] << "\n";
    else
        cout << "impossivel\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}