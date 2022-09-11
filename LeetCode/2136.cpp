class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        vector<pair<int, int>> pairs(plantTime.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { plantTime[i], growTime[i] };
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        
        int time = 0, res = 0;
        for (auto &[plant, grow] : pairs) {
            res = max(res, time + plant + grow);
            time += plant;
        }
        return res;
    }
};