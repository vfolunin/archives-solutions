class Solution {
    int getCycleSize(int v, vector<int> &to, vector<int> &visited) {
        unordered_map<int, int> seen;
        
        for (int i = 0; v != -1 && !visited[v]; i++) {
            visited[v] = 1;
            seen[v] = i;
            
            if (seen.count(to[v]))
                return i - seen[to[v]] + 1;
            
            v = to[v];
        }
        
        return -1;
    }
    
public:
    int longestCycle(vector<int> &to) {
        vector<int> visited(to.size());
        int maxCycleSize = -1;
        
        for (int v = 0; v < to.size(); v++)
            if (!visited[v])
                maxCycleSize = max(maxCycleSize, getCycleSize(v, to, visited));
        
        return maxCycleSize;
    }
};