class Solution {
public:
    int boxDelivering(vector<vector<int>> &boxes, int portCount, int boxLimit, int weightLimit) {
        vector<int> tripCount(boxes.size() + 1);

        int weight = 0, trips = 1;
        for (int l = 0, r = 0; r < boxes.size(); r++) {
            weight += boxes[r][1];
            trips += !r || boxes[r - 1][0] != boxes[r][0];
            
            while (r - l + 1 > boxLimit || weight > weightLimit || l < r && tripCount[l] == tripCount[l + 1]) {
                weight -= boxes[l][1];
                trips -= boxes[l][0] != boxes[l + 1][0];
                l++;
            }
            
            tripCount[r + 1] = tripCount[l] + trips;
        }
        
        return tripCount.back();
    }
};
