class LockingTree {
    vector<int> parent, locked;
    vector<vector<int>> graph;
    
    bool hasLockedAncestor(int v) {
        if (locked[v] != -1)
            return 1;
        
        if (parent[v] != -1 && hasLockedAncestor(parent[v]))
            return 1;
        
        return 0;
    }
    
    bool hasLockedDescendant(int v) {
        if (locked[v] != -1)
            return 1;
        
        for (int to : graph[v])
            if (hasLockedDescendant(to))
                return 1;
        
        return 0;
    }
    
    void unlockDescendants(int v) {
        locked[v] = -1;
        for (int to : graph[v])
            unlockDescendants(to);
    }
    
public:
    LockingTree(vector<int> &parent) : parent(parent) {
        locked.assign(parent.size(), -1);
        graph.resize(parent.size());
        for (int v = 1; v < parent.size(); v++)
            graph[parent[v]].push_back(v);
    }
    
    bool lock(int v, int user) {
        if (locked[v] != -1)
            return 0;
        
        locked[v] = user;
        return 1;
    }
    
    bool unlock(int v, int user) {
        if (locked[v] != user)
            return 0;
        
        locked[v] = -1;
        return 1;
    }
    
    bool upgrade(int v, int user) {
        if (locked[v] != -1 || hasLockedAncestor(v) || !hasLockedDescendant(v))
            return 0;
        
        unlockDescendants(v);
        locked[v] = user;
        return 1;
    }
};