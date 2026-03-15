class Solution {
public:
    int minCost(vector<int> &a, vector<int> &b) {
        unordered_set<int> values;
        unordered_map<int, int> countA, countB;
        for (int value : a) {
            values.insert(value);
            countA[value]++;
        }
        for (int value : b) {
            values.insert(value);
            countB[value]++;
        }
        
        int res = 0;
        for (int value : values) {
            if ((countA[value] + countB[value]) % 2)
                return -1;
            res += abs(countA[value] - countB[value]);
        }
        return res / 4;
    }
};