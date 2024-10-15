class Solution {
public:
    int minConnectedGroups(vector<vector<int>> &segments, int limit) {
        sort(segments.begin(), segments.end());
        vector<pair<int, int>> mergedSegments;
        for (auto &segment : segments) {
            if (mergedSegments.empty() || mergedSegments.back().second < segment[0])
                mergedSegments.push_back({ segment[0], segment[1] });
            else
                mergedSegments.back().second = max(mergedSegments.back().second, segment[1]);
        }

        int res = mergedSegments.size();
        for (int l = 0, r = 0; r < mergedSegments.size(); r++) {
            while (mergedSegments[l].second + limit < mergedSegments[r].first)
                l++;
            res = min(res, (int)mergedSegments.size() - (r - l));
        }
        return res;
    }
};