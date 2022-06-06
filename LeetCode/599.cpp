class Solution {
public:
    vector<string> findRestaurant(vector<string> &a, vector<string> &b) {
        unordered_map<string, int> posInA;
        for (int i = 0; i < a.size(); i++)
            posInA[a[i]] = i;
        
        int resSum = 1e9;
        vector<string> res;
        
        for (int i = 0; i < b.size(); i++) {
            if (posInA.count(b[i])) {
                int sum = posInA[b[i]] + i;
                if (resSum > sum) {
                    resSum = sum;
                    res = { b[i] };
                } else if (resSum == sum) {
                    res.push_back(b[i]);
                }
            }
        }
        
        return res;
    }
};