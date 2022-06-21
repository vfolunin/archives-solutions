class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        multiset<int> maxDeltas;
        int minDeltasSum = 0;
        
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i - 1] >= heights[i])
                continue;
            
            maxDeltas.insert(heights[i] - heights[i - 1]);
            if (maxDeltas.size() > ladders) {
                minDeltasSum += *maxDeltas.begin();
                maxDeltas.erase(maxDeltas.begin());
                
                if (minDeltasSum > bricks)
                    return i - 1;
            }
        }
        
        return heights.size() - 1;
    }
};