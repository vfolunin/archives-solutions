class Solution {
    int getCycleSize(int v, vector<int> &to, vector<int> &visited) {
        visited[v] = 1;
        return visited[to[v]] ? 1 : 1 + getCycleSize(to[v], to, visited);
    }
    
public:
    int arrayNesting(vector<int> &to) {
        vector<int> visited(to.size());
        int res = 0;
        
        for (int v = 0; v < to.size(); v++)
            res = max(res, getCycleSize(v, to, visited));
        
        return res;
    }
};