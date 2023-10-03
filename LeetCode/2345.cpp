class Solution {
    bool shades(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) <= a[1] - b[1];
    }

public:
    int visibleMountains(vector<vector<int>> &a) {
        sort(a.begin(), a.end());

        vector<pair<int, int>> stack;
        for (int i = 0; i < a.size(); i++) {
            bool hasDuplicate = !stack.empty() && a[stack.back().first] == a[i];

            while (!stack.empty() && shades(a[i], a[stack.back().first]))
                stack.pop_back();
            
            if (stack.empty() || !shades(a[stack.back().first], a[i]))
                stack.push_back({ i, hasDuplicate });
        }

        int res = 0;
        for (auto &[_, hasDuplicate] : stack)
            res += !hasDuplicate;
        return res;
    }
};