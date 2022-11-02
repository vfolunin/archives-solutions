class TreeAncestor {
    vector<vector<int>> graph, ancestor;
    vector<int> depth;
    int root;
    
    void dfs(int v, int parent) {
        depth[v] = (v == parent ? 0 : depth[parent] + 1);

        ancestor[v][0] = parent;
        for (int i = 1; i < ancestor[v].size(); i++)
            ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

        for (int to : graph[v])
            dfs(to, v);
    }
    
public:
    TreeAncestor(int vertexCount, vector<int> &parent) :
        graph(vertexCount), ancestor(vertexCount, vector<int>(20)), depth(vertexCount) {
        for (int v = 0; v < vertexCount; v++) {
            if (parent[v] == -1)
                root = v;
            else
                graph[parent[v]].push_back(v);
        }
        
        dfs(root, root);
    }
    
    int getKthAncestor(int v, int k) {
        if (depth[v] < k)
            return -1;
        
        for (int bit = ancestor[v].size() - 1; bit >= 0; bit--)
            if (k & (1 << bit))
                v = ancestor[v][bit];
        
        return v;
    }
};