class Solution {
public:
    int minimumSum(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> minPos;
        for (int i = 0; i < a.size(); i++)
            if (!minPos.contains(a[i]))
                minPos[a[i]] = i;
        
        int res = 1e9;
        for (int i = 0; i < b.size(); i++)
            if (minPos.contains(b[i]))
                res = min(res, minPos[b[i]] + i);
        return res != 1e9 ? res : -1;
    }
};