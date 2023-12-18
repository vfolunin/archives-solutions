class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &a) {
        vector<int> count(a.size() * a.size());
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a.size(); x++)
                count[a[y][x] - 1]++;
        
        int value2 = find(count.begin(), count.end(), 2) - count.begin() + 1;
        int value0 = find(count.begin(), count.end(), 0) - count.begin() + 1;
        return { value2, value0 };
    }
};