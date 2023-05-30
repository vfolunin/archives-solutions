#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable() {}

    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(min(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getMin(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return min(st[level][l], st[level][r - levelWidth + 1]);
    }
};

class Graph {
    vector<vector<int>> graph;
    vector<int> l, r, depths;
    SparseTable sparseTable;

    void dfs(int v, int depth) {
        l[v] = depths.size();
        depths.push_back(depth);
        for (int to : graph[v]) {
            dfs(to, depth + 1);
            depths.push_back(depth);
        }
        r[v] = depths.size() - 1;
    }

public:
    Graph(int vertexCount) :
        graph(vertexCount),
        l(vertexCount),
        r(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
    }

    void prepare(int root) {
        dfs(root, 0);
        sparseTable = SparseTable(depths);
    }

    int lcaDepth(int a, int b) {
        return sparseTable.getMin(min(l[a], l[b]), max(r[a], r[b]));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    Graph graph(vertexCount);
    vector<int> isRoot(vertexCount, 1);

    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
        isRoot[b - 1] = 0;
    }

    graph.prepare(find(isRoot.begin(), isRoot.end(), 1) - isRoot.begin());

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << " " << graph.lcaDepth(a - 1, b - 1) << "\n";
    }
}