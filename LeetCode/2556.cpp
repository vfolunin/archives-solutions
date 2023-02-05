struct Graph {
    vector<vector<int>> g;
    vector<int> visited, marked, depth, upDepth;
    vector<int> cutpoints;
	
    bool dfs1(int v, int finish) {
        visited[v] = 1; 
        marked[v] = v == finish;
        
        for (int to : g[v])
            if (!visited[to] && dfs1(to, finish))
                marked[v] = 1;
        
        return marked[v];
    }

    void dfs2(int v, int parent) {
        visited[v] = 1;
        depth[v] = (parent == -1 ? 0 : depth[parent] + 1);
        upDepth[v] = depth[v];
 
        for (int to : g[v]) {
            if (to == parent) {
                continue;
            } else if (!visited[to]) {
                dfs2(to, v);
                if (parent != -1 && upDepth[to] >= depth[v] && marked[to])
                    cutpoints.push_back(v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        marked.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool hasTwoPaths(int start, int finish) {
        dfs1(start, finish);
        if (!visited[finish])
            return 0;
        visited.assign(g.size(), 0);
        dfs2(start, -1);
        return cutpoints.empty();
    }
};

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        Graph graph(h * w);

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x])
                    continue;

                if (y + 1 < h && a[y + 1][x])
                    graph.addEdge(y * w + x, (y + 1) * w + x);

                if (x + 1 < w && a[y][x + 1])
                    graph.addEdge(y * w + x, y * w + x + 1);
            }
        }

        return !graph.hasTwoPaths(0, h * w - 1);
    }
};