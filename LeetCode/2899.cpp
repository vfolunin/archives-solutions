class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int> &a) {
        vector<int> seen, res;
        int i = 0;
        
        for (int &value : a) {
            if (value == -1) {
                i--;
                res.push_back(0 <= i ? seen[i] : -1);
            } else {
                seen.push_back(value);
                i = seen.size();
            }
        }
        
        return res;
    }
};