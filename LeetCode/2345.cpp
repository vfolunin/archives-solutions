class Solution {
    bool shades(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) <= a[1] - b[1];
    }

public:
    int visibleMountains(vector<vector<int>> &a) {
        sort(a.begin(), a.end());

        vector<int> stack;
        int duplicateCount = 0;

        for (int i = 0; i < a.size(); i++) {
            duplicateCount += !stack.empty() && a[stack.back()] == a[i];

            while (!stack.empty() && shades(a[i], a[stack.back()]))
                stack.pop_back();
            
            if (stack.empty() || !shades(a[stack.back()], a[i]))
                stack.push_back(i);
        }

        return max((int)stack.size() - duplicateCount, 0);
    }
};