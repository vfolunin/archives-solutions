class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int volume = capacity, res = 0;
        for (int i = 0; i < plants.size(); i++) {
            if (volume >= plants[i]) {
                res++;
                volume -= plants[i];
            } else {
                res += i * 2 + 1;
                volume = capacity - plants[i];
            }
        }
        return res;
    }
};