class Solution {
    pair<int, int> getCoords(int label) {
        int level = -1;
        for (int l = label; l; l /= 2)
            level++;
        
        int width = 1 << level, vertex = label - width;
        if (level % 2)
            vertex = width - 1 - vertex;
        
        return { level, vertex };
    }
    
    int getLabel(int level, int vertex) {
        int width = 1 << level;
        if (level % 2)
            vertex = width - 1 - vertex;
        return width + vertex;
    }
    
public:
    vector<int> pathInZigZagTree(int label) {        
        auto [level, vertex] = getCoords(label);
        
        vector<int> path(level + 1);
        path[level] = label;
        
        for (level--, vertex /= 2; level >= 0; level--, vertex /= 2)
            path[level] = getLabel(level, vertex);
        
        return path;
    }
};