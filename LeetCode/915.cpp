class Solution {
public:
    int partitionDisjoint(vector<int> &a) {
        vector<int> suffixMin(a.size());
        suffixMin.back() = a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            suffixMin[i] = min(a[i], suffixMin[i + 1]);
        
        int prefixMax = a[0];
        for (int i = 1; 1; i++) {
            if (prefixMax <= suffixMin[i])
                return i;
            prefixMax = max(prefixMax, a[i]);
        }
        
        return -1;
    }
};