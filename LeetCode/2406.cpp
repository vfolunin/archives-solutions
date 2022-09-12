class Solution {
public:
    int minGroups(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end());
        multiset<int> last;
        for (vector<int> &segment : segments) {
            if (!last.empty() && *last.begin() < segment[0])
                last.erase(last.begin());
            last.insert(segment[1]);
        }
        return last.size();
    }
};