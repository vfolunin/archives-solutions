class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string &s, int width) {
        unordered_map<string, int> count;
        int maxCount = 0;

        for (int from = 0; from < s.size(); from += width)
            maxCount = max(maxCount, ++count[s.substr(from, width)]);
        
        return s.size() / width - maxCount;
    }
};