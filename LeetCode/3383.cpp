struct Graph {
    vector<vector<int>> graph, graphR;
    vector<int> visited, order, sccOf;

    Graph(int vertexCount) :
        graph(vertexCount), graphR(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs1(to);
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        sccOf[v] = component;
        for (int to : graphR[v])
            if (sccOf[to] == -1)
                dfs2(to, component);
    }

    int getSourceCount() {
        visited.assign(graph.size(), 0);
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs1(v);
        reverse(order.begin(), order.end());

        sccOf.assign(graph.size(), -1);
        int sccCount = 0;
        for (int v : order)
            if (sccOf[v] == -1)
                dfs2(v, sccCount++);

        vector<int> isSource(sccCount, 1);
        for (int v = 0; v < graph.size(); v++)
            for (int to : graph[v])
                if (sccOf[v] != sccOf[to])
                    isSource[sccOf[to]] = 0;

        return count(isSource.begin(), isSource.end(), 1);
    }
};

class Solution {
public:
    int minRunesToAdd(int vertexCount, vector<int> &sources, vector<int> &edgeFrom, vector<int> &edgeTo) {
        Graph graph(vertexCount + 1);

        for (int source : sources)
            graph.addEdge(vertexCount, source);
        
        for (int i = 0; i < edgeFrom.size(); i++)
            graph.addEdge(edgeFrom[i], edgeTo[i]);
        
        return graph.getSourceCount() - 1;
    }
};