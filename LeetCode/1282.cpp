class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<pair<int, int>> groupSizeAndIndex;
        for (int i = 0; i < groupSizes.size(); i++)
            groupSizeAndIndex.push_back({ groupSizes[i], i });
        
        sort(groupSizeAndIndex.begin(), groupSizeAndIndex.end());
        
        vector<vector<int>> groups;
        for (int i = 0; i < groupSizeAndIndex.size(); i += groupSizeAndIndex[i].first) {
            groups.emplace_back();
            for (int j = 0; j < groupSizeAndIndex[i].first; j++)
                groups.back().push_back(groupSizeAndIndex[i + j].second);
        }
        return groups;
    }
};