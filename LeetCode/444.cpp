class Solution {
public:
    bool sequenceReconstruction(vector<int> &a, vector<vector<int>> &subs) {
        vector<int> pos(a.size() + 1);
        for (int i = 0; i < a.size(); i++)
            pos[a[i]] = i;

        vector<int> fixed(a.size() + 1);
        
        for (vector<int> &sub : subs) {
            for (int i = 0; i + 1 < sub.size(); i++) {
                if (pos[sub[i]] > pos[sub[i + 1]])
                    return 0;
                
                if (!fixed[sub[i]] && pos[sub[i]] + 1 == pos[sub[i + 1]])
                    fixed[sub[i]] = 1;
            }
        }
        
        return count(fixed.begin() + 1, fixed.end(), 1) == a.size() - 1;
    }
};
