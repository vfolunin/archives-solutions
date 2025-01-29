#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, capacity, flow = 0;

        Edge(int a, int b, int capacity) :
            a(a), b(b), capacity(capacity) {}

        int other(int v) const {
            return v == a ? b : a;
        }

        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }

        void addFlowTo(int v, int deltaFlow) {
            flow += (v == b ? deltaFlow : -deltaFlow);
        }
    };

    vector<Edge> edges;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> edgeTo;

    void bfs(int start) {
        queue<int> q;
        visited[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int e : graph[v]) {
                int to = edges[e].other(v);
                if (!visited[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    bool hasPath(int start, int finish) {
        visited.assign(visited.size(), 0);
        bfs(start);
        return visited[finish];
    }

    int bottleneckCapacity(int start, int finish) {
        int bCapacity = 1e9;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }

    void addFlow(int start, int finish, int deltaFlow) {
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, deltaFlow);
    }

    Graph(int vertexCount) :
        graph(vertexCount), visited(vertexCount), edgeTo(vertexCount) {}

    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        graph[from].push_back(edges.size() - 1);
        graph[to].push_back(edges.size() - 1);
    }

    long long maxFlow(int start, int finish) {
        long long flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = bottleneckCapacity(start, finish);
            addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cardCount;
    cin >> cardCount;

    vector<string> cards(cardCount);
    unordered_map<string, vector<int>> cardIndexes;
    for (int i = 0; i < cardCount; i++) {
        cin >> cards[i];
        cardIndexes[cards[i]].push_back(i);
    }

    Graph graph(1 + 26 * 26 + 26 + 1);
    for (auto &[card, indexes] : cardIndexes) {
        int from = 1 + (card[0] - 'a') * 26 + (card[1] - 'a');
        graph.addEdge(0, from, indexes.size());
        int to1 = 1 + 26 * 26 + (card[0] - 'a');
        int to2 = 1 + 26 * 26 + (card[1] - 'a');
        graph.addEdge(from, to1, 1e9);
        graph.addEdge(from, to2, 1e9);
    }

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        int from = 1 + 26 * 26 + i;
        int to = 1 + 26 * 26 + 26;
        int capacity = count(s.begin(), s.end(), 'a' + i);
        graph.addEdge(from, to, capacity);
    }

    int flow = graph.maxFlow(0, 1 + 26 * 26 + 26);
    if (flow != s.size()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    unordered_map<char, vector<int>> usedCardIndexes;
    for (auto &[a, b, capacity, flow] : graph.edges) {
        if (flow && 0 < a && a < 1 + 26 * 26) {
            char letter = b - 1 - 26 * 26 + 'a';
            int cardCode = a - 1;
            string card = string(1, cardCode / 26 + 'a') + string(1, cardCode % 26 + 'a');
            for (int i = 0; i < flow; i++) {
                if (letter == card[0])
                    usedCardIndexes[letter].push_back(cardIndexes[card].back() + 1);
                else
                    usedCardIndexes[letter].push_back(-cardIndexes[card].back() - 1);
                cardIndexes[card].pop_back();
            }
        }
    }

    for (char c : s) {
        cout << usedCardIndexes[c].back() << " ";
        usedCardIndexes[c].pop_back();
    }
}