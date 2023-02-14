class Solution {
public:
    int maximumNumberOfOnes(int h, int w, int size, int maxOnes) {
        vector<vector<int>> count(size, vector<int>(size));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                count[y % size][x % size]++;
        
        vector<int> counts;
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                counts.push_back(count[y][x]);
        
        sort(counts.rbegin(), counts.rend());
        return accumulate(counts.begin(), counts.begin() + maxOnes, 0);
    }
};