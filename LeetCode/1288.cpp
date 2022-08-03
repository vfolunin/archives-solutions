class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<vector<int>> stack;
        for (vector<int> &segment : segments)
            if (stack.empty() || stack.back()[1] < segment[1])
                stack.push_back(segment);
        return stack.size();
    }
};