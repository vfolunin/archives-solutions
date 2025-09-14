class Solution {
public:
    int minArrivalsToDiscard(vector<int> &a, int windowSize, int limit) {
        unordered_map<int, int> count;
        vector<int> skipped(a.size());

        for (int i = 0; i < a.size(); i++) {
            if (i >= windowSize && !skipped[i - windowSize])
                count[a[i - windowSize]]--;
            
            if (count[a[i]] < limit)
                count[a[i]]++;
            else
                skipped[i] = 1;
        }

        return accumulate(skipped.begin(), skipped.end(), 0);
    }
};