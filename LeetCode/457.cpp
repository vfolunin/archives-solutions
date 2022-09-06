class Solution {
    bool rec(vector<int> &a, int v, vector<int> &visited, bool positive, int cycleSize) {
        if (positive != (a[v] > 0))
            return 0;
        
        visited[v] = cycleSize;
        
        int len = a.size(), to = ((v + a[v]) % len + len) % len;
        if (visited[to] == 1 && cycleSize > 1 || !visited[to] && rec(a, to, visited, positive, cycleSize + 1))
            return 1;
        
        visited[v] = 0;
        return 0;
    }
    
public:
    bool circularArrayLoop(vector<int> &a) {
        vector<int> visited(a.size());
        
        for (int v = 0; v < a.size(); v++)
            if (rec(a, v, visited, a[v] > 0, 1))
                return 1;
        
        return 0;
    }
};