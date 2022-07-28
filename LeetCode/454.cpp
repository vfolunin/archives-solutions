class Solution {
public:
    int fourSumCount(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
        unordered_map<int, int> abCount;
        for (int aValue : a)
            for (int bValue : b)
                abCount[aValue + bValue]++;
        
        int res = 0;
        for (int cValue : c)
            for (int dValue : d)
                if (auto it = abCount.find(-cValue - dValue); it != abCount.end())
                    res += it->second;
        return res;
    }
};