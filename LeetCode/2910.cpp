class Solution {
    int groupCount(int count, int groupSize) {
        int largeGroupCount = count / (groupSize + 1);
        int remainingCount = count % (groupSize + 1);

        if (!remainingCount)
            return largeGroupCount;
        else if (groupSize - remainingCount <= largeGroupCount)
            return largeGroupCount + 1;
        else
            return 1e9;
    }
    
    int groupCount(map<int, int> &counts, int groupSize) {
        int res = 0;
        for (auto &[count, factor] : counts) {
            int delta = groupCount(count, groupSize);
            if (delta == 1e9)
                return 1e9;
            res += delta * factor;
        }
        return res;
    }
    
public:
    int minGroupsForValidAssignment(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        map<int, int> counts;
        for (auto &[value, count] : count)
            counts[count]++;
        
        int res = 1e9;
        for (int groupSize = 1; groupSize <= counts.begin()->first; groupSize++)
            res = min(res, groupCount(counts, groupSize));
        return res;
    }
};