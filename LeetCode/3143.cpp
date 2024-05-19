class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string &s) {
        map<int, vector<int>> count;
        for (int i = 0; i < points.size(); i++) {
            int size = max(abs(points[i][0]), abs(points[i][1]));
            count[size].resize(26);
            count[size][s[i] - 'a']++;
        }

        vector<int> totalCount(26);
        for (auto &[size, count] : count) {
            vector<int> nextTotalCount = totalCount;
            for (int i = 0; i < totalCount.size(); i++)
                nextTotalCount[i] += count[i];
            if (*max_element(nextTotalCount.begin(), nextTotalCount.end()) > 1)
                break;
            totalCount.swap(nextTotalCount);
        }

        return accumulate(totalCount.begin(), totalCount.end(), 0);
    }
};