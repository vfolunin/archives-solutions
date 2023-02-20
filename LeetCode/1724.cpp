struct DSU {
    vector<int> id;

    DSU() {}

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Graph {
    vector<map<int, int>> graph;
    vector<vector<int>> ancestor, maxWeight;
    vector<int> l, r;
    int timer;

    Graph() {}

    Graph(int vertexCount) :
        graph(vertexCount),
        ancestor(vertexCount),
        maxWeight(vertexCount),
        l(vertexCount),
        r(vertexCount) {}

    void addEdge(int a, int b, int w) {
        graph[a][b] = w;
        graph[b][a] = w;
    }

    void dfs(int v, int parent) {
        l[v] = ++timer;

        ancestor[v].push_back(parent);
        maxWeight[v].push_back(v == parent ? -1e9 : graph[v][parent]);

        for (int i = 1; i < 20; i++) {
            ancestor[v].push_back(ancestor[ancestor[v][i - 1]][i - 1]);
            maxWeight[v].push_back(max(maxWeight[v].back(), maxWeight[ancestor[v][i - 1]][i - 1]));
        }

        for (auto &[to, _] : graph[v])
            if (!l[to])
                dfs(to, v);

        r[v] = ++timer;
    }

    void prepare(int root) {
        timer = 0;
        dfs(root, root);
    }

    bool isAncestor(int a, int b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }

    int lca(int a, int b) {
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;
        for (int i = 19; i >= 0; i--)
            if (!isAncestor(ancestor[a][i], b))
                a = ancestor[a][i];
        return ancestor[a][0];
    }

    int maxWeightOnPathToLca(int a, int b) {
        int res = -1e9;
        for (int i = 19; i >= 0; i--) {
            if (isAncestor(a, ancestor[b][i])) {
                res = max(res, maxWeight[b][i]);
                b = ancestor[b][i];
            }
        }
        return res;
    }

    int maxWeightOnPath(int a, int b) {
        int l = lca(a, b);
        int ma = maxWeightOnPathToLca(l, a);
        int mb = maxWeightOnPathToLca(l, b);
        return max(ma, mb);
    }
};

class DistanceLimitedPathsExist {
    DSU dsu;
    Graph graph;

public:
    DistanceLimitedPathsExist(int vertexCount, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        dsu = DSU(vertexCount);
        graph = Graph(vertexCount);

        for (vector<int> &edge : edges) {
            if (!dsu.connected(edge[0], edge[1])) {
                dsu.merge(edge[0], edge[1]);
                graph.addEdge(edge[0], edge[1], edge[2]);
            }
        }

        for (int v = 0; v < vertexCount; v++)
            if (dsu.find(v) == v)
                graph.prepare(v);
    }
    
    bool query(int a, int b, int limit) {
        return dsu.connected(a, b) && graph.maxWeightOnPath(a, b) < limit;
    }
};