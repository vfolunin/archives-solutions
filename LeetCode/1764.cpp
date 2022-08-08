class Solution {    
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &a) {
        auto from = a.begin();
        for (vector<int> &group : groups) {
            if (auto it = search(from, a.end(), group.begin(), group.end()); it != a.end())
                from = it + group.size();
            else
                return 0;
        }
        return 1;
    }
};