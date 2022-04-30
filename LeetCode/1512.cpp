class Solution {
public:
    int numIdenticalPairs(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int l = 0, r = 0; r < a.size(); l = r) {
            r = l;
            while (r < a.size() && a[l] == a[r])
                r++;
            
            int count = r - l;
            res += count * (count - 1) / 2;
        }
        
        return res;
    }
};