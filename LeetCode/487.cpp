class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &a) {
        vector<pair<int, int>> parts;
        for (int value : a) {
            if (parts.empty() || parts.back().first != value)
                parts.push_back({ value, 1 });
            else
                parts.back().second++;
        }

        if (parts.size() == 1)
            return parts[0].first ? parts[0].second : 1;
        
        int res = 0;
        for (int i = 0; i < parts.size(); i++) {
            if (parts[i].first) {
                res = max(res, parts[i].second + 1);
                if (i >= 2 && parts[i - 1].second == 1)
                    res = max(res, parts[i - 2].second + 1 + parts[i].second);
                if (i + 2 < parts.size() && parts[i + 1].second == 1)
                    res = max(res, parts[i].second + 1 + parts[i + 2].second);
            }
        }
        return res;
    }
};