class Solution {
public:
    int deleteAndEarn(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> maxBonus(count.size());
        maxBonus[0] = count.begin()->first * count.begin()->second;
        
        auto it = next(count.begin());
        for (int i = 1; i < count.size(); i++, it++) {
            maxBonus[i] = it->first * it->second;
            if (prev(it)->first + 1 < it->first)
                maxBonus[i] += maxBonus[i - 1];
            else if (0 <= i - 2)
                maxBonus[i] += maxBonus[i - 2];
            maxBonus[i] = max(maxBonus[i], maxBonus[i - 1]);
        }
        
        return maxBonus.back();
    }
};