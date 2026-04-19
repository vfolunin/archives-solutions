class Solution {
public:
    int firstStableIndex(vector<int> &a, int limit) {
        vector<int> lMax = a;
        for (int i = 1; i < a.size(); i++)
            lMax[i] = max(lMax[i - 1], a[i]);
        
        vector<int> rMin = a;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            rMin[i] = min(rMin[i + 1], a[i]);
        
        for (int i = 0; i < a.size(); i++)
            if (lMax[i] - rMin[i] <= limit)
                return i;
        return -1;
    }
};