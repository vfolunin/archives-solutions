class Solution {
public:
    int minBuildTime(vector<int> &blockTime, int splitTime) {
        multiset<int> times(blockTime.begin(), blockTime.end());

        while (times.size() > 1) {
            times.erase(times.begin());
            int time = *times.begin();
            times.erase(times.begin());
            times.insert(splitTime + time);
        }
        
        return *times.begin();
    }
};