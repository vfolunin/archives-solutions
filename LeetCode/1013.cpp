class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &a) {
        vector<int> p(a.size());
        partial_sum(a.begin(), a.end(), p.begin());
        
        if (p.back() % 3)
            return 0;
        int partSum = p.back() / 3;
        
        int l = 0;
        while (l < a.size() && p[l] != partSum)
            l++;
        if (l == a.size())
            return 0;
        
        int r = a.size() - 2;
        while (0 <= r && p[r] != p.back() - partSum)
            r--;
        return l < r;
    }
};