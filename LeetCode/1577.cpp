class Solution {
public:
    int numTriplets(vector<int> &a, vector<int> &b) {
        unordered_map<long long, int> aCount;
        for (int value : a)
            aCount[1LL * value * value]++;
        
        unordered_map<long long, int> bCount;
        for (int value : b)
            bCount[1LL * value * value]++;
        
        int res = 0;
        
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (auto it = bCount.find(1LL * a[i] * a[j]); it != bCount.end())
                    res += it->second;
        
        for (int i = 0; i < b.size(); i++)
            for (int j = i + 1; j < b.size(); j++)
                if (auto it = aCount.find(1LL * b[i] * b[j]); it != aCount.end())
                    res += it->second;
        
        return res;
    }
};