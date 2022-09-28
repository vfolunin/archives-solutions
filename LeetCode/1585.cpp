class Solution {
public:
    bool isTransformable(string &a, string &b) {
        vector<vector<int>> pos(10);
        for (int i = 0; i < a.size(); i++)
            pos[a[i] - '0'].push_back(i);
        
        vector<int> index(10);
        
        for (char c : b) {
            if (index[c - '0'] == pos[c - '0'].size())
                return 0;
            
            for (auto i = 0; i < c - '0'; i++)
                if (index[i] < pos[i].size() && pos[i][index[i]] < pos[c - '0'][index[c - '0']])
                    return 0;
            
            index[c - '0']++;
        }
        
        return 1;
    }
};