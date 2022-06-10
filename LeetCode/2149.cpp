class Solution {
public:
    vector<int> rearrangeArray(vector<int> &a) {
        vector<int> res(a.size());
        
        for (int i = 0, j = 0, r = 0; r < res.size(); ) {
            while (a[i] < 0)
                i++;
            res[r++] = a[i++];
            
            while (a[j] > 0)
                j++;
            res[r++] = a[j++];
        }
        
        return res;
    }
};