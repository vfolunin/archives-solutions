class Solution {
    vector<int> rec(int mask, vector<int> &skillMask, vector<vector<int>> &memo) {
        if (!mask)
            return {};
        
        vector<int> &res = memo[mask];
        if (!res.empty())
            return res;
        
        for (int i = 0; i < skillMask.size(); i++) {
            if (mask & skillMask[i]) {
                vector<int> childRes = rec(mask & ~skillMask[i], skillMask, memo);
                if (res.empty() || res.size() > childRes.size() + 1) {
                    childRes.push_back(i);
                    res = childRes;
                }
            }
        }
        return res;
    }
    
public:
    vector<int> smallestSufficientTeam(vector<string> &skills, vector<vector<string>> &people) {
        vector<int> skillMask(people.size());
        for (int i = 0; i < people.size(); i++)
            for (int j = 0; j < skills.size(); j++)
                if (find(people[i].begin(), people[i].end(), skills[j]) != people[i].end())
                    skillMask[i] |= 1 << j;

        vector<vector<int>> memo(1 << skills.size());
        
        return rec((1 << skills.size()) - 1, skillMask, memo);
    }
};