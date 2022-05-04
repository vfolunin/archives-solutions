class Solution {
public:
    vector<string> summaryRanges(vector<int> &a) {
        vector<string> res;
        
        for (int l = 0, r = 0; r < a.size(); l = r) {
            while (r < a.size() && (long long)a[l] + r - l == a[r])
                r++;
            
            string s = to_string(a[l]);
            if (l + 1 < r)
                s += "->" + to_string(a[r - 1]);
            res.push_back(s);
        }
        
        return res;
    }
};