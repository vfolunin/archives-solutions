class Solution {
public:
    int maximumGroups(vector<int> &a) {
        int groupCount = 0, totalSize = 0;
        for (int groupSize = 1; totalSize + groupSize <= a.size(); groupSize++) {
            totalSize += groupSize;
            groupCount++;
        }
        return groupCount;
    }
};