class Solution {
public:
    int maxChunksToSorted(vector<int> &a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        
        unordered_multiset<int> as, bs;
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            as.insert(a[i]);
            bs.insert(b[i]);
            
            if (as == bs) {
                res++;
                as.clear();
                bs.clear();
            }
        }
        
        return res;
    }
};