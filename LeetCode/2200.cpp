class Solution {
public:
    vector<int> findKDistantIndices(vector<int> &a, int targetValue, int k) {
        vector<int> targetPos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == targetValue)
                targetPos.push_back(i);
        
        vector<int> res;
        for (int ai = 0, ti = 0; ai < a.size() && ti < targetPos.size(); ai++) {
            if (ti + 1 < targetPos.size() && abs(ai - targetPos[ti]) > abs(ai - targetPos[ti + 1]))
                ti++;
            if (abs(ai - targetPos[ti]) <= k)
                res.push_back(ai);
        }
        return res;
    }
};