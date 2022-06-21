class Solution {
public:
    int countTriplets(vector<int> &p) {
        for (int i = 1; i < p.size(); i++)
            p[i] ^= p[i - 1];
        
        int res = 0;
        for (int len = 2; len <= p.size(); len++)
            for (int l = 0, r = len - 1; r < p.size(); l++, r++)
                if (p[r] == (l ? p[l - 1] : 0))
                    res += len - 1;
        
        return res;
    }
};