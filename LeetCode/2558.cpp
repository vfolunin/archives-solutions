class Solution {
public:
    long long pickGifts(vector<int> &a, int n) {
        multiset<int> values(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int value = *prev(values.end());
            values.erase(prev(values.end()));
            values.insert(sqrt(value));
        }
        
        long long res = 0;
        for (int value : values)
            res += value;
        return res;
    }
};