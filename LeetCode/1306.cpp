class Solution {
public:
    bool canReach(vector<int> &a, int v) {
        if (!a[v])
            return 1;
        
        int jump = a[v];
        a[v] = -1;
        
        return (0 <= v - jump && a[v - jump] != -1 && canReach(a, v - jump) ||
                v + jump < a.size() && a[v + jump] != -1 && canReach(a, v + jump)); 
    }
};