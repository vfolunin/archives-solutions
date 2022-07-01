class Solution {
    unordered_map<int, vector<int>> pos;
    
public:
    Solution(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
    }
    
    int pick(int target) {
        vector<int> &p = pos[target];
        return p[rand() % p.size()];
    }
};