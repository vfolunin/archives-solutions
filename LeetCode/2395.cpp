class Solution {
public:
    bool findSubarrays(vector<int> &a) {
        unordered_set<int> seen;
        
        for (int i = 0; i + 1 < a.size(); i++) {
            if (seen.count(a[i] + a[i + 1]))
                return 1;
            seen.insert(a[i] + a[i + 1]);
        }
        
        return 0;
    }
};