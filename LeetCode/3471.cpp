class Solution {
public:
    int largestInteger(vector<int> &a, int width) {
        vector<vector<int>> from(51);
        for (int l = 0, r = width - 1; r < a.size(); l++, r++)
            for (int i = l; i <= r; i++)
                from[a[i]].push_back(l);
        
        for (int value = from.size() - 1; value >= 0; value--)
            if (!from[value].empty() && from[value].front() == from[value].back())
                return value;
        return -1;
    }
};