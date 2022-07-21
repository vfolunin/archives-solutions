class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> res(p.size());
        for (int i = 0; i < res.size(); i++) {
            int value = p[i] - (i ? p[i - 1] : 0);
            
            int smallerSum = i ? p[i - 1] : 0;
            int smallerCount = i;
            res[i] += value * smallerCount - smallerSum;
            
            int biggerSum = p.back() - p[i];
            int biggerCount = p.size() - 1 - i;
            res[i] += biggerSum - value * biggerCount;
        }
        return res;
    }
};