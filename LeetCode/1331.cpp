class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &a) {
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        for (int &value : a)
            value = lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin() + 1;
        return a;
    }
};