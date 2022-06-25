class Solution {
    int commonPrefix(string &a, string &b) {
        int res = 0;
        while (res < a.size() && res < b.size() && a[res] == b[res])
            res++;
        return res;        
    }
    
    int commonSuffix(string &a, string &b) {
        int res = 0;
        while (res < a.size() && res < b.size() && a[a.size() - 1 - res] == b[b.size() - 1 - res])
            res++;
        return res;        
    }
    
public:
    int numOfPairs(vector<string> &s, string target) {
        vector<int> prefixCount(target.size() + 1);
        vector<int> suffixCount(target.size() + 1);
        int res = 0;
        
        for (string &s : s) {
            int l = commonPrefix(s, target);
            if (l == s.size())
                prefixCount[l]++;
            
            int r = commonSuffix(s, target);
            if (r == s.size())
                suffixCount[r]++;
            
            if (l == s.size() && r == s.size() && s.size() * 2 == target.size())
                res--;
        }
        
        for (int l = 1, r = target.size() - 1; l < target.size(); l++, r--)
            res += prefixCount[l] * suffixCount[r];
        
        return res;
    }
};