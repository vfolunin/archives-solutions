class Solution {
public:
    int countTriplets(vector<int> &a) {
        vector<int> count(1 << 16);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a.size(); j++)
                count[a[i] & a[j]]++;
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int mask = 0; mask < (1 << 16); mask++)
                if (!(a[i] & mask))
                    res += count[mask];
        return res;
    }
};