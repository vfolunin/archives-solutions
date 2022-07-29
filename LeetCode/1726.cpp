class Solution {
public:
    int tupleSameProduct(vector<int> &a) {
        unordered_map<int, int> count;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                count[a[i] * a[j]]++;
        
        int res = 0;
        for (auto &[value, count] : count)
            res += count * (count - 1) * 4;
        return res;
    }
};