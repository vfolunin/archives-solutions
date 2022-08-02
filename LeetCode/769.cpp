class Solution {
public:
    int maxChunksToSorted(vector<int> &a) {
        unordered_set<int> aSet, iSet;
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            aSet.insert(a[i]);
            iSet.insert(i);
            if (aSet == iSet) {
                res++;
                aSet.clear();
                iSet.clear();
            }
        }
        
        return res;
    }
};