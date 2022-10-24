class Solution {
    int lisSize(vector<int> &a) {
        vector<int> lisLast;
        for (int i = 0; i < a.size(); i++) {
            int pos = upper_bound(lisLast.begin(), lisLast.end(), a[i]) - lisLast.begin();
            if (pos == lisLast.size())
                lisLast.emplace_back();
            lisLast[pos] = a[i];
        }
        return lisLast.size();
    }
    
public:
    int kIncreasing(vector<int> &a, int mod) {
        vector<vector<int>> parts(mod);
        for (int i = 0; i < a.size(); i++)
            parts[i % mod].push_back(a[i]);
        
        int res = 0;
        for (vector<int> &part : parts)
            res += part.size() - lisSize(part);
        return res;
    }
};