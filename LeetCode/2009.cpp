class Solution {
public:
    int minOperations(vector<int> &a) {
        sort(a.begin(), a.end());
        unordered_map<int, int> count;
        int res = 1e9;
        
        for (int l = 0, r = 0; r < a.size(); l++) {
            while (r < a.size() && a[r] - a[l] < a.size()) {
                count[a[r]]++;
                r++;
            }
            
            res = min<int>(res, a.size() - count.size());
            
            if (!--count[a[l]])
                count.erase(a[l]);
        }
        
        return res;
    }
};