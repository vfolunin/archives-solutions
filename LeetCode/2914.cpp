class Solution {
public:
    int minChanges(string &s) {
        vector<int> cost(s.size() / 2);
        cost[0] = s[0] != s[1];
        for (int i = 1; i * 2 < s.size(); i++)
            cost[i] = cost[i - 1] + (s[i * 2] != s[i * 2 + 1]);
        return cost.back();
    }
};