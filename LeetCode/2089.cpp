class Solution {
public:
    vector<int> targetIndices(vector<int> &a, int target) {
        int lessCount = 0, equalCount = 0;
        for (int value : a) {
            if (value < target)
                lessCount++;
            else if (value == target)
                equalCount++;
        }
        
        vector<int> res;
        for (int i = lessCount; i < lessCount + equalCount; i++)
            res.push_back(i);
        return res;
    }
};